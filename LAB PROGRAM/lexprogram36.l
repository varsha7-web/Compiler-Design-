%{
#include <stdio.h>
%}

%%

"int"|"float"|"char"|"void"|"return"|"if"|"else"|"while"|"for"
            { printf("KEYWORD: %s\n", yytext); }

[0-9]+      { printf("CONSTANT: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*
            { printf("IDENTIFIER: %s\n", yytext); }

[+\-*/=]
            { printf("OPERATOR: %s\n", yytext); }

[(){};,]
            { printf("SPECIAL SYMBOL: %s\n", yytext); }

\"[^\"]*\"
            { printf("STRING: %s\n", yytext); }

[ \t\n]+    ;

.           ;

%%

int main()
{
    FILE *fp = fopen("sample.c", "r");

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