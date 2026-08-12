#include <stdio.h>
#include <string.h>

int main()
{
    char p1[30], p2[30], p3[30];
    char prefix[30], r1[30], r2[30];
    int i = 0, j = 0;

    printf("Enter three productions:\n");
    printf("Example: iEtS iEtSeS a\n");
    scanf("%s %s %s", p1, p2, p3);

    /* Find common prefix of first two productions */
    while (p1[i] == p2[i] && p1[i] != '\0')
    {
        prefix[i] = p1[i];
        i++;
    }
    prefix[i] = '\0';

    /* Get remaining parts */
    strcpy(r1, p1 + i);
    strcpy(r2, p2 + i);

    /* Check whether left factoring is possible */
    if (strlen(prefix) > 0)
    {
        printf("\nAfter eliminating left factoring:\n");
        printf("S -> %sS' | %s\n", prefix, p3);
        printf("S' -> %s | %s\n", r1, r2);
    }
    else
    {
        printf("No common prefix found.\n");
    }

    return 0;
}