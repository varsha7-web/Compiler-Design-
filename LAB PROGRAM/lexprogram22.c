#include <stdio.h>

int main()
{
    char op, arg1, arg2, result;

    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Enter first operand: ");
    scanf(" %c", &arg1);

    printf("Enter second operand: ");
    scanf(" %c", &arg2);

    printf("Enter result variable: ");
    scanf(" %c", &result);

    printf("\nTarget Code:\n");

    printf("MOV R0, %c\n", arg1);

    switch (op)
    {
        case '+':
            printf("ADD R0, %c\n", arg2);
            break;

        case '-':
            printf("SUB R0, %c\n", arg2);
            break;

        case '*':
            printf("MUL R0, %c\n", arg2);
            break;

        case '/':
            printf("DIV R0, %c\n", arg2);
            break;

        default:
            printf("Invalid operator\n");
            return 1;
    }

    printf("MOV %c, R0\n", result);

    return 0;
}