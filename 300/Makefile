a.out: main.o Interprete.o Pagina.o Diccionario.o TablaHash.o NodoAVL.o ArbolAVL.o
	g++ main.o Interprete.o Pagina.o Diccionario.o TablaHash.o NodoAVL.o ArbolAVL.o

Interprete.o: Interprete.cpp Interprete.h Diccionario.h Pagina.h
	g++ -c Interprete.cpp

Diccionario.o: Diccionario.cpp Diccionario.h TablaHash.h ArbolAVL.h
	g++ -c Diccionario.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Pagina.h
	g++ -c TablaHash.cpp

Pagina.o: Pagina.cpp Pagina.h
	g++ -c Pagina.cpp

NodoAVL.o: NodoAVL.cpp NodoAVL.h Pagina.h
	g++ -c NodoAVL.cpp

ArbolAVL.o: ArbolAVL.cpp ArbolAVL.h NodoAVL.h
	g++ -c ArbolAVL.cpp

main.o: main.cpp Interprete.h
	g++ -c main.cpp


clean:
	rm -f *.o a.out

.PHONY: clean
