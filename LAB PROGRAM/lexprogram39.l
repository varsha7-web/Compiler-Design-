%{
#include <stdio.h>
%}

%%
oldword    printf("newword");
\n         printf("\n");
.          printf("%s", yytext);
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}