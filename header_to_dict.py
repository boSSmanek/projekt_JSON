import re


def extract_enum_values(header_file):
    enum_start_pattern = r"enum\s+Global\s*{"
    enum_end_pattern = r"};"

    start_match = re.search(enum_start_pattern, header_file)
    if not start_match:
        return {}

    end_match = re.search(enum_end_pattern, header_file[start_match.end() :])
    if not end_match:
        return {}

    enum_content = header_file[
        start_match.end() : start_match.end() + end_match.start()
    ]

    enum_value_pattern = r"(\w+)\s*=\s*(\d+),?"

    matches = re.findall(enum_value_pattern, enum_content)

    enum_dict = {name: int(value) for name, value in matches}

    return enum_dict


def open_CSV(file_path):
    with open(file_path, "r") as file:
        header_content = file.read()

    global_enum_values = extract_enum_values(header_content)

    return global_enum_values


""" for key, value in global_enum_values.items():
    print(f"{key} = {value}")


print(f"{len(global_enum_values)}") """
