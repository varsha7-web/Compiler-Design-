#include <stdio.h>

char trailing[3][10];
int count[3] = {0};

void add(int n, char ch)
{
    int i;

    for (i = 0; i < count[n]; i++)
    {
        if (trailing[n][i] == ch)
            return;
    }

    trailing[n][count[n]++] = ch;
}

void findTrailing()
{
    /* F -> (E) | id */
    add(2, ')');
    add(2, 'i');

    /* T -> T*F | F */
    add(1, '*');

    for (int i = 0; i < count[2]; i++)
        add(1, trailing[2][i]);

    /* E -> E+T | T */
    add(0, '+');

    for (int i = 0; i < count[1]; i++)
        add(0, trailing[1][i]);
}

void display(char ch, int n)
{
    int i;

    printf("TRAILING(%c) = { ", ch);

    for (i = 0; i < count[n]; i++)
    {
        printf("%c", trailing[n][i]);

        if (i < count[n] - 1)
            printf(", ");
    }

    printf(" }\n");
}

int main()
{
    findTrailing();

    display('E', 0);
    display('T', 1);
    display('F', 2);

    return 0;
}