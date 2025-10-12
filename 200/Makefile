a.out: main.o interprete.o Pagina.o Diccionario.o TablaHash.o
	g++ main.o interprete.o Pagina.o Diccionario.o TablaHash.o

interprete.o: interprete.cpp interprete.h Diccionario.h TablaHash.h Pagina.h
	g++ -c interprete.cpp

Diccionario.o: Diccionario.cpp Diccionario.h TablaHash.h Pagina.h
	g++ -c Diccionario.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Pagina.h
	g++ -c TablaHash.cpp

Pagina.o: Pagina.cpp Pagina.h Diccionario.h interprete.h TablaHash.h 
	g++ -c Pagina.cpp

main.o: main.cpp Pagina.h Diccionario.h interprete.h TablaHash.h
	g++ -c main.cpp
