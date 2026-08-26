%{
#include <stdio.h>
#include <string.h>

int max = 0;
char longest[100];
%}

%%

[A-Za-z]+ {
    if (yyleng > max)
    {
        max = yyleng;
        strcpy(longest, yytext);
    }
}

[ \t]+    ;
\n        { return 0; }

.         ;

%%

int main()
{
    char input[500];

    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);

    YY_BUFFER_STATE buffer = yy_scan_string(input);

    yylex();

    printf("\nLongest word = %s\n", longest);
    printf("Length = %d\n", max);

    yy_delete_buffer(buffer);

    return 0;
}

int yywrap()
{
    return 1;
}