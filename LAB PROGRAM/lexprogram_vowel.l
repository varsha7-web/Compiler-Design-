%{
#include<stdio.h>
int count=0;
%}

%%
[AEIOUaeiou] {
    printf("Vowel : %s\n", yytext);
    count++;
}

\n {
    printf("Total Vowels = %d\n", count);
    return 0;
}

. ;

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter String: ");
    yylex();
    return 0;
}