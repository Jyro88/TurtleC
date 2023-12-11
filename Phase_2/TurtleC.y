%{
#include <stdio.h>
extern FILE * yyin;
extern int current_line;
extern int current_column; 

void yyerror(const char * msg) {
	printf("Error: On line %d, column %d: %s \n", current_line, current_column, msg);
}
%}

%union{
	int num;
}

%error-verbose

%start program

%token BACKSLASH RETURN WHILE VALID_CHAR TERMINATE UNDERSCORE READ WRITE COLON THIS IF ELIF ELSE COMMA INTEGER_ARRAY_DATATYPE EQUIVALENT NOT_EQUIVALENT SEMICOLON PERIOD RETURN_TYPE_ARROW L_BRACKET R_BRACKET TRUE FALSE GREATER_THAN_EQUAL LESS_THAN_EQUAL GREATER_THAN LESS_THAN NOT OR AND COMMENT L_PARENTHESIS R_PARENTHESIS QUOTE NUM PLUS MINUS DIVIDE TIMES ASSIGNMENT IDENTIFIER INTEGER_DATATYPE L_CURLY R_CURLY 
%%

program: functions
		{printf("program -> functions\n");};

functions: 	function functions
		{printf("functions -> function functions\n");}
		| {printf("functions -> epsilon\n");}; //epsilon
		
	
function: IDENTIFIER COLON L_BRACKET INTEGER_DATATYPE IDENTIFIER R_BRACKET RETURN_TYPE_ARROW INTEGER_DATATYPE L_CURLY statements R_CURLY
			{printf("function -> IDENTIFIER COLON L_BRACKET INTEGER_DATATYPE IDENTIFIER R_BRACKET RETURN_TYPE_ARROW INTEGER_DATATYPE L_CURLY statements R_CURLY\n");};

statements: statement statements {printf("statements -> statement statements\n");}
			|  		{printf("statements -> epsilon\n");}; //epsilon
			 
statement: numeric_expression 
			{printf("statement -> numeric_expression\n");};
			| read
			{printf("statement -> read\n");}
			| write
			{printf("statement -> write\n");}
			| break
			{printf("statement -> break\n");}
			| assignment_statement
			{printf("statement -> assignment_statement\n");}
			| variable_assignment
			{printf("statement -> variable_assignment\n");}
			| variable_declaration
			{printf("statement -> variable_declaration\n");}
			| array_declaration
			{printf("statement -> array_declaration\n");}
			| while_statement
			{printf("statement -> while_statement\n");}
			| return_statement
			{printf("statement -> return_statement\n");}
			| if_then_else_statement
			{printf("statement -> if_then_else_statement\n");}
			| single_comment
			{printf("statement -> comment\n");};

break: TERMINATE SEMICOLON {printf("break -> TERMINATE;\n");};

read: IDENTIFIER ASSIGNMENT READ L_PARENTHESIS IDENTIFIER R_PARENTHESIS
			{printf("read -> IDENTIFIER EQUIVALENT READ L_PARENTHESIS IDENTIFIER R_PARENTHESIS\n");};

write: WRITE L_PARENTHESIS IDENTIFIER COMMA IDENTIFIER R_PARENTHESIS	
			{printf("write -> WRITE L_PARENTHESIS IDENTIFIER COMMA IDENTIFIER R_PARENTHESIS\n");};			

add_operator: PLUS {printf("add_operator -> PLUS\n");} | MINUS {printf("add_operator -> MINUS\n");};
			
mult_operator: DIVIDE {printf("mult_operator -> DIVIDE\n");} | TIMES {printf("mult_operator -> TIMES\n");};

term: term mult_operator factor 
				{printf("term -> term mult_operator factor\n");}
				| factor 
				{printf("term -> factor\n");}
				;

factor: L_PARENTHESIS numeric_expression R_PARENTHESIS 
				{printf("factor -> L_PARENTHESIS numeric_expression R_PARENTHESIS\n");}
				| NUM
				{printf("factor -> NUM\n");}
				| IDENTIFIER
				{printf("factor -> IDENTIFIER\n");};
				;

numeric_expression: numeric_expression add_operator term 
				{printf("numeric_expression -> numeric_expression add_operator term\n");} 
				| term 
				{printf("numeric_expression -> term\n");}
				;

assignment_statement : variable_declaration SEMICOLON {printf("assignment_statement -> variable_declaration SEMICOLON\n");} 
		| variable_assignment SEMICOLON {printf("assignment_statement -> variable_declaration SEMICOLON\n");}; 
			
variable_declaration : INTEGER_DATATYPE IDENTIFIER ASSIGNMENT numeric_expression 
		{printf("variable_declaration -> INTEGER_DATATYPE IDENTIFIER ASSIGNMENT numeric_expression\n");}
		| INTEGER_DATATYPE IDENTIFIER SEMICOLON
		{printf("variable_declaration -> INTEGER_DATATYPE IDENTIFIER SEMICOLON\n");};

variable_assignment : IDENTIFIER ASSIGNMENT numeric_expression
		{printf("variable_assignment -> IDENTIFIER ASSIGNMENT numeric_expression\n");};

array_declaration : INTEGER_ARRAY_DATATYPE NUM IDENTIFIER SEMICOLON
		{printf("array_declaration ->  INTEGER_ARRAY_DATATYPE NUM IDENTIFIER SEMICOLON\n");};

relational_expression: LESS_THAN
			{printf("relational_expression -> LESS_THAN\n");}
			| GREATER_THAN
			{printf("relational_expression -> GREATER_THAN\n");}
			| LESS_THAN_EQUAL
			{printf("relational_expression -> LESS_THAN_EQUAL\n");}
			| GREATER_THAN_EQUAL
			{printf("relational_expression -> GREATER_THAN_EQUAL\n");};

while_statement: WHILE THIS COLON L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY
			{printf("while_statement -> WHILE THIS COLON L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY\n");}
			| WHILE THIS COLON L_PARENTHESIS IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY
			{printf("WHILE THIS COLON L_PARENTHESIS bool R_PARENTHESIS L_CURLY statements R_CURLY\n");};

return_statement: RETURN IDENTIFIER SEMICOLON
			{printf("return_statement -> RETURN IDENTIFIER SEMICOLON\n");};	

if_then_else_statement : if_statement
			{printf("if_then_else_statement -> if_statement\n");}
			|
			if_statement else_statement
			{printf("if_then_else_statement -> if_else_statement\n");}
			|
			if_statement elif_statement else_statement
			{printf("if_then_else_statement -> if_statement elif_statement else_statement\n");};

if_statement: IF L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY		
			{printf("if_statement -> IF L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY\n");};	

else_statement: ELSE L_CURLY statements R_CURLY 
			{printf("else_statement -> ELSE L_CURLY statements R_CURLY\n");};

elif_statement : ELIF L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY
			{printf("elif_statememt -> ELIF L_CURLY statements R_CURLY\n");};	

single_comment : COMMENT %prec VALID_CHAR
		{printf("single_comment -> COMMENT VALID_CHAR\n");};
		

%%


