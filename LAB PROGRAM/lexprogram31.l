%{
#include <stdio.h>

int comments = 0;
FILE *out;
%}

%%

"//".*                  { comments++; }

"/*"([^*]|\*+[^*/])*\*+"/"   { comments++; }

\n                      { fputc('\n', out); }

.                       { fputs(yytext, out); }

%%

int main()
{
    FILE *fp;

    fp = fopen("input.c", "r");
    out = fopen("output.c", "w");

    if (fp == NULL || out == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    yyin = fp;
    yylex();

    fclose(fp);
    fclose(out);

    printf("Number of comments = %d\n", comments);
    printf("Comments removed and saved in output.c\n");

    return 0;
}

int yywrap()
{
    return 1;
}