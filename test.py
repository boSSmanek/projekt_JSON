import tkinter as tk
from tkinter import ttk, filedialog, Text, messagebox
import json
import csv
from header_to_dict import open_CSV

FILETYPES = [("JSON Files", "*.json"), ("All Files", "*.*")]


class Application(tk.Tk):
    def __init__(self):
        super().__init__()

        self.title("Aplikacja")
        self.geometry("800x600")

        self.powers = []
        self.powers_window = None
        self.load_powers_from_file()
        
        # Buttons to open and export JSON file
        button_frame = ttk.Frame(self)
        button_frame.pack(side=tk.TOP, fill=tk.X)

        open_button = ttk.Button(
            button_frame, text="Open JSON File", command=self.select_or_add_power
        )
        open_button.pack(side=tk.LEFT, padx=5, pady=5)

        export_button = ttk.Button(
            button_frame, text="Export JSON", command=self.export_json_file
        )
        export_button.pack(side=tk.LEFT, padx=5, pady=5)

        export_button_to_csv = ttk.Button(
            button_frame, text="Export CSV", command=self.export_csv_file
        )
        export_button_to_csv.pack(side=tk.LEFT, padx=5, pady=5)

        """ add_power_button = ttk.Button(
            button_frame, text="Add power", command=self.add_power
        )
        add_power_button.pack(side=tk.LEFT, padx=5, pady=5) """

        """ show_powers_button = ttk.Button(
            button_frame, text="Show powers", command=self.show_powers
        )
        show_powers_button.pack(side=tk.LEFT, padx=5, pady=5) """


        # PanedWindow
        paned_window = ttk.PanedWindow(self, orient=tk.HORIZONTAL)
        paned_window.pack(fill=tk.BOTH, expand=1)

        # Left frame for Treeview and Scrollbar
        tree_frame = ttk.Frame(paned_window)
        paned_window.add(tree_frame, weight=1)

        # Treeview
        self.tree = ttk.Treeview(tree_frame, columns=("full_data"), show="tree")
        self.tree.bind("<<TreeviewSelect>>", self.display_selected_name)
        self.tree.column("full_data", width=0, stretch=tk.NO)
        self.tree.heading("#0", text="Name")
        self.tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        # Scrollbar
        scroll_bar = ttk.Scrollbar(
            tree_frame, orient="vertical", command=self.tree.yview
        )
        scroll_bar.pack(side="right", fill="y")
        self.tree.configure(yscrollcommand=scroll_bar.set)

        # Right frame for Text widget
        text_frame = ttk.Frame(paned_window)
        paned_window.add(text_frame, weight=3)

        # Text widget for JSON data
        self.text = Text(text_frame, wrap=tk.WORD)
        self.text.pack(fill=tk.BOTH, expand=True)
        self.text.insert(tk.END, "Select a file from options menu")
        self.text.bind("<<Modified>>", self.on_text_modified)

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
                    self.powers = data.get("powers", [])
                    # self.tree.delete(*self.tree.get_children())
                    self.populate_tree_view(data)    
                #self.select_or_add_power()
                messagebox.showinfo(title="Status", message="Opening file OK")
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

    def add_power(self, listbox=None):
        add_power_window = tk.Toplevel(self)
        add_power_window.title("Add Power")

        label = tk.Label(add_power_window, text="Enter new power:")
        label.pack(padx=10, pady=10)

        entry = tk.Entry(add_power_window)
        entry.pack(padx=10, pady=10)

        def add_power_to_list(event=None):
            new_power = entry.get()
            if new_power and new_power not in self.powers:
                self.powers.append(new_power)
                if listbox:  # Jeśli lista została przekazana
                    listbox.insert(tk.END, new_power)
                self.save_powers_to_file()
                messagebox.showinfo("Success", f"Power '{new_power}' added!")
                entry.delete(0, tk.END)
                add_power_window.destroy()
            else:
                messagebox.showerror("Error", "Power already exists or is invalid.")
                entry.delete(0, tk.END)

        # Bind klawisza Enter do dodawania mocy
        entry.bind("<Return>", add_power_to_list)

        add_button = tk.Button(add_power_window, text="Add", command=add_power_to_list)
        add_button.pack(pady=10)

    def select_or_add_power(self):
        self.load_powers_from_file()

        power_window = tk.Toplevel(self)
        power_window.title("Select or Add Power")

        label = tk.Label(power_window, text="Select a power or add a new one:")
        label.pack(padx=10, pady=10)

        listbox = tk.Listbox(power_window)
        listbox.pack(fill=tk.BOTH, expand=True)

        for power in self.powers:
            listbox.insert(tk.END, power)

        def on_select():
            selection = listbox.curselection()
            if selection:
                selected_power = listbox.get(selection[0])
                messagebox.showinfo("Selected Power", f"You selected: {selected_power}")
                power_window.destroy()  # Zamknięcie okna po wyborze
                self.open_json_file()

                # Tutaj można dodać dodatkowe akcje po wyborze mocy
            else:
                messagebox.showwarning("Selection Error", "No power selected")

        def add_new_power():
            self.add_power(listbox)

        select_button = tk.Button(power_window, text="Select Power", command=on_select)
        select_button.pack(padx=5, pady=5)

        add_button = tk.Button(power_window, text="Add New Power", command=add_new_power)
        add_button.pack(padx=5, pady=5)

    def load_powers_from_file(self):
        try:
            with open("powers.json", "r", encoding="utf-8") as file:
                data = json.load(file)
                self.powers = data.get("powers", [])
        except FileNotFoundError:
            self.powers = []
        except json.JSONDecodeError:
            messagebox.showerror("Error", "Error reading powers file. Please check the file format.")
        except Exception as e:
            messagebox.showerror("Error", f"An error occurred: {e}")

    def save_powers_to_file(self):
        try:
            with open("powers.json", "w", encoding="utf-8") as file:
                json.dump({"powers": self.powers}, file, ensure_ascii=False, indent=4)
        except Exception as e:
            messagebox.showerror("Error", f"Error saving powers to file: {e}")




    def export_csv_file(self):
        self.save_current_data()

        enum_dict = open_CSV("ID.h")

        file_path = filedialog.asksaveasfilename(
            defaultextension=".csv",
            filetypes=[("CSV Files", "*.csv"), ("All Files", "*.*")],
        )
        if not file_path:
            return

        with open(file=file_path, mode="w", newline="", encoding="utf-8") as file:
            writer = csv.writer(file, delimiter=";")

            writer.writerow(
                [
                    "namespace",
                    "instance_index",
                    "id",
                    "value_def",
                    "value_min",
                    "value_max",
                ]
            )

            def extract_and_write(item, namespace="", instance_index=""):
                children = self.tree.get_children(item)
                if not children:
                    full_data = self.tree.set(item, "full_data")
                    if full_data:
                        data = json.loads(full_data)

                        numeric_id = data.get('ID', '')
                        id_name = next((name for name, number in enum_dict.items() if number == numeric_id), numeric_id)
                        if data.get("type") == "TT_WARTOSC":
                            writer.writerow(
                                [
                                    namespace,
                                    instance_index,
                                    id_name,
                                    data.get("defVal", ""),
                                    data.get("minVal", ""),
                                    data.get("maxVal", ""),
                                ]
                            )
                        elif data.get("type") == "TT_CHECK_BOX":
                            writer.writerow(
                                [
                                    namespace,
                                    instance_index,
                                    id_name,
                                    data.get("defVal", ""),
                                    0,
                                    1,
                                ]
                            )
                else:
                    for child in children:
                        extract_and_write(child, namespace, instance_index)

            for root_item in self.tree.get_children():
                extract_and_write(root_item)

        messagebox.showinfo(
            title="Export Complete", message=f"CSV file exported: {file_path}"
        )

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
