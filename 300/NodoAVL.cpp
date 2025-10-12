#include "NodoAVL.h"
#include <list>
NodoAVL::NodoAVL(){
	this->altura = 0;
	this->izq = NULL;
	this->der = NULL;
}

// DESTRUCTOR
NodoAVL::~NodoAVL() {
    delete izq;
    delete der;
}
