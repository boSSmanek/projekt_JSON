import tkinter as tk
from tkinter import ttk, filedialog, Text, messagebox
import json

FILETYPES = [("JSON Files", "*.json"), ("All Files", "*.*")]


class Application(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Aplikacja")
        self.geometry("800x600")

        # Menubar
        """ self.menu_bar = Menu(self)
        self.config(menu=self.menu_bar)

        self.options_menu = Menu(self.menu_bar, tearoff=1)
        self.menu_bar.add_cascade(label="Options", menu=self.options_menu)
        self.options_menu.add_command(
            label="Open JSON File", command=self.open_json_file
        )
        self.options_menu.add_command(
            label="Export JSON", command=self.export_json_file
        )
        self.options_menu.add_command(label="Exit", command=self.quit) """

        # Buttons to open JSON file and export JSON
        button_frame = ttk.Frame(self)
        button_frame.pack(side=tk.TOP, fill=tk.X)

        open_button = ttk.Button(
            button_frame, text="Open JSON File", command=self.open_json_file
        )
        open_button.pack(side=tk.LEFT, padx=5, pady=5)

        export_button = ttk.Button(
            button_frame, text="Export JSON", command=self.export_json_file
        )
        export_button.pack(side=tk.LEFT, padx=5, pady=5)

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

        self.current_item = None

    def open_json_file(self):
        file_path = filedialog.askopenfilename(filetypes=FILETYPES)
        if file_path:
            try:
                with open(file_path, "r", encoding="utf-8") as file:
                    data = json.load(file)
                    self.populate_tree_view(data)
                messagebox.showinfo(title="Status", message="Opening file OK")
            except Exception as e:
                messagebox.showerror(
                    title="Status", message=f"Error opening file: {str(e)}"
                )

    """ def export_json_file(self):
        file_path = filedialog.asksaveasfilename(
            defaultextension=".json", filetypes=FILETYPES
        )

        if file_path:
            selected_item = self.tree.selection()[0]
            full_data = self.tree.set(selected_item, "full_data")
            data_dict = json.loads(full_data)
            try:
                with open(file_path, "w", encoding="utf-8") as file:
                    json.dump(data_dict, file, indent=4)
                messagebox.showinfo(
                    title="Status", message=f"Export saved: {file_path}"
                )
            except Exception as e:
                messagebox.showerror(
                    title="Status", message=f"Error exporting to file: {str(e)}"
                ) """

    def export_json_file(self):
        file_path = filedialog.asksaveasfilename(
            defaultextension=".json", filetypes=FILETYPES
        )
        if file_path:
            data = self.tree_to_dict()
            try:
                with open(file_path, "w", encoding="utf-8") as file:
                    json.dump(data, file, indent=2)
                messagebox.showinfo("Status", message=f"Export saved: {file_path}")
            except Exception as e:
                messagebox.showinfo(
                    "Status", message=f"Error exporting to file: {str(e)}"
                )

    def populate_tree_view(self, data, parent=""):
        textId = data["textId"]
        if textId.startswith("IDT_"):
            textId = textId[4:]
        item_id = self.tree.insert(parent, "end", text=textId, open=False)
        self.tree.set(item_id, "full_data", json.dumps(data))

        if "SUBMENU" in data:
            for submenu in data["SUBMENU"]:
                self.populate_tree_view(submenu, item_id)

    def saved_current_data(self):
        if self.current_item:
            new_data = self.text.get(1.0, tk.END)
            try:
                data_dict = json.loads(new_data)
                self.tree.set(self.current_item, "full_data", json.dumps(data_dict))
            except json.JSONDecodeError:
                messagebox.showerror("Error", "Invalid data. Please correct it.")

    def display_selected_name(self, event):
        self.saved_current_data()

        selected_item = self.tree.selection()[0]
        # self.current_item = selected_item
        full_data = self.tree.set(selected_item, "full_data")
        data_dict = json.loads(full_data)

        if "SUBMENU" in data_dict:
            # Display main item fields only
            main_fields = {
                k: v
                for k, v in data_dict.items()
                if k in ["name", "textId", "iconId", "ID", "type", "onlyOnPanel"]
            }
            self.text.delete(1.0, tk.END)
            self.text.insert(tk.END, json.dumps(main_fields, indent=4))
        elif data_dict["type"] == "TT_WARTOSC":
            # Display value for type "TT_WARTOSC"
            input_value = {
                k: v
                for k, v in data_dict.items()
                if k in ["defVal", "minVal", "maxVal", "valueType"]
            }
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
