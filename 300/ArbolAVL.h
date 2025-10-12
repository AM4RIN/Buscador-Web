#ifndef _ARBOL_H
#define _ARBOL_H

#include "NodoAVL.h"
#include "Pagina.h"

class ArbolAVL{
private:
	NodoAVL * raiz;
	int nElem;
	int altura(NodoAVL * nodo);
	void insertar (NodoAVL *&A, string palabra, Pagina* pag);
	void insertarPorIzquierda(NodoAVL *&A, string palabra, Pagina *pag);
	void insertarPorDerecha(NodoAVL *&A, string palabra, Pagina *pag);
    void insertaPagina(NodoAVL *&A, Pagina *pag);
    void insertarAux(NodoAVL *&A, Pagina *pag);
	void RDI(NodoAVL *& A);
    void RSI(NodoAVL *& A);
    void RSD(NodoAVL *& A);
    void RDD(NodoAVL *& A);
public:
    ArbolAVL();
    ~ArbolAVL();	
    void insertarRaiz (string palabra, Pagina *pag);
    list<Pagina*> buscar (string palabra); 
    int numElem (void);
};

#endif
