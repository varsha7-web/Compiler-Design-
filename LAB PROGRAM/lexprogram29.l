%{
#include <stdio.h>
%}

%%

<[^>]+>    { printf("%s\n", yytext); }

.|\n       ;

%%

int main()
{
    FILE *fp;

    fp = fopen("sample.html", "r");

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