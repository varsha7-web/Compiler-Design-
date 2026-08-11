%{
#include<stdio.h>
%}

%%
[a-zA-Z]+   { printf("Word : %s\n", yytext); }
[0-9]+      { printf("Number : %s\n", yytext); }
\n          { return 0; }
.           ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter Input: ");
    yylex();
    return 0;
}