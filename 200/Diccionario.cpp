#include "Diccionario.h"

int DicPaginas::contadorPaginas(){
	return tabla.getNumElem();
}

void DicPaginas::insertarPagina(Pagina nueva){
	tabla.insertar(nueva);
}

Pagina * DicPaginas::consultar(string URL){
        return tabla.consultar(URL);
}

