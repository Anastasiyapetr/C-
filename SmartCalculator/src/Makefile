.PHONY: all rebuild test smartCalc leak clean gcov_report remove_smartCalc linter linteri build install unistall dvi dist

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TESTFILE = unit-test/test
GCOV_FLAG = --coverage
SOURCES = credit_calculator.c smartCalc.c
TARGET = smartCalc
OBJECT = SmartCalc
STYLE = clang-format
PREFIX = SmartCalc_app

LIBS_FOR_CHECK_PCKG =
D_OS =
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	LIBS_FOR_CHECK_PCKG = -lcheck -lsubunit -lm -lpthread -lrt
	D_OS = -D __My_Linux__
else
	LIBS_FOR_CHECK_PCKG = -lcheck -lm -lpthread
	D_OS = -D __My_APPLE__
endif

all: $(TARGET)

rebuild: clean all

test: clean $(TARGET)
	cd ./backend && $(CC) $(CFLAGS) -o a.out ../$(TESTFILE).c $(TARGET).a $(LIBS_FOR_CHECK_PCKG) $(GCOV_FLAG) && ./a.out

smartCalc: remove_smartCalc
	cd ./backend && $(CC) -c $(CFLAGS) $(SOURCES) && ar rc $(TARGET).a *.o && ranlib $(TARGET).a
	rm -rf ./backend/*.o

leak:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out 

clean:
	cd ./backend && rm -rf *.a *.o *.out *.gcno *.gcda
	cd ./unit-test && rm -f  *.info *.gcno *.gcda test
	rm -rf report
	rm -rf *.gch *.gz
	rm -rf build/
	rm -rf $(OBJECT)_app
	rm -rf Documents/html
	rm -rf Documents/latex

gcov_report: clean
	$(CC) $(CFLAGS) $(GCOV_FLAG) backend/*.c unit-test/*.c $(LIBS_FOR_CHECK_PCKG) -o $(TESTFILE)
	./$(TESTFILE)
	lcov -t "test" -o $(TESTFILE).info -c -d .
	genhtml -o report $(TESTFILE).info
	
remove_smartCalc:
	cd backend && rm -f *.a *.o

linter:
	$(STYLE) -n -style=Google backend/*.c backend/*.h SmartCalc_V1.0/*.cpp SmartCalc_V1.0/*.h

linteri:
	$(STYLE) -i -style=Google backend/*.c backend/*.h SmartCalc_V1.0/*.cpp SmartCalc_V1.0/*.h

build: clean
	mkdir build
	cd build; qmake6 ../SmartCalc_V1.0/Smart_Calc.pro
	cd build; make
	
install: 
	make build
	mkdir $(PREFIX)
	mv build/SmartCalc $(PREFIX)
	cd $(PREFIX); ./$(OBJECT)

uninstall:
	rm -rf $(PREFIX)
	rm -rf build

dist:
	cd Documents; doxygen Doxyfile
	tar -czf SmartCalc.install.tar.gz SmartCalc_V1.0 Documents/html Makefile backend unit-test

dvi:
	cd Documents; doxygen Doxyfile
	Documents/html/./index.html