
FIRST = {
    "E": {"id", "("},
    "E'": {"+", "ε"},
    "T": {"id", "("},
    "T'": {"*", "ε"},
    "F": {"id", "("}
}

# FOLLOW Sets
FOLLOW = {
    "E": {")", "$"},
    "E'": {")", "$"},
    "T": {"+", ")", "$"},
    "T'": {"+", ")", "$"},
    "F": {"*", "+", ")", "$"}
}

# LL(1) Parsing Table
parsing_table = {
    ("E", "id"): ["T", "E'"],
    ("E", "("): ["T", "E'"],

    ("E'", "+"): ["+", "T", "E'"],
    ("E'", ")"): ["ε"],
    ("E'", "$"): ["ε"],

    ("T", "id"): ["F", "T'"],
    ("T", "("): ["F", "T'"],

    ("T'", "*"): ["*", "F", "T'"],
    ("T'", "+"): ["ε"],
    ("T'", ")"): ["ε"],
    ("T'", "$"): ["ε"],

    ("F", "id"): ["id"],
    ("F", "("): ["(", "E", ")"]
}

# Input String
input_string = ["id", "+", "id", "*", "id", "$"]

stack = ["$", "E"]

print("=" * 75)
print("LL(1) Predictive Parsing")
print("=" * 75)

print("\nFIRST Sets")
for nt, val in FIRST.items():
    print(f"FIRST({nt}) = {val}")

print("\nFOLLOW Sets")
for nt, val in FOLLOW.items():
    print(f"FOLLOW({nt}) = {val}")

print("\nParsing Process")
print("-" * 75)
print("{:<25}{:<30}{}".format("Stack", "Input", "Action"))
print("-" * 75)

while True:
    stack_display = " ".join(stack)
    input_display = " ".join(input_string)

    top = stack[-1]
    current = input_string[0]

    if top == current == "$":
        print("{:<25}{:<30}Accepted".format(stack_display, input_display))
        break

    # Terminal
    if top not in ["E", "E'", "T", "T'", "F"]:
        if top == current:
            print("{:<25}{:<30}Match {}".format(stack_display, input_display, current))
            stack.pop()
            input_string.pop(0)
        else:
            print("String Rejected")
            break

    else:
        production = parsing_table.get((top, current))

        if production is None:
            print("String Rejected")
            break

        print("{:<25}{:<30}{} -> {}".format(
            stack_display,
            input_display,
            top,
            " ".join(production)
        ))

        stack.pop()

        if production != ["ε"]:
            for symbol in reversed(production):
                stack.append(symbol)

print("\nFinal Result : String Accepted")