%{
#include <stdio.h>

int macros = 0;
int headers = 0;
%}

%%

^[ \t]*#[ \t]*define      { macros++; }
^[ \t]*#[ \t]*include     { headers++; }

.|\n                       ;

%%

int main()
{
    FILE *fp;

    fp = fopen("sample.c", "r");

    if (fp == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }

    yyin = fp;
    yylex();

    printf("Number of macros = %d\n", macros);
    printf("Number of header files = %d\n", headers);

    fclose(fp);
    return 0;
}

int yywrap()
{
    return 1;
}