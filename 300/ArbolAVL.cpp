#include "ArbolAVL.h"

ArbolAVL::ArbolAVL(){
	this->raiz = NULL;
	this->nElem = 0;
}

ArbolAVL::~ArbolAVL(){
	delete raiz;
}

void ArbolAVL::insertarRaiz (string palabra, Pagina *pag){
	insertar(raiz, palabra, pag);
}

list<Pagina*> ArbolAVL::buscar(string palabra) {
	NodoAVL* actual = raiz; 
    while (actual != NULL) { 
        if (palabra == actual->palabra) { 
            return actual->paginas;
        } else if (palabra < actual->palabra) {
            actual = actual->izq;
        } else { 
            actual = actual->der;
        }
    }
    
    return list<Pagina*>(); 
}

int ArbolAVL::numElem (void) {
	return this->nElem;
} 

int ArbolAVL::altura(NodoAVL * nodo){
	if(nodo == NULL)
		return -1;
	else
		return nodo->altura;
}

void ArbolAVL::insertar (NodoAVL *&A, string palabra, Pagina *pag){

	if (A == NULL){
		A = new NodoAVL();
		A->palabra = palabra;
		A->paginas.push_back(pag); 
		nElem++;
	}else if(palabra < A->palabra){ 
		insertarPorIzquierda(A, palabra, pag);
	}else if (palabra > A->palabra){ 
		insertarPorDerecha(A, palabra, pag);
	}else if (pag != NULL){ 
			insertaPagina(A, pag); 
	}
}

void ArbolAVL::insertarPorIzquierda(NodoAVL *&A, string palabra, Pagina *pag){
	insertar(A->izq, palabra, pag);
	
	if(altura(A->izq) - altura(A->der) > 1){
		if(palabra < A->izq->palabra)
			RSI(A);
		else
			RDI(A);
	}else{
		A->altura = 1 + max(altura(A->izq), altura(A->der));
	}	
}



void ArbolAVL::insertarPorDerecha(NodoAVL *&A, string palabra, Pagina *pag) {
    insertar(A->der, palabra, pag);
    
    if (altura(A->der) - altura(A->izq) > 1) {
        if (palabra > A->der->palabra)
            RSD(A);
        else                      
            RDD(A);
    } else {
        A->altura = 1 + max(altura(A->izq), altura(A->der));
    }
}



void ArbolAVL::insertaPagina(NodoAVL *&A, Pagina *pag){
		list<Pagina*>::iterator iterador = A->paginas.begin();
		while (iterador != A->paginas.end() && (*iterador != NULL) && (*iterador)->getURL() != pag->getURL()) {
			iterador++; 
		}
		
		if (iterador == A->paginas.end() ) { 
			insertarAux(A, pag);
		}
}


void ArbolAVL::insertarAux (NodoAVL *&A, Pagina *pag) {
		list<Pagina*>::iterator iterador = A->paginas.begin();
		
		while (iterador != A->paginas.end() && (*iterador != NULL) && (*iterador)->getRelevancia() > pag->getRelevancia()) {
			iterador++;
		}


		if (iterador != A->paginas.end() && (*iterador != NULL) && (*iterador)->getRelevancia() == pag->getRelevancia()) {
			while (iterador != A->paginas.end() && (*iterador != NULL) && (*iterador)->getRelevancia() == pag->getRelevancia() && (*iterador)->getURL() < pag->getURL()) {
				iterador++;
			}
		}

		A->paginas.insert(iterador, pag);

}

void ArbolAVL::RSI(NodoAVL *& A){
    NodoAVL* B = A->izq;
    A->izq = B->der;
    B->der = A;
    A->altura = 1 + max(altura(A->izq), altura(A->der));
    B->altura = 1 + max(altura(B->izq), A->altura);
    A = B;
}

void ArbolAVL::RSD(NodoAVL*& A){
    NodoAVL* B = A->der;
    A->der = B->izq;
    B->izq = A;
    A->altura = 1 + max(altura(A->izq), altura(A->der));
    B->altura = 1 + max(altura(B->der), A->altura);
    A = B;
}

void ArbolAVL::RDI(NodoAVL*& A){
	RSD(A->izq);
    RSI(A);
}

void ArbolAVL::RDD(NodoAVL*& A){
    RSI(A->der);
    RSD(A);
}
