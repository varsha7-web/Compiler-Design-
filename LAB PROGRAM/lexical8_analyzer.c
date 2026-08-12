#include <stdio.h>
#include <ctype.h>

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '=' || ch == '<' ||
            ch == '>');
}

int main()
{
    char str[100];
    int i = 0;

    printf("Enter an expression: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0')
    {
        /* Identify identifier */
        if (isalpha(str[i]) || str[i] == '_')
        {
            printf("Identifier: ");

            while (isalnum(str[i]) || str[i] == '_')
            {
                printf("%c", str[i]);
                i++;
            }

            printf("\n");
        }

        /* Identify constant */
        else if (isdigit(str[i]))
        {
            printf("Constant: ");

            while (isdigit(str[i]))
            {
                printf("%c", str[i]);
                i++;
            }

            printf("\n");
        }

        /* Identify operator */
        else if (isOperator(str[i]))
        {
            printf("Operator: %c\n", str[i]);
            i++;
        }

        else
        {
            i++;
        }
    }

    return 0;
}