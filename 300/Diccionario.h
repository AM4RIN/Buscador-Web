#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include "TablaHash.h"
#include "ArbolAVL.h"

class DicPaginas {
private:
        TablaHash tabla;
        ArbolAVL arbol;
        
public:
		void insertarPagina(Pagina nueva);
		Pagina* consultar (string URL);
        int contadorPaginas ();
        
        void insertarPalabra(string palabra, Pagina *pag);
		list<Pagina*> buscarPalabra(string palabra);
};

#endif
