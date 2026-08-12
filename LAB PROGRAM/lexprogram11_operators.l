%{
#include <stdio.h>
%}

%%
"+"     { printf("Operator: +\n"); }
"-"     { printf("Operator: -\n"); }
"*"     { printf("Operator: *\n"); }
"/"     { printf("Operator: /\n"); }
[ \t\n]+ ;
.       { printf("Not an operator: %s\n", yytext); }
%%

int main()
{
    printf("Enter an expression:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}