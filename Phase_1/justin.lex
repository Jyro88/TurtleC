%{
#include <stdio.h>
%}
DATA_TYPE [tInt, tString, tDouble, tBool, Void]
DATA_TYPES ,{SPACES}{DATA_TYPE}
COMMENT [~]
NEWLINE [\n]
SPACES [ \t]*

%%
^({COMMENT}.+{NEWLINE}) {printf("Single Comment: %s\n", yytext);}
^(\\~.+~\\) {printf("Multi-line Comment: %s\n", yytext);}
.+:{SPACES}\[({DATA_TYPE}{SPACES}({DATA_TYPES})?)*\]{SPACES}->{SPACES}{DATA_TYPE}({DATA_TYPES})? {
    printf("Function Call: %s\n", yytext);}


%%

int main() {
    yylex();
    return 0;
}


