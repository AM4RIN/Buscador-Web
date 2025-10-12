#ifndef _PAGINA_H
#define _PAGINA_H

#include <list>
#include <iostream>
#include <string>

using namespace std;

class DicPaginas;

class Pagina {
private:
        string URL;
        string titulo;
        int relevancia;

public:
        
        void escribir(DicPaginas& dic);
        string leer();
        void escribirNum(DicPaginas & dic, int indice);

        string getURL();
        string getTitulo();
        int getRelevancia();

        void setURL(string nuevaURL);
        void setTitulo(string nuevoTitulo);
        void setRelevancia(int nuevaRelevancia);
};
#endif
