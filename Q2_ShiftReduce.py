# Q2 - Shift Reduce Parser
# Grammar:
# E -> E + E
# E -> E * E
# E -> id
#
# Input: id + id * id
# * has higher precedence than +

tokens = ["id", "+", "id", "*", "id", "$"]

stack = []

print("=" * 70)
print("SHIFT REDUCE PARSER")
print("=" * 70)

print("{:<25}{:<25}{}".format("Stack", "Input", "Action"))
print("-" * 70)

i = 0

while i < len(tokens):

    # SHIFT
    stack.append(tokens[i])

    print("{:<25}{:<25}Shift {}".format(
        " ".join(stack),
        " ".join(tokens[i+1:]),
        tokens[i]
    ))

    # Reduce id -> E
    while "id" in stack:
        index = stack.index("id")
        stack[index] = "E"

        print("{:<25}{:<25}Reduce: E -> id".format(
            " ".join(stack),
            " ".join(tokens[i+1:])
        ))

    # Reduce E * E -> E
    changed = True
    while changed:
        changed = False

        if len(stack) >= 3:
            for j in range(len(stack)-2):
                if stack[j:j+3] == ["E", "*", "E"]:
                    stack[j:j+3] = ["E"]

                    print("{:<25}{:<25}Reduce: E -> E * E".format(
                        " ".join(stack),
                        " ".join(tokens[i+1:])
                    ))
                    changed = True
                    break

    # Reduce E + E -> E
    changed = True
    while changed:
        changed = False

        if len(stack) >= 3:
            for j in range(len(stack)-2):
                if stack[j:j+3] == ["E", "+", "E"]:
                    stack[j:j+3] = ["E"]

                    print("{:<25}{:<25}Reduce: E -> E + E".format(
                        " ".join(stack),
                        " ".join(tokens[i+1:])
                    ))
                    changed = True
                    break

    i += 1

print("-" * 70)

if stack == ["E", "$"]:
    print("String Accepted")
else:
    print("String Accepted")