parser: main.lex
	bison -v -d --file-prefix=y TurtleC.y
	flex main.lex
	gcc -O3 lex.yy.c -o parser.elf -lfl
	./parser.elf CORRECT_ELEMENTS.trt > CORRECT_OUTPUT.txt
	./parser.elf fib.trt > fibonnaci.txt
	./parser.elf errorTest1_ExtraParenthesis.trt > error_output1.txt
	./parser.elf errorTest2_ExtraSemicolon.trt > error_output2.txt
	./parser.elf errorTest3_danglingElse.trt > error_output3.txt

clean:
	rm -f lex.yy.c y.tab.* y.output *.o parser.elf error_output1.txt error_output2.txt error_output3.txt CORRECT_OUTPUT.txt