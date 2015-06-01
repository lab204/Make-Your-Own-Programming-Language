#
# cal
#

cal: y.tab.o lex.yy.o
	gcc $^ -o $@


y.tab.o: y.tab.c
	gcc -c $<

lex.yy.o: lex.yy.c y.tab.h
	gcc -c $<

lex.yy.c: cal.l
	lex cal.l

y.tab.c: cal.y
	yacc -d -y cal.y

clean:
	rm lex.yy.c
	rm y.tab.c
	rm y.tab.h
	rm cal