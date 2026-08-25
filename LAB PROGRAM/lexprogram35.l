%{
#include <stdio.h>
%}

%%

[6-9][0-9]{9}    {
                    printf("Valid Mobile Number\n");
                    return 0;
                }

[0-9]+           {
                    printf("Invalid Mobile Number\n");
                    return 0;
                }

.                ;

%%

int main()
{
    printf("Enter mobile number: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}