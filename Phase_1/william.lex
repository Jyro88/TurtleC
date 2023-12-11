%{
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-Z]
EXTENSION .txt
READFILE read\(\"({DIGIT}|{LETTER})*{EXTENSION}\"\);

/*can be if, if else, or if elif+ else */
/* the problems listed immediately below are because flex does not have recursion or lookahead capabilities*/
/* no nesting */
/* cannot have % anywhere within outer two %'s */
/* inside of () there cannot be a newline because adding newline recognition means you cant have child parentheses*/                               
IF_THEN_ELIF if[ \t, \n]*\(.*\)[ \t, \n]*\%[^%]*\%((elif[ \t, \n]*\(.*\)[ \t, \n]*\%[^%]*\%)*?[ \t, \n]*else[ \t, \n]*\%[^%]*\%)?

%%
{READFILE} {
    printf("read successful");
}

{IF_THEN_ELIF} {
    printf("if then else");
}

%%

int main() {
    yylex();
    return 0;
}
