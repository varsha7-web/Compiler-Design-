%{
#include<stdio.h>
%}

%%

[a-zA-Z_][a-zA-Z0-9_]* {
    int i, capital = 0;

    for(i = 0; yytext[i] != '\0'; i++)
    {
        if(yytext[i] >= 'A' && yytext[i] <= 'Z')
            capital++;
    }

    printf("Valid Identifier\n");
    printf("Number of Capital Letters = %d\n", capital);
}

.* {
    printf("Invalid Identifier\n");
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter an Identifier: ");
    yylex();
    return 0;
}