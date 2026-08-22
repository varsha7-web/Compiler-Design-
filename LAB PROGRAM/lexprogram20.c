#include <stdio.h>
#include <string.h>

int main()
{
    char exp[50];
    char op1, op2, op;
    char temp = '1';

    printf("Enter expression: ");
    scanf("%s", exp);

    while (strchr(exp, '*') || strchr(exp, '/'))
    {
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '*' || exp[i] == '/')
            {
                op1 = exp[i - 1];
                op = exp[i];
                op2 = exp[i + 1];

                printf("t%c = %c %c %c\n", temp, op1, op, op2);

                exp[i - 1] = 't';
                exp[i] = temp;
                strcpy(&exp[i + 1], &exp[i + 2]);

                temp++;
                break;
            }
        }
    }

    while (strchr(exp, '+') || strchr(exp, '-'))
    {
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '+' || exp[i] == '-')
            {
                op1 = exp[i - 1];
                op = exp[i];
                op2 = exp[i + 1];

                printf("t%c = %c %c %c\n", temp, op1, op, op2);

                exp[i - 1] = 't';
                exp[i] = temp;
                strcpy(&exp[i + 1], &exp[i + 2]);

                temp++;
                break;
            }
        }
    }

    return 0;
}