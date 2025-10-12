#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include "TablaHash.h"
using namespace std;

class DicPaginas {
private:
        //atributos
        TablaHash tabla;
public:

        //metodos (el constructor no es necesario)
        void insertarPagina(Pagina nueva);
        Pagina* consultar (string URL);
        int contadorPaginas ();

};
#endif
