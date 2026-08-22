#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp;
    char filename[50], ch;
    int characters = 0, words = 0, lines = 0;
    int inWord = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if (ch == '\n')
            lines++;

        if (isspace(ch))
            inWord = 0;
        else if (inWord == 0)
        {
            words++;
            inWord = 1;
        }
    }

    if (characters > 0 && ch != '\n')
        lines++;

    fclose(fp);

    printf("Number of characters = %d\n", characters);
    printf("Number of words = %d\n", words);
    printf("Number of lines = %d\n", lines);

    return 0;
}