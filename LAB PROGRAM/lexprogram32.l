%{
#include <stdio.h>
%}

%%

[A-Z]+      { printf("Capital word: %s\n", yytext); }

[ \t\n]+    ;

.           ;

%%

int main()
{
    printf("Enter a sentence: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}