%{
#include <stdio.h>

int vowels = 0;
%}

%%

[AEIOUaeiou]    { vowels++; }
\n              { return 0; }
.               ;

%%

int main()
{
    printf("Enter a sentence: ");
    yylex();

    printf("Number of vowels = %d\n", vowels);

    return 0;
}

int yywrap()
{
    return 1;
}