%{
#include <stdio.h>

int characters = 0;
int words = 0;
int lines = 0;
%}

%%

\n              { lines++; characters++; }
[ \t]+          { characters += yyleng; }
[A-Za-z0-9_]+   { words++; characters += yyleng; }
.               { characters += yyleng; }

%%

int main()
{
    yylex();

    printf("\nCharacters = %d\n", characters);
    printf("Words = %d\n", words);
    printf("Lines = %d\n", lines);

    return 0;
}

int yywrap()
{
    return 1;
}