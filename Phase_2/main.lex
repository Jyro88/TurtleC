%{
#include <math.h>
#include <stdio.h>
#include "y.tab.c"

int current_line = 1;
int current_column = 1;
%}

/* Basics */

/* Name                 REGEX   */ 
DIGIT                   [0-9]
LETTER                  [a-zA-Z]

IDENTIFIER              {LETTER}({LETTER}|{DIGIT})* 

WHITESPACE [ \t | \n]*

EXTENSION .txt


%%
{DIGIT}+ {yylval.num = atoi(yytext); current_column+=yyleng; return NUM;}

                 
"("                 {current_column+=yyleng; return L_PARENTHESIS;}

")"                 {current_column+=yyleng; return R_PARENTHESIS;}

"["                 {current_column+=yyleng; return L_BRACKET;}

"]"                 {current_column+=yyleng; return R_BRACKET;}

"\""                {current_column+=yyleng; return QUOTE;}

"~"                 {current_column+=yyleng; return COMMENT;}

"/p"                {current_column+=yyleng; return PLUS;}

"/m"                {current_column+=yyleng; return MINUS;}

"/t"               {current_column+=yyleng; return TIMES;} 

"/d"               {current_column+=yyleng; return DIVIDE;}
 
"&&"               {current_column+=yyleng; return AND;}

"||"               {current_column+=yyleng; return OR;}

"!"                {current_column+=yyleng; return NOT;}

"/gt"                {current_column+=yyleng; return GREATER_THAN;}

"/lt"                {current_column+=yyleng; return LESS_THAN;}

"/gte"               {current_column+=yyleng; return GREATER_THAN_EQUAL;}

"/lte"               {current_column+=yyleng; return LESS_THAN_EQUAL;}

"TRUE"             {current_column+=yyleng; return TRUE;}

"FALSE"            {current_column+=yyleng; return FALSE;}

":"                {current_column+=yyleng; return COLON;}

";"                {current_column+=yyleng; return SEMICOLON;}

"read"              {return READ; current_column+=yyleng;}    

"write"             {return WRITE; current_column+=yyleng;}

"tInt"      {current_column+=yyleng; return INTEGER_DATATYPE;}

"->"               {current_column+=yyleng; return RETURN_TYPE_ARROW;}

"{"                {current_column+=yyleng; return L_CURLY;}

"}"                   {current_column+=yyleng; return R_CURLY;}

"\n"                {++current_line; current_column = 1;}

"output"            {return RETURN; current_column+=yyleng;}

"while"             {return WHILE; current_column+=yyleng;}

"this"              {return THIS; current_column+=yyleng;}

"is"                {return ASSIGNMENT; current_column+=yyleng;}     

"if"               {return IF; current_column+=yyleng;}

"elif"             {return ELIF; current_column+=yyleng;}

"else"              {return ELSE; current_column+=yyleng;}

","                 {return COMMA; current_column+=yyleng;}

"/"                 {return BACKSLASH; current_column+=yyleng;}       

"arrayOf_"    {return INTEGER_ARRAY_DATATYPE; current_column+=yyleng;} 

"terminate"        {return TERMINATE; current_column+=yyleng; }
 
"/eq"                {return EQUIVALENT; current_column+=yyleng;}
    
"/neq"                {return NOT_EQUIVALENT; current_column+=yyleng;}

"."                 {return PERIOD; current_column+=yyleng;}

"_"             {return UNDERSCORE; current_column+=yyleng;}

{IDENTIFIER}            {current_column+=yyleng; return IDENTIFIER;}

[.]*                {current_column+=yyleng; return VALID_CHAR;}

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
    return VALID_CHAR;
}

%%

int main(int argc, char **argv) {
    if (argc == 2 && !(yyin = fopen(argv[1], "r"))) { 
        fprintf(stderr, "could not open input FILE \n");
        return -1;
    }

    yyparse();
    return 0;
}