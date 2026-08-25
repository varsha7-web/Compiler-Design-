%{
#include <stdio.h>
%}

%%

[a-zA-Z0-9._]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}    {
                                                    printf("Valid Email Address\n");
                                                    return 0;
                                                 }

.*                                               {
                                                    printf("Invalid Email Address\n");
                                                    return 0;
                                                 }

%%

int main()
{
    printf("Enter email address: ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}