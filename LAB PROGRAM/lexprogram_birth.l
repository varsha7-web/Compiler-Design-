{
#include<stdio.h>
%}

%%

([0-2][0-9]|3[0-1])"/"(0[1-9]|1[0-2])"/"(19[0-9][0-9]|20[0-9][0-9])   {
    printf("Valid Date of Birth\n");
}

.*  {
    printf("Invalid Date of Birth\n");
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter DOB (DD/MM/YYYY): ");
    yylex();
    return 0;
}