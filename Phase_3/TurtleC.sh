flex main.lex
bison -v  -d --file-prefix=y TurtleC.y
gcc lex.yy.c -o parser.elf -lfl -std=c99 -w

# ./parser.elf < testingFunctions.trt > testingFunctions.mil
# ./mil_run testingFunctions.mil

# ./parser.elf < testingArrays.trt > testingArrays.mil
# ./mil_run testingArrays.mil


# ./parser.elf < testingVariableDeclaration.trt > testingVariableDeclaration.mil
# ./mil_run testingVariableDeclaration.mil

# ./parser.elf < testingCopy.trt > testingCopy.mil
# ./mil_run testingCopy.mil


# ./parser.elf < ./tests/errors/noMainFunction.trt > ./tests/errors/noMainFunction.mil





# ./parser.elf < while.trt > while.mil
# ./mil_run while.mil

# ./parser.elf < branchStatements.trt > branch.mil
# ./mil_run branch.mil

# ./parser.elf < fib.trt > fib.mil
# ./mil_run fib.mil

./parser.elf < bub.trt > bub.mil
./mil_run bub.mil

rm -f lex.yy.c y.tab.* y.output *.o parser.elf 