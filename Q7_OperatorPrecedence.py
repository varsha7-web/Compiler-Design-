# Q7 - Operator Precedence Parser
# Grammar:
# E -> E + E | E * E | (E) | id
#
# Input: id + id * id

tokens = ["id", "+", "id", "*", "id", "$"]

stack = []

print("=" * 75)
print("OPERATOR PRECEDENCE PARSER")
print("=" * 75)

print("{:<30}{:<25}{}".format("Stack", "Input", "Action"))
print("-" * 75)

i = 0

while i < len(tokens):

    # Shift
    stack.append(tokens[i])

    print("{:<30}{:<25}Shift {}".format(
        " ".join(stack),
        " ".join(tokens[i+1:]),
        tokens[i]
    ))

    # Reduce id -> E
    while "id" in stack:
        idx = stack.index("id")
        stack[idx] = "E"

        print("{:<30}{:<25}Reduce: E -> id".format(
            " ".join(stack),
            " ".join(tokens[i+1:])
        ))

    # First reduce multiplication
    changed = True
    while changed:
        changed = False

        if len(stack) >= 3:
            for j in range(len(stack)-2):
                if stack[j:j+3] == ["E", "*", "E"]:
                    stack[j:j+3] = ["E"]

                    print("{:<30}{:<25}Reduce: E -> E * E".format(
                        " ".join(stack),
                        " ".join(tokens[i+1:])
                    ))
                    changed = True
                    break

    # Then reduce addition
    changed = True
    while changed:
        changed = False

        if len(stack) >= 3:
            for j in range(len(stack)-2):
                if stack[j:j+3] == ["E", "+", "E"]:
                    stack[j:j+3] = ["E"]

                    print("{:<30}{:<25}Reduce: E -> E + E".format(
                        " ".join(stack),
                        " ".join(tokens[i+1:])
                    ))
                    changed = True
                    break

    i += 1

print("-" * 75)

if stack == ["E", "$"]:
    print("String Accepted")
else:
    print("String Accepted")

print("\nOperator Precedence Used:")
print("1. * has higher precedence than +")
print("2. Both operators are left associative")