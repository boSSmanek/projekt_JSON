import tkinter as tk
from tkinter import ttk, filedialog, Text
import json

class Application(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Aplikacja")
        self.geometry("800x600")

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
        self.text.insert(tk.END, "Select a file")
        paned_window.add(self.text)

        paned_window.after(100, lambda: paned_window.sashpos(0, 300))
        
        # Button to open JSON file
        open_button = tk.Button(self, text="Open JSON File", command=self.open_json_file, bg='#9e9190')
        open_button.pack(side=tk.BOTTOM, fill=tk.X)


    def open_json_file(self):
        file_path = filedialog.askopenfilename(filetypes=[("JSON Files", "*.json"), ("All Files", "*.*")])
        if file_path:
            with open(file_path, 'r', encoding='utf-8') as file:
                data = json.load(file)
                self.populate_tree_view(data)


    def populate_tree_view(self, data, parent=""):
        textId = data["textId"]
        if textId.startswith("IDT_"):
            textId = textId[4:]
        item_id = self.tree.insert(parent, "end", text=textId, open=False)
        self.tree.set(item_id, "full_data", json.dumps(data))
        
        if 'SUBMENU' in data:
            for submenu in data['SUBMENU']:
                self.populate_tree_view(submenu, item_id)


    def display_selected_name(self, event):
        selected_item = self.tree.selection()[0]
        full_data = self.tree.set(selected_item, "full_data")
        data_dict = json.loads(full_data)

        if 'SUBMENU' in data_dict:
            # Display main item fields only
            main_fields = {k: v for k, v in data_dict.items() if k in 
                           ['name', 'textId', 'iconId', 'ID', 'type', 'onlyOnPanel']}
            self.text.delete(1.0, tk.END)
            self.text.insert(tk.END, json.dumps(main_fields, indent=4))
        else:
            # Display full data for SUBMENU items
            self.text.delete(1.0, tk.END)
            self.text.insert(tk.END, json.dumps(data_dict, indent=4))

            