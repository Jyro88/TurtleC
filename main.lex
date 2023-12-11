%{
#include <math.h>
#include <stdio.h>
unsigned long long current_line = 1;
unsigned long long current_column = 1;
%}

/* Basics */

/* Name                 REGEX   */ 
DIGIT                   [0-9]
LETTER                  [a-zA-Z]
/* An identifier must start with a letter. Then it can have any number of letters, numbers, and underscores */
IDENTIFIER              {LETTER}({LETTER}|{DIGIT})* 
INTEGER                 {DIGIT}+
INTEGER_DATATYPE        tInt

/*  Related to integer scalar variables */

/* Name                             REGEX   */ 
INTEGER_DECLARATION                 {INTEGER_DATATYPE}[ \t]+{IDENTIFIER}[ \t]*;
INTEGER_ASSIGNMENT                  {IDENTIFIER}{ASSIGNMENT}{INTEGER};
INTEGER_DECLARATION_AND_ASSIGNMENT  {INTEGER_DATATYPE}[ \t]+{IDENTIFIER}{INTEGER_ASSIGNMENT}


/* ASSIGNMENT */
ASSIGNMENT              [ \t]+is[ \t]+

/* Integer Array */

INTEGER_ARRAY_DECLARATION                   {INTEGER_DATATYPE}_array[ \t]+{IDENTIFIER}[ \t]*;
INTEGER_ARRAY                               \[({INTEGER}(?:,{INTEGER})*)?\]
INTEGER_ARRAY_DECLARATION_AND_ASSIGNMENT    {INTEGER_DATATYPE}_array[ \t]+{IDENTIFIER}({ASSIGNMENT})?{SPACES}{INTEGER_ARRAY};

INTEGER_ARRAY_ASSIGNMENT                    {IDENTIFIER}{ASSIGNMENT}{INTEGER_ARRAY}[ \t]*;

EXTENSION .txt
READFILE read\(\"({DIGIT}|{LETTER})*{EXTENSION}\"\);

/*can be if, if else, or if elif+ else */
/* the problems listed immediately below are because flex does not have recursion or lookahead capabilities*/
/* no nesting */
/* cannot have % anywhere within outer two %'s */
/* inside of () there cannot be a newline because adding newline recognition means you cant have child parentheses*/                               
IF_THEN_ELIF if[ \t, \n]*\(.*\)[ \t, \n]*\%[^%]*\%((elif[ \t, \n]*\(.*\)[ \t, \n]*\%[^%]*\%)*?[ \t, \n]*else[ \t, \n]*\%[^%]*\%)?

DATA_TYPE [tInt, tString, tDouble, tBool, Void]
DATA_TYPES {SPACES},{SPACES}{DATA_TYPE}
COMMENT [~]
NEWLINE [\n]
SPACES [ \t]*

WHILE_LOOP while[ \t]+this{SPACES}:{SPACES}\({SPACES}\){SPACES}\{\}

BREAK_STATEMENT terminate{SPACES};
%%

{INTEGER_DECLARATION}  {
    printf("Integer scalar variable declaration: %s\n", yytext);
    current_column += yyleng;
}

{INTEGER_ASSIGNMENT} {
    printf("Integer scalar variable assignment: %s\n", yytext);
    current_column += yyleng;
}

{INTEGER_ARRAY} {
    current_column += yyleng;
}

{INTEGER_ARRAY_ASSIGNMENT} {
    printf("Integer array assignment: %s\n", yytext);
    current_column += yyleng;
}

{INTEGER_ARRAY_DECLARATION} {

    printf("Integer array declaration: %s\n", yytext);
    current_column += yyleng;
}

{INTEGER_ARRAY_DECLARATION_AND_ASSIGNMENT} {
    printf("Integer array declaration and assignment: %s\n", yytext);
    current_column += yyleng;
}


{INTEGER_DATATYPE} {
    current_column += yyleng;
}

{READFILE} {
    printf("read successful \n");

}

{IF_THEN_ELIF} {
    printf("if then else \n");

  
}

{COMMENT}.+{NEWLINE} {printf("Single Comment: %s\n", yytext); current_column += yyleng;}
\\~(.|{NEWLINE})+~\\ {printf("Multi-line Comment: %s\n", yytext); current_column += yyleng;}

.+:{SPACES}\[({DATA_TYPE}{SPACES}{IDENTIFIER}({DATA_TYPES}{IDENTIFIER})?)*\]{SPACES}->{SPACES}tInt {
    printf("Function Call: %s\n", yytext); current_column += yyleng;}






"/p" {printf("%s\n", "PLUS"); current_column++; }
"/m" {printf("%s\n", "MINUS"); current_column++; }
"/t" {printf("%s\n", "TIMES"); current_column++; }
"/d" {printf("%s\n", "DIVIDE"); current_column++; }

"/lt" {printf("%s\n", "LESS THAN"); current_column++; }
"/gt" {printf("%s\n", "GREATER THAN"); current_column++; }
"/eq" {printf("%s\n", "EQUALS"); current_column++; }
"/neq" {printf("%s\n", "NOT EQUALS"); current_column++; }

{WHILE_LOOP} {printf("While Loop: %s\n", yytext);}

{BREAK_STATEMENT} {printf("Break statement: %s\n", yytext); current_column += yyleng;}

\n {
    ++current_line;
    current_column = 1; // Reset column number on new lines
}

[ \t\r]+ {
    current_column += yyleng; // Update column number for whitespace
}


{DIGIT}+{IDENTIFIER} {
    fprintf(stderr, "Error at line %llu, column %llu: Identifier \"%s\" must not begin with a number\n", current_line, current_column, yytext);
    current_column += yyleng;
}

. {
    fprintf(stderr, "Unrecognized symbol at line %llu, column %llu: %s\n", current_line, current_column, yytext);
    current_column += yyleng;
}

%%

int main(int argc, char **argv) {
    if (argc == 2 && !(yyin = fopen(argv[1], "r"))) { 
        fprintf(stderr, "could not open input FILE \n");
        return -1;
    }

    yylex();
    return 0;
}
