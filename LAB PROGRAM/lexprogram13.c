#include <stdio.h>
#include <string.h>

void first(char *p)
{
    int i;

    for (i = 0; p[i]; i++)
    {
        if (p[i] == 'A' || p[i] == 'B')
        {
            if (i == 0 || p[i - 1] == 'A' || p[i - 1] == 'B')
                continue;
        }

        if (p[i] == 'a' || p[i] == 'b')
        {
            printf("%c ", p[i]);
            return;
        }
    }
}

int main()
{
    char s1[] = "AaAb";
    char s2[] = "BbBa";

    printf("FIRST(S) = { ");
    first(s1);
    first(s2);
    printf("}\n");

    printf("FIRST(A) = { e }\n");
    printf("FIRST(B) = { e }\n");

    return 0;
}