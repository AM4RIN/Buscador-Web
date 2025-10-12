#include "Diccionario.h"

int DicPaginas::contadorPaginas(){
	return tabla.getNumElem();
}

void DicPaginas::insertarPagina(Pagina nueva){
	tabla.insertar(nueva);
}

void DicPaginas::insertarPalabra(string palabra, Pagina* nueva){
	arbol.insertarRaiz(palabra, nueva);
}

Pagina * DicPaginas::consultar(string URL){
    return tabla.consultar(URL);
}

list<Pagina*>  DicPaginas::buscarPalabra(string palabra){
	return arbol.buscar(palabra); 
}

