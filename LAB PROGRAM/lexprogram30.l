%{
#include <stdio.h>

int line = 1;
%}

%%

^.*\n      { printf("%d: %s", line++, yytext); }
.+         { printf("%d: %s\n", line++, yytext); }

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

    fclose(fp);
    return 0;
}

int yywrap()
{
    return 1;
}