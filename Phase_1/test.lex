%{
#include <stdio.h>
#include <math.h>

int line_number = 1;
%}

ANYTHING .

DIGIT [0-9]
LETTER [a-zA-Z]

ASSIGNMENT [ \t]*is[ \t]*
END ;
INTEGER_DECLARATION tInt[ \t]+({LETTER}|{DIGIT})*[ \t]*(;)?
AN_INTEGER {DIGIT}*
INTEGER_ASSIGNMENT ({INTEGER_DECLARATION})*{ASSIGNMENT}{AN_INTEGER}[ \t]*{END}

INT_ARRAY_DECLARATION tInt_array
AN_INT_ARRAY \[({AN_INTEGER}(?:,{AN_INTEGER})*)\]?
INTEGER_ARRAY_ASSIGNMENT {INT_ARRAY_DECLARATION}{ASSIGNMENT}{AN_INT_ARRAY}{END}


%%

{INTEGER_ASSIGNMENT} {
    printf("Integer assignment: %s\n", yytext);
}

{INTEGER_ARRAY_ASSIGNMENT} {
    printf("Integer array assignment: %s\n", yytext);
}

{INTEGER_DECLARATION} {
    if (isdigit(yytext[5])) {
        fprintf(stderr, "Error: Variable starts with a number\n");
    } else {
        printf("Integer scalar variable declaration: %s\n", yytext);
    }
}

"/p" printf("%s\n", "PLUS");
"/m" printf("%s\n", "MINUS");
"/t" printf("%s\n", "TIMES");
"/d" printf("%s\n", "DIVIDE");

. {
    fprintf(stderr, "Error: Invalid symbol at line %d: %s\n", line_number, yytext);
}

%%

int main() {
    yylex();
    return 0;
}
