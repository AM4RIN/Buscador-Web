a.out: main.o interprete.o PaginaYDiccionario.o
	g++ main.o interprete.o PaginaYDiccionario.o

interprete.o: interprete.cpp interprete.h PaginaYDiccionario.h
	g++ -c interprete.cpp
	
PaginaYDiccionario.o: PaginaYDiccionario.cpp PaginaYDiccionario.h interprete.h
	g++ -c PaginaYDiccionario.cpp
	
main.o: main.cpp PaginaYDiccionario.h interprete.h
	g++ -c main.cpp
