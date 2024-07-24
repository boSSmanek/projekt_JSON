import tkinter as tk
from tkinter import ttk, filedialog, Text, Menu
import json

FILETYPES = [("JSON Files", "*.json"), ("All Files", "*.*")]

class Application(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Aplikacja")
        self.geometry("800x600")

        # Menubar
        self.menu_bar = Menu(self)
        self.config(menu=self.menu_bar)

        self.options_menu = Menu(self.menu_bar, tearoff=1)
        self.menu_bar.add_cascade(label="Options", menu=self.options_menu)
        self.options_menu.add_command(label="Open JSON File", command=self.open_json_file)
        self.options_menu.add_command(label="Export JSON", command=self.export_json_file)
        self.options_menu.add_command(label="Exit", command=self.quit)

        # Main frame
        main_frame = ttk.Frame(self)
        main_frame.pack(fill=tk.BOTH, expand=1)

        # Horizontal paned window
        paned_window = ttk.PanedWindow(main_frame, orient=tk.HORIZONTAL)
        paned_window.pack(fill=tk.BOTH, expand=1)

        # Treeview
        self.tree = ttk.Treeview(paned_window, columns=("full_data"), show="tree")
        self.tree.bind("<<TreeviewSelect>>", self.display_selected_name)
        self.tree.column("full_data", width=0, stretch=tk.NO)
        self.tree.heading("#0", text="Name")
        paned_window.add(self.tree)
        
        # Text widget for displaying JSON data
        self.text = Text(paned_window, wrap=tk.WORD)
        self.text.insert(tk.END, "Select a file from options menu")
        paned_window.add(self.text)

        paned_window.after(100, lambda: paned_window.sashpos(0, 300))
        
        # Button to open JSON file
        #open_button = tk.Button(self, text="Open JSON File", command=self.open_json_file, bg='#9e9190')
        #open_button.pack(side=tk.BOTTOM, fill=tk.X)


    def open_json_file(self):
        file_path = filedialog.askopenfilename(filetypes=FILETYPES)
        if file_path:
            with open(file_path, 'r', encoding="utf-8") as file:
                data = json.load(file)
                self.populate_tree_view(data)


    def export_json_file(self):
        file_path = filedialog.asksaveasfilename(defaultextension=".json", 
                                                 filetypes=FILETYPES)

        if file_path:
            selected_item = self.tree.selection()[0]
            full_data = self.tree.set(selected_item, "full_data")
            data_dict = json.loads(full_data)
            with open(file_path, 'w', encoding="utf-8") as file:
                json.dump(data_dict, file, indent=4)


    def populate_tree_view(self, data, parent=""):
        textId = data["textId"]
        if textId.startswith("IDT_"):
            textId = textId[4:]
        item_id = self.tree.insert(parent, "end", text=textId, open=False)
        self.tree.set(item_id, "full_data", json.dumps(data))
        
        if "SUBMENU" in data:
            for submenu in data["SUBMENU"]:
                self.populate_tree_view(submenu, item_id)


    def display_selected_name(self, event):
        selected_item = self.tree.selection()[0]
        full_data = self.tree.set(selected_item, "full_data")
        data_dict = json.loads(full_data)

        if "SUBMENU" in data_dict:
            # Display main item fields only
            main_fields = {k: v for k, v in data_dict.items() if k in 
                           ["name", "textId", "iconId", "ID", "type", "onlyOnPanel"]}
            self.text.delete(1.0, tk.END)
            self.text.insert(tk.END, json.dumps(main_fields, indent=4))
        elif data_dict["type"] == "TT_WARTOSC":
            # Display value for type "TT_WARTOSC"
            input_value = {k: v for k, v in data_dict.items() if k in 
                           ["defVal", "minVal", "maxVal", "valueType"]}
            self.text.delete(1.0, tk.END)
            self.text.insert(tk.END, json.dumps(input_value, indent=4))
        else:
            # Display full data for SUBMENU items
            self.text.delete(1.0, tk.END)
            self.text.insert(tk.END, json.dumps(data_dict, indent=4))


def main():
    app = Application()
    app.mainloop()

if __name__ == "__main__":
    main()
