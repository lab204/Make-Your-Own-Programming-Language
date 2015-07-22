sparrow: y.tab.o lex.yy.o
	g++ -o $@ $^

y.tab.o: y.tab.c y.tab.h
	gcc -o $@ $<

lex.yy.o: lex.yy.c
	gcc -o $@ $<

lex.yy.c: sparrow.l
	lex $<

y.tab.c: sparrow.y
	yacc -d $<

clean:
	rm *.c *.o sparrow
