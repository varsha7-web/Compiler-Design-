#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int S()
{
    if (input[pos] == 'a')
    {
        pos++;

        if (input[pos] == 'b')
        {
            pos++;
            return 1;
        }

        if (S() && input[pos] == 'b')
        {
            pos++;
            return 1;
        }
    }

    return 0;
}

int main()
{
    printf("Grammar: S -> aSb | ab\n");

    printf("Enter the string: ");
    scanf("%s", input);

    if (S() && input[pos] == '\0')
        printf("String is accepted\n");
    else
        printf("String is rejected\n");

    return 0;
}