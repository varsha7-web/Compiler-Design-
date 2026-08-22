%{
#include <stdio.h>
%}

%%

[0-9]+(\.[0-9]+)?     { printf("Constant: %s\n", yytext); }

.|\n                  ;

%%

int yywrap()
{
    return 1;
}

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

    fclose(fp);

    return 0;
}