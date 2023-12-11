flex main.lex
bison -v  -d --file-prefix=y TurtleC.y
gcc lex.yy.c -o parser.elf -lfl -std=c99 -w



# ./parser.elf < errorNoMainFunction.trt > errorNoMainFunction.mil
# ./mil_run errorNoMainFunction.mil


./parser.elf < errorDeclaringArraySizeLessThan0.trt > errorDeclaringArraySizeLessThan0.mil
./mil_run errorDeclaringArraySizeLessThan0.mil


# ./parser.elf < errorRedecInSameScope.trt > errorRedecInSameScope.mil
# ./mil_run errorRedecInSameScope.mil


# ./parser.elf < errorUsingVariableWithoutDeclaring.trt > errorUsingVariableWithoutDeclaring.mil
# ./mil_run errorUsingVariableWithoutDeclaring.mil

rm -f lex.yy.c y.tab.* y.output *.o parser.elf 