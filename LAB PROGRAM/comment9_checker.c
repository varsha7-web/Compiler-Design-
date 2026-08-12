#include <stdio.h>
#include <string.h>

int main()
{
    char line[200];

    printf("Enter a line: ");
    fgets(line, sizeof(line), stdin);

    if (line[0] == '/' && line[1] == '/')
    {
        printf("The given line is a single-line comment.\n");
    }
    else if (line[0] == '/' && line[1] == '*')
    {
        if (strstr(line, "*/") != NULL)
            printf("The given line is a multi-line comment.\n");
        else
            printf("The given line starts as a multi-line comment.\n");
    }
    else
    {
        printf("The given line is not a comment.\n");
    }

    return 0;
}