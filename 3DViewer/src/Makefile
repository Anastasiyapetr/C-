.PHONY: all rebuild viewer clean gcov_report remove_viewer linter linteri build install unistall dvi dist

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
TESTFILE = ../unit-test/test
GCOV_FLAG = --coverage
SOURCES = model.c parcer.c transformations.c
TARGET = viewer
STYLE = clang-format
PREFIX = 3DViewer_app
OBJECT = 3DViewer

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

all: install

rebuild: clean all

viewer: remove_viewer
	cd ./3DViewer/backend && $(CC) -c $(CFLAGS) $(SOURCES) && ar rc $(TARGET).a *.o && ranlib $(TARGET).a
	rm -rf ./3DViewer/backend/*.o

clean:
	cd ./3DViewer/backend && rm -rf *.a *.o *.out *.gcno *.gcda 
	rm -rf *.gch *.gz
	rm -rf build/
	rm -rf $(OBJECT)_app

remove_viewer:
	cd 3DViewer/backend && rm -f *.a *.o

linter:
	$(STYLE) -n -style=Google 3DViewer/backend/*.c 3DViewer/backend/*.h 3DViewer/*.cpp 3DViewer/*.h

linteri:
	$(STYLE) -i -style=Google 3DViewer/backend/*.c 3DViewer/backend/*.h 3DViewer/*.cpp 3DViewer/*.h

build: clean
	mkdir build
	cd build; qmake6 ../3DViewer/3DViewer.pro
	cd build; make
	
install: build
	mkdir $(PREFIX)
	mv build/3DViewer $(PREFIX)
	cd $(PREFIX); ./$(OBJECT)

uninstall:
	rm -rf $(PREFIX)
	rm -rf build

dist:
	tar -czf 3DViewer.install.tar.gz 3DViewer Documents/index.html Makefile QtGifImage examples

dvi:
	./Documents/index.html