#include <stdio.h>

int main()
{
    char p1[] = "AaAb";
    char p2[] = "BbBa";

    printf("Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> e\nB -> e\n\n");

    printf("FOLLOW(S) = { $ }\n");

    printf("FOLLOW(A) = { ");
    if (p1[1] == 'a')
        printf("a, ");
    if (p1[3] == '\0' || p1[3] == 'b')
        printf("$");
    printf(" }\n");

    printf("FOLLOW(B) = { ");
    if (p2[1] == 'b')
        printf("b, ");
    if (p2[3] == '\0' || p2[3] == 'a')
        printf("$");
    printf(" }\n");

    return 0;
}