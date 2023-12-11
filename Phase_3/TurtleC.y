%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE * yyin;
extern int current_line;
extern int current_column; 

typedef struct labelNode{
	char* name;
	struct labelNode* nextLabel;
} labelNode;

//for while loops
struct labelNode *whileHead;

//for branch statements
struct labelNode *branchHead;

//for branch block endpoint
struct labelNode *endHead;


//select 0 is for while stack, select 1 is for branch stack, 2 is for end of branch block
void createLabelNode (char* name, int select) {
	if (select == 0) {
		struct labelNode* newNode = (struct labelNode*) malloc(sizeof(labelNode));
		newNode->name = name;
		newNode->nextLabel = whileHead;
		whileHead = newNode;
	}
	if (select == 1) {
		struct labelNode* newNode = (struct labelNode*) malloc(sizeof(labelNode));
		newNode->name = name;
		newNode->nextLabel = branchHead;
		branchHead = newNode;
	}
	if (select == 2) {
		struct labelNode* newNode = (struct labelNode*) malloc(sizeof(labelNode));
		newNode->name = name;
		newNode->nextLabel = endHead;
		endHead = newNode;
	}
	else {

	}
}


char* popLabelNode (int select) {
	if (select == 0) {
		char* temp = whileHead->name;
		whileHead = whileHead->nextLabel;
		return temp;
	}
	if (select == 1) {
		char* temp = branchHead->name;
		branchHead = branchHead->nextLabel;
		return temp;
	}
	if (select == 2) {
		char* temp = endHead->name;
		endHead = endHead->nextLabel;
		return temp;
	}
	else {

	}
}

char* getEndHead () {
	return endHead->name;
}

int yylex (void);
void yyerror(const char * msg) {
	printf("Error: On line %d, column %d: %s \n", current_line, current_column, msg);
}

static char* genTempName() {
	static unsigned long long counter;

	static char buff[4096]; 
    sprintf(buff, "_temp%llu", counter++);
	return strdup(buff);
}

static char* genTempLabel(int offset) {
	static unsigned long long counter;

	static char buff[4096]; 

	switch(offset){
		case 0: {sprintf(buff, "_label%llu", counter++);} break;
		default: {sprintf(buff, "_label%llu", counter);} break;
	}

	return strdup(buff);
}


typedef struct {char *name; char *code;} NameAndCodeData;


// creating a map for symbol table

#define HASH_TABLE_INITIAL_SIZE 100

typedef struct Node {
    char *identifier;
    char value;
    int isArray;
    int arraySize;
    struct Node *next;
} Node;


typedef struct HashTable {
    Node **nodes;
    int size;
    int count;
} HashTable;

typedef struct ScopeStack {
    HashTable *currentScope;
    struct ScopeStack *previousScope;
} ScopeStack;

unsigned int hash(char *key, int size) {
    unsigned int hashValue = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hashValue = hashValue * 31 + key[i];  // A simple hash function
    }
    return hashValue % size;
}

HashTable *createHashTable(int size) {
    HashTable *table = malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->nodes = malloc(sizeof(Node *) * size);
    for (int i = 0; i < size; i++) {
        table->nodes[i] = NULL;
    }
    return table;
}

Node *createNode(char *identifier, char value, int isArray, int arraySize) {
    Node *newNode = malloc(sizeof(Node));
    newNode->identifier = strdup(identifier);
    newNode->value = value;
    newNode->isArray = isArray;
    newNode->arraySize = arraySize;
    newNode->next = NULL;
    return newNode;
}


void freeNode(Node *node) {
    if (node) {
        free(node->identifier);
        free(node);
    }
}

void insert(HashTable *table, char *identifier, char value) {
    unsigned int index = hash(identifier, table->size);
    Node *newNode = createNode(identifier, value,0,0);
    newNode->next = table->nodes[index];
    table->nodes[index] = newNode;
    table->count++;
}

void insertArray(HashTable *table, char *identifier, int arraySize) {
    unsigned int baseIndex = hash(identifier, table->size);

    // Check if the base index is already used
    if (table->nodes[baseIndex] != NULL) {

        printf("Error: Collision detected or identifier already in use.\n");
        return;
    }

    // start array base
    Node *baseNode = createNode(identifier, 0, 1, arraySize);
    table->nodes[baseIndex] = baseNode;
    table->count++;

    // Insert additional nodes for array elements
    for (int i = 1; i < arraySize; i++) {
        // Calculate actual index for each element
        unsigned int actualIndex = (baseIndex + i) % table->size;

        // Check for collision at actual index
        if (table->nodes[actualIndex] != NULL) {
            // Handle collision or report an error
            printf("Error: Collision detected while inserting array elements.\n");
            // Optionally, remove the previously inserted nodes to clean up
            return;
        }

        // Create a dummy node for the array element with the value 0
        Node *newNode = createNode("", 0, 0, 0); // Empty identifier for non-base elements
        table->nodes[actualIndex] = newNode;
        table->count++;
    }
}


char find(HashTable *table, char *identifier) {
    unsigned int index = hash(identifier, table->size);
    Node *node = table->nodes[index];
    while (node != NULL) {
        if (strcmp(node->identifier, identifier) == 0) {
            return node->value;
        }
        node = node->next;
    }
    return '\0';  // Return null character if not found
}

int containsKey(HashTable *table, char *identifier) {
    unsigned int index = hash(identifier, table->size);
    Node *node = table->nodes[index];
    while (node != NULL) {
        if (strcmp(node->identifier, identifier) == 0) {
            return 1; // Key found
        }
        node = node->next;
    }
    return 0; // Key not found
}


ScopeStack *createScopeStack() {
    ScopeStack *stack = malloc(sizeof(ScopeStack));
    stack->currentScope = createHashTable(HASH_TABLE_INITIAL_SIZE);
    stack->previousScope = NULL;
    return stack;
}

void enterScope(ScopeStack **stack) {
    ScopeStack *newScope = createScopeStack();
    newScope->previousScope = *stack;
    *stack = newScope;
}

void exitScope(ScopeStack **stack) {
    if (stack && *stack) {
        ScopeStack *topScope = *stack;
        HashTable *table = topScope->currentScope;
        for (int i = 0; i < table->size; i++) {
            Node *node = table->nodes[i];
            while (node) {
                Node *temp = node;
                node = node->next;
                freeNode(temp);
            }
        }
        free(table->nodes);
        free(table);
        *stack = topScope->previousScope;
        free(topScope);
    }
}

char getArrayValue(HashTable *table, char *identifier, int index) {
    // Hash the identifier to find the base index
    unsigned int baseIndex = hash(identifier, table->size);

    // Check if the base node is an array and the index is within bounds
    Node *baseNode = table->nodes[baseIndex];
    if (baseNode != NULL && baseNode->isArray && index < baseNode->arraySize) {
        // Calculate actual node index
        unsigned int actualIndex = (baseIndex + index) % table->size;
        Node *targetNode = table->nodes[actualIndex];
        if (targetNode != NULL) {
            return targetNode->value;
        }
    }
    return '\0';  // Return null character if not found or out of bounds
}

void setArrayValue(HashTable *table, char *arrayIdentifier, int index, char newValue) {
    // Hash the array identifier to find the base index
    unsigned int baseIndex = hash(arrayIdentifier, table->size);

    // Find the base node for the array
    Node *baseNode = table->nodes[baseIndex];
    if (baseNode != NULL && baseNode->isArray && index < baseNode->arraySize) {
        // Calculate the actual index of the array element
        unsigned int actualIndex = (baseIndex + index) % table->size;
        Node *targetNode = table->nodes[actualIndex];

        // Check if the target node exists and is part of the array
        if (targetNode != NULL && (actualIndex == baseIndex || strcmp(targetNode->identifier, "") == 0)) {
            // Update the value of the array element
            targetNode->value = newValue;
        } else {
            // Handle the case where the target node does not exist or is not part of the array
            printf("Error: Invalid array index or array element does not exist.\n");
        }
    } else {
        // Handle the case where the array does not exist or the index is out of bounds
        printf("Error: Array not found or index out of bounds.\n");
    }
}


// Function variables
int param_index = 0;
int is_main_function = 0;
int has_return_statement = 0;
int main_function_defined = 0; 
// Scope Stack

// Every time you enter a function, you push a scope onto the stack

ScopeStack *scopeStack;

%}

%union{
	char *strVal; // To hold string values of identifiers and numbers
	char *operator; // To hold string values of an operator
	NameAndCodeData nameAndCode; 

}

%define parse.error verbose

%start program

%token CALL BACKSLASH RETURN WHILE VALID_CHAR TERMINATE UNDERSCORE READ WRITE COLON THIS IF ELIF ELSE COMMA ARRAY_DATATYPE EQUIVALENT NOT_EQUIVALENT SEMICOLON PERIOD RETURN_TYPE_ARROW L_BRACKET R_BRACKET TRUE FALSE GREATER_THAN_EQUAL LESS_THAN_EQUAL GREATER_THAN LESS_THAN NOT OR AND COMMENT L_PARENTHESIS R_PARENTHESIS QUOTE ASSIGNMENT INTEGER_DATATYPE L_CURLY R_CURLY
%token <strVal> NUM IDENTIFIER PLUS MINUS TIMES DIVIDE
%type <operator>  add_operator mult_operator relational_expression
%type<nameAndCode> factor term numeric_expression function_call while_statement 
%%

program: {scopeStack = createScopeStack();} functions {
    if (!main_function_defined) {
        yyerror("Error: No 'main' function defined.");
        YYABORT;
    }
}
		
functions: 	

		function functions
		// {printf("functions -> function functions\n");}

		| 
		// {printf("functions -> epsilon\n");}; //epsilon
		
function: 
    IDENTIFIER {
        param_index = 0; // Reset parameter index for the new function
        printf("func %s\n", $1);
        is_main_function = (strcmp($1, "main") == 0); // Set flag if function is "main"
		
		if (strcmp($1, "main") == 0) {
            main_function_defined = 1; // Set flag when 'main' is defined
            
        }
		enterScope(&scopeStack);
			
			// char * test = "a";
			// insert(scopeStack->currentScope , "a" , 5);
			// char value = find(scopeStack->currentScope, "a");
			// printf("VALUE YAY: %d\n " , value);
		
		
    }
    COLON L_BRACKET params R_BRACKET L_CURLY statements R_CURLY
    {
        if (!is_main_function && !has_return_statement) {
            yyerror("Non-main function must have a return statement.");
        }
        // Reset the flag for the next function
        is_main_function = 0;
        has_return_statement = 0;
		exitScope(&scopeStack);
        printf("endfunc\n");
    };

params: 
	params COMMA IDENTIFIER 
	{
		printf(". %s\n ", $3);
        printf("= %s, $%d\n ", $3, param_index++ );
     
	}

	|
	
	IDENTIFIER
	{
		printf(". %s\n" , $1);
		printf("= %s, $%d\n", $1, param_index++); 
	};

	|
	{/* epsilon */ }

statements: statement statements {/* printf("statements -> statement statements\n"); */}
			|  		{ /* printf("statements -> epsilon\n"); */ }; //epsilon
			 
statement: numeric_expression 
			{};

			| read
			{/* printf("statement -> read\n"); */}

			| write
			{/* printf("statement -> write\n"); */}

			| break
			{printf("statement -> break\n");}

			| variable_assignment
			{/* printf("statement -> variable_assignment\n"); */}

			| array_assignment 
			{}
			| array_assignment2
			{}

			| variable_declaration
			{/* printf("statement -> variable_declaration\n"); */}

			| array_declaration
			{/* printf("statement -> array_declaration\n"); */}

			| while_statement
			{}

			| return_statement
			{/* printf("statement -> return_statement\n"); */}

			| if_then_else_statement
			{}
			
			| single_comment
			{printf("statement -> comment\n");};

arg_list: arg_list COMMA numeric_expression 

	{
		char* parameter = genTempName();
		printf(". %s\n" , parameter);

		printf("= %s, %s\n" , parameter, $3.name);
		printf("param %s\n", parameter); // Append each parameter
    }
	
	| 
	
	numeric_expression 
	{
		// printf("arg_list -> numeric_expression\n");
		char* parameter = genTempName();
		printf(". %s\n" , parameter);

		printf("= %s, %s\n" , parameter, $1.name);
		printf("param %s\n", parameter);

	};

function_call : CALL IDENTIFIER L_PARENTHESIS arg_list R_PARENTHESIS
	{

		// name, dest
		char *registerName = genTempName();
		$$.name = registerName;
		printf(". %s\n" , registerName);
		printf("call %s, %s\n" , $2, registerName);
		// printf("function_call -> IDENTIFIER L_PARENTHESIS arg_list R_PARENTHESIS\n");

		
	};

break: TERMINATE {printf("break -> TERMINATE;\n");};

read: READ L_PARENTHESIS IDENTIFIER R_PARENTHESIS
			{
				printf(".< %s\n" , $3);
				// printf("read -> IDENTIFIER EQUIVALENT READ L_PARENTHESIS IDENTIFIER R_PARENTHESIS\n");
			};

write: WRITE L_PARENTHESIS IDENTIFIER R_PARENTHESIS	
			{
				printf(".> %s\n" , $3);
				// printf("write -> WRITE L_PARENTHESIS IDENTIFIER COMMA IDENTIFIER R_PARENTHESIS\n");
			};			

add_operator: 
	PLUS 
	{
		$$ = "+";
		// printf("add_operator -> PLUS, strVal: %s\n", $$);
	} 

	| 
	
	MINUS 
	{
		$$ = "-";
		// printf("add_operator -> MINUS, strVal: %s\n", $$);
	} 
			
mult_operator: 

	DIVIDE 
	{
		$$ = "/";
		// printf("mult_operator -> DIVIDE\n");
	} 
	
	| 
	
	TIMES 
	{
		$$ = "*";
		// printf("mult_operator -> TIMES\n");
	};

term: 
	term mult_operator factor 

    {
        $$.name = genTempName();
        
		
		// print out the code

		// To initialize the new temp variable		
		printf(". %s\n", $$.name);

		// To store the code
		printf("%s %s, %s, %s\n", $2, $$.name, $1.name, $3.name);

		// printf("term -> term mult_operator factor\n");


    }	
				
				
	| 
				
	factor 
	{
		// term.name = factor.name
		$$.name = $1.name;
		// printf("term -> factor, name: %s\n", $$.name);
	}
	;

factor: 

	L_PARENTHESIS numeric_expression R_PARENTHESIS 
    	{ 
			$$.name = $2.name;
			// printf("factor -> L_PARENTHESIS numeric_expression R_PARENTHESIS\n"); 
		}

    | NUM
    {
		// Value of num should be stored in factor.name.
		// factor.name = num.strVal
        $$.name = $1;
		// printf("factor -> NUM\n");
        // printf("factor -> NUM, name: %s\n", $$.name); // Comment out later
    }

	| function_call
	{
		// printf("factor -> function_call\n");
		$$.name = $1.name;
	
	}

		// a[5]
	| IDENTIFIER L_BRACKET NUM R_BRACKET

	{
		// a is nums[8]
		// name - the value of the array element
		// getArrayValue(HashTable *table, char *identifier, int index)

		// char arrayElementValue = getArrayValue(scopeStack->currentScope, "nums", 8);

		char* arrayElementTemp = genTempName();
		printf(". %s\n" , arrayElementTemp);
		printf("=[] %s, %s, %s\n" , arrayElementTemp, $1, $3 );
		$$.name = arrayElementTemp;
		
	}
	|
	IDENTIFIER L_BRACKET IDENTIFIER R_BRACKET

	{
		// a is nums[8]
		// name - the value of the array element
		// getArrayValue(HashTable *table, char *identifier, int index)

		// char arrayElementValue = getArrayValue(scopeStack->currentScope, "nums", 8);

		char* arrayElementTemp = genTempName();
		printf(". %s\n" , arrayElementTemp);
		printf("=[] %s, %s, %s\n" , arrayElementTemp, $1, $3 );
		$$.name = arrayElementTemp;
		
	}

    | IDENTIFIER
    {

        $$.name = $1;
 
        // printf("factor -> IDENTIFIER, name: %s\n", $$.name); // Comment out later
    };

numeric_expression: 

	numeric_expression add_operator term 
		{
			$$.name = genTempName();

			// print code

			// to intialize temporary variable for num_exp.  ex: . t1
			printf(". %s\n", $$.name);

			// assign value to the temp variable. ex: + t1, 2, 5 --> t1 = 2 + 5
			printf("%s %s, %s, %s\n" , $2, $$.name, $1.name, $3.name);

			// printf("numeric_expression -> numeric_expression add_operator term\n");
		} 
				
				
	| 
	
	term 
		{
			$$.name = $1.name;
			// printf("numeric_expression -> term\n");
		
		}
	;
			
variable_declaration : INTEGER_DATATYPE IDENTIFIER
		{
			// put in symbol table
			
			char *declaredIdentifier = $2;

        if (!containsKey(scopeStack->currentScope, declaredIdentifier)) {
            insert(scopeStack->currentScope, declaredIdentifier, 0);
            printf(". %s\n", declaredIdentifier);
        } else {
            // Duplicate identifier found, report an error
            char errorMessage[256];
            sprintf(errorMessage, "Duplicate identifier '%s' found.", declaredIdentifier);
            yyerror(errorMessage);
            YYABORT;  // Optionally abort the parsing
        }
			
			
			

			// char value = find(scopeStack->currentScope, test);

		
			// printf("VALUE YAY: %d\n " , value);

			// if(containsKey(scopeStack->currentScope, "a")) {
			// 	printf("Key 'a' exists in the current scope\n");

			// }

			// else {
			// 	printf("Key 'a' does NOT exist in the current scope\n");
			// }
		

			// printf("variable_declaration -> INTEGER_DATATYPE IDENTIFIER ASSIGNMENT numeric_expression\n");
		}
	
variable_assignment : IDENTIFIER ASSIGNMENT numeric_expression
		{
			
			

			printf("= %s, %s\n" , $1, $3.name);
			// printf("variable_assignment -> IDENTIFIER ASSIGNMENT numeric_expression\n");
			
		};

array_declaration : INTEGER_DATATYPE ARRAY_DATATYPE NUM IDENTIFIER 
    {
        char *arrayDecIdentifier = $4;
        char *arraySizeStr = $3;
        int arraySize = atoi(arraySizeStr);

        // Check if the array size is valid (greater than 0)
        if (arraySize <= 0) {
            printf("Error: Array size must be greater than 0. Given size: %d\n", arraySize);
            YYABORT;  // Optionally abort the parsing process
        } else {
            insertArray(scopeStack->currentScope, arrayDecIdentifier, arraySize);
            printf(".[] %s, %s\n", arrayDecIdentifier, arraySizeStr);
        }
    };


array_assignment: IDENTIFIER L_BRACKET NUM R_BRACKET ASSIGNMENT numeric_expression
	{
		// a[7] is 7
		// num is a[7]
		// void setArrayValue(HashTable *table, char *arrayIdentifier, int index, char newValue)
		// setArrayValue(scopeStack->currentScope, $1, atoi($3), (char)$6.name); // fix later

		printf("[]= %s, %s, %s\n" , $1, $3, $6.name);
	};

array_assignment2: IDENTIFIER L_BRACKET IDENTIFIER R_BRACKET ASSIGNMENT numeric_expression
	{
		// a[7] is 7
		// num is a[7]
		// void setArrayValue(HashTable *table, char *arrayIdentifier, int index, char newValue)
		// setArrayValue(scopeStack->currentScope, $1, atoi($3), (char)$6.name); // fix later

		printf("[]= %s, %s, %s\n" , $1, $3, $6.name);
	};

while_statement: 
    WHILE THIS COLON L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY
    {
        char* tempLabel = genTempLabel(0); 
        printf(": %s\n", tempLabel);
		createLabelNode(tempLabel, 0);
    }
    statements
    R_CURLY
    {
        char* tempName = genTempName();
		char* labelName = popLabelNode(0);
        printf(". %s\n", tempName);
        printf("%s %s, %s, %s\n", $6, tempName, $5, $7);
        printf("?:= %s, %s\n", labelName, tempName);
		
    }

			// | WHILE THIS COLON L_PARENTHESIS IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY
			// {printf("WHILE THIS COLON L_PARENTHESIS bool R_PARENTHESIS L_CURLY statements R_CURLY\n");};

relational_expression: LESS_THAN
			{$$ = "<";}
			| GREATER_THAN
			{$$ = ">";}
			| LESS_THAN_EQUAL
			{$$ = "<=";}
			| GREATER_THAN_EQUAL
			{$$ = ">=";}
			| EQUIVALENT
			{$$ = "==";}
			| NOT_EQUIVALENT
			{$$ = "!=";}

return_statement: RETURN numeric_expression
    {
        has_return_statement = 1;
		
        printf("ret %s\n" , $2.name);
    }; 

if_then_else_statement : if_statement
			{
				char* endPoint = popLabelNode(2);
				printf(": %s\n", endPoint);
			}
			|
			if_statement else_statement
			{
				char* endPoint = popLabelNode(2);
				printf(": %s\n", endPoint);
			}
			|
			if_statement elif_statement else_statement
			{
				char* endPoint = popLabelNode(2);
				printf(": %s\n", endPoint);
			}

if_statement: IF L_PARENTHESIS IDENTIFIER relational_expression numeric_expression R_PARENTHESIS L_CURLY	
			{
				char* tempLabel1 = genTempLabel(0);
				char* tempLabel2 = genTempLabel(0);
				createLabelNode(tempLabel1, 1);
				createLabelNode(tempLabel2, 2);
				char* tempName = genTempName();
				printf(". %s\n", tempName);
        		printf("%s %s, %s, %s\n", $4, tempName, $3, $5);
				printf("! %s, %s\n", tempName, tempName);
				printf("?:= %s, %s\n", tempLabel1, tempName);
			}
			statements 
			R_CURLY	
			{
				char* endPoint = getEndHead();
				printf(":= %s\n", endPoint);

				char* labelName = popLabelNode(1);
				printf(": %s\n", labelName);
			}	



//printf("if_statement -> IF L_PARENTHESIS IDENTIFIER relational_expression IDENTIFIER R_PARENTHESIS L_CURLY statements R_CURLY\n");

else_statement: ELSE L_CURLY statements R_CURLY 
			{}

//printf("else_statement -> ELSE L_CURLY statements R_CURLY\n");

elif_statement : ELIF L_PARENTHESIS IDENTIFIER relational_expression numeric_expression R_PARENTHESIS L_CURLY
			{
				char* tempLabel1 = genTempLabel(0);
				createLabelNode(tempLabel1, 1);
				char* tempName = genTempName();
				printf(". %s\n", tempName);
        		printf("%s %s, %s, %s\n", $4, tempName, $3, $5);
				printf("! %s, %s\n", tempName, tempName);
				printf("?:= %s, %s\n", tempLabel1, tempName);
			}
			statements
			R_CURLY
			{
				char* endPoint = getEndHead();
				printf(":= %s\n", endPoint);

				char* labelName = popLabelNode(1);
				printf(": %s\n", labelName);
			}

// printf("elif_statememt -> ELIF L_CURLY statements R_CURLY\n");


single_comment : COMMENT %prec VALID_CHAR
		{
		//printf("// %s\n", $1);
			};

//printf("single_comment -> COMMENT VALID_CHAR\n");
		

%%

