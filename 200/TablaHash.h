#ifndef _TABLAHASH_H
#define _TABLAHASH_H

#include "Pagina.h"
using namespace std;

// Capacidad inicial de la tabla de dispersión
extern const int CAPACIDAD_INICIAL;

class TablaHash {
  private:
    //Atributos
    list<Pagina> *tablaHash;   // Array de listas para colisiones
    int capacidad;            // Capacidad actual de la tabla (B)
    int numElem;             // Número de pags en la tabla (n)

    //Metodos privados auxiliares
    unsigned int hash(string url);
    void redimensionar();

public:
    TablaHash(); //Constructor
    TablaHash(int cap); //Constructor
    ~TablaHash(); //Destructor
    void insertar(Pagina nueva);
    Pagina* consultar(string url);
    int getNumElem(); //Antiguo contador
};
#endif
