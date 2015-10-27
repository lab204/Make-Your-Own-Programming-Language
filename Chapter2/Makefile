CC = gcc
CCFLAGS = -g -W -Wall

FLEX = flex
FLEX_OPTS = -Pcalc

BISON = bison
BISON_OPTS = -t -pcalc

OBJS = Absyn.o Lexer.o Parser.o Printer.o

.PHONY: clean distclean

all: Testcalc

clean:
	rm -f *.o Testcalc calc.aux calc.log calc.pdf calc.dvi calc.ps calc

distclean: clean
	rm -f Absyn.h Absyn.c Test.c Parser.c Parser.h Lexer.c Skeleton.c Skeleton.h Printer.c Printer.h Makefile calc.l calc.y calc.tex 

Testcalc: ${OBJS} Test.o
	@echo "Linking Testcalc..."
	${CC} ${CCFLAGS} ${OBJS} Test.o -o Testcalc

Absyn.o: Absyn.c Absyn.h
	${CC} ${CCFLAGS} -c Absyn.c

Lexer.c: calc.l
	${FLEX} ${FLEX_OPTS} -oLexer.c calc.l

Parser.c: calc.y
	${BISON} ${BISON_OPTS} calc.y -o Parser.c

Lexer.o: Lexer.c Parser.h
	${CC} ${CCFLAGS} -c Lexer.c 

Parser.o: Parser.c Absyn.h
	${CC} ${CCFLAGS} -c Parser.c

Printer.o: Printer.c Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Printer.c

Test.o: Test.c Parser.h Printer.h Absyn.h
	${CC} ${CCFLAGS} -c Test.c

