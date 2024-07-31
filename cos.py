import tkinter as tk
from tkinter import ttk, filedialog, Text, messagebox
import json

FILETYPES = [("JSON Files", "*.json"), ("All Files", "*.*")]


class Application(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Aplikacja")
        self.geometry("800x600")

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
        self.text.bind("<<Modified>>", self.on_text_modified)
        paned_window.add(self.text)

        self.update_idletasks()
        paned_window.sashpos(0, 350)

        self.current_item = None

        self.text.edit_modified(False)

        self.valueType_error_displayed = False

    def on_text_modified(self, event):
        self.text.edit_modified(True)
        # self.save_current_data()

    def open_json_file(self):
        file_path = filedialog.askopenfilename(filetypes=FILETYPES)
        if file_path:
            try:
                with open(file_path, "r", encoding="utf-8") as file:
                    data = json.load(file)
                    # self.tree.delete(*self.tree.get_children())
                    self.populate_tree_view(data)
                messagebox.showinfo(title="Status", message="Opening file OK")
                # self.text.edit_modified(False)
            except json.JSONDecodeError:
                messagebox.showerror(
                    title="Error",
                    message="Error opening file. Check if the file format is correct.",
                )

    def export_json_file(self):
        self.save_current_data()

        file_path = filedialog.asksaveasfilename(
            defaultextension=".json", filetypes=FILETYPES
        )
        if file_path:
            data = self.tree_to_dict()
            try:
                with open(file_path, "w", encoding="utf-8") as file:
                    json.dump(data, file, indent=2)
                messagebox.showinfo(
                    title="Status", message=f"Export saved: {file_path}"
                )
                self.text.edit_modified(False)
            except json.JSONDecodeError:
                messagebox.showerror(title="Error", message="Exporting failed.")

    def populate_tree_view(self, data, parent=""):
        textId = data.get("textId", "")
        if textId.startswith("IDT_"):
            textId = textId[4:]
        item_id = self.tree.insert(parent, "end", text=textId, open=False)
        self.tree.set(item_id, "full_data", json.dumps(data))

        if "SUBMENU" in data:
            for submenu in data["SUBMENU"]:
                self.populate_tree_view(submenu, item_id)

    def save_current_data(self):
        if not self.current_item:
            return

        new_data = self.text.get(1.0, tk.END).strip()
        if not new_data:
            return  # No data to update

        try:
            data_dict = json.loads(new_data)
        except json.JSONDecodeError:
            messagebox.showerror(
                title="Error", message="Invalid JSON data. Please correct it."
            )
            return

        full_data = self.tree.set(self.current_item, "full_data")
        if not full_data:
            return

        original_data = json.loads(full_data)
        self.preserve_value_type(original_data, data_dict)

        # Update original data with new data
        original_data.update(data_dict)

        # Update the textId in the Treeview item
        textId = original_data.get("textId", "").removeprefix("IDT_")
        self.tree.item(self.current_item, text=textId)

        # Save the updated full data back to the tree
        self.tree.set(self.current_item, "full_data", json.dumps(original_data))
        self.text.edit_modified(False)

    def preserve_value_type(self, original_data, data_dict):
        if (
            "valueType" in original_data
            and data_dict.get("valueType") != original_data["valueType"]
        ):
            if not self.valueType_error_displayed:
                messagebox.showerror(title="Error", message="Don't change 'valueType'")
                self.valueType_error_displayed = True
            data_dict["valueType"] = original_data["valueType"]
        else:
            self.valueType_error_displayed = False  # Reset flag if no error

    def ask_before_exit(self):
        if self.text.edit_modified():
            ask = messagebox.askyesnocancel(
                title="Quit", message="Do you want save before exit?"
            )

            if ask is True:
                self.export_json_file()
                self.destroy()
            elif ask is False:
                self.destroy()
            else:
                return
        else:
            self.destroy()

    def display_selected_name(self, event):
        self.save_current_data()  # Save changes before displaying new data

        selected_item = self.tree.selection()
        if not selected_item:
            return

        self.current_item = selected_item[0]  # Update current item
        full_data = self.tree.set(self.current_item, "full_data")

        if full_data:
            data_dict = json.loads(full_data)
            filtered_data = self.filter_data(data_dict)

            self.update_text_widget(filtered_data)
        else:
            self.show_no_data_error()

    def filter_data(self, data_dict):
        if data_dict.get("type") == "TT_WARTOSC":
            return {
                key: data_dict[key]
                for key in ("defVal", "minVal", "maxVal", "valueType")
                if key in data_dict
            }
        elif "SUBMENU" in data_dict:
            return {
                key: value
                for key, value in data_dict.items()
                if key in ["name", "textId", "iconId", "ID", "type", "onlyOnPanel"]
            }
        return data_dict

    def update_text_widget(self, filtered_data):
        self.text.delete(1.0, tk.END)
        self.text.insert(tk.END, json.dumps(filtered_data, indent=2))
        self.text.edit_modified(False)

    def show_no_data_error(self):
        messagebox.showerror(
            title="Error",
            message="No data found for the selected item. Please check the data.",
        )

    def tree_to_dict(self, item=""):
        children = self.tree.get_children(item)

        if not item:
            if children:
                return self.tree_to_dict(children[0])
            else:
                return {}

        if not children:
            full_data = self.tree.set(item, "full_data")
            if full_data:
                return json.loads(full_data)
            else:
                return {}

        data = self.tree.set(item, "full_data")
        if data:
            data_dict = json.loads(data)
            data_dict["SUBMENU"] = [self.tree_to_dict(child) for child in children]
            return data_dict
        else:
            return {"SUBMENU": [self.tree_to_dict(child) for child in children]}


def main():
    app = Application()
    app.protocol("WM_DELETE_WINDOW", app.ask_before_exit)
    app.mainloop()


if __name__ == "__main__":
    main()
