all: hw12.o
	gcc	-o hw12 hw12.o
main.o:	hw12.c
	gcc	-c hw12.c
