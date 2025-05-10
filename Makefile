all: exec
main.o: fightersmain1.c fighters1.h
	gcc -c fightersmain1.c -o main.o
	
fighters1.o: fighters1.c fighters1.h
	gcc -c fighters1.c -o fighters1.o
	
exec: main.o fighters1.o 
	gcc main.o fighters1.o -o exec
clean:
	rm -f *.o
	rm exec
