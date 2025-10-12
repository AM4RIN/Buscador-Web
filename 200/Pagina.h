#ifndef _PAGINA_H
#define _PAGINA_H

#include <list>
#include <iostream>
#include <string>

using namespace std;

class DicPaginas; // Definicion anticipada para que no de error

class Pagina {
private:
        //atributos
        string URL;
        string titulo;
        int relevancia;

public:
        //funcionalidad
        void escribir(DicPaginas& dic);
        void leer();

	//getters/setters
        string getURL();
        string getTitulo();
        int getRelevancia();

        void setURL(string nuevaURL);
        void setTitulo(string nuevoTitulo);
        void setRelevancia(int nuevaRelevancia);
};
#endif
