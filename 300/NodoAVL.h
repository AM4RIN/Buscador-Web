#ifndef _NODO_H
#define _NODO_H
#include "Pagina.h"

class ArbolAVL;

class NodoAVL{
	
friend class ArbolAVL;

private:
	string palabra;
	list<Pagina*> paginas;  
	int altura;
	NodoAVL* izq;
	NodoAVL* der;
public:
	NodoAVL();
	~NodoAVL();
};
#endif
