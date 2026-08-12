%{
#include <stdio.h>

int spaces = 0;
int newlines = 0;
%}

%%
"END"       { yyterminate(); }
[ \t]       { spaces++; }
\n          { newlines++; }
.           ;
%%

int main()
{
    printf("Enter the text (type END to finish):\n");
    yylex();

    printf("\nNumber of whitespaces: %d\n", spaces);
    printf("Number of newline characters: %d\n", newlines);

    return 0;
}

int yywrap()
{
    return 1;
}