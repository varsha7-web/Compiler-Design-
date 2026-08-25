%{
#include <stdio.h>

int consonants = 0;
%}

%%

[BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz]  { consonants++; }

\n      { return 0; }

.       ;

%%

int main()
{
    printf("Enter a sentence: ");
    yylex();

    printf("Number of consonants = %d\n", consonants);

    return 0;
}

int yywrap()
{
    return 1;
}