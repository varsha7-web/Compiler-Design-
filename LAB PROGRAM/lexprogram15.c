#include <stdio.h>
#include <string.h>

int main()
{
    char lhs, alpha[20], beta[20];
    char production[50];

    printf("Enter production with left recursion:\n");
    printf("Example: L->L,S|S\n");
    scanf("%s", production);

    lhs = production[0];

    /* Find -> */
    int i = 3, j = 0, k = 0;

    /*
       Read first production after ->
       Example: L,S
    */
    while (production[i] != '|' && production[i] != '\0')
    {
        alpha[j++] = production[i++];
    }
    alpha[j] = '\0';

    /* Read second production */
    if (production[i] == '|')
        i++;

    while (production[i] != '\0')
    {
        beta[k++] = production[i++];
    }
    beta[k] = '\0';

    /* Check left recursion */
    if (alpha[0] == lhs)
    {
        /* Remove the left-recursive symbol */
        memmove(alpha, alpha + 1, strlen(alpha));

        printf("\nAfter eliminating left recursion:\n");
        printf("%c -> %s%c'\n", lhs, beta, lhs);
        printf("%c' -> %s%c' | e\n", lhs, alpha, lhs);
    }
    else
    {
        printf("No left recursion found.\n");
    }

    return 0;
}