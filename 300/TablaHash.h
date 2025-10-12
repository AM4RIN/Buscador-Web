#ifndef _TABLAHASH_H
#define _TABLAHASH_H

#include "Pagina.h"

class TablaHash {
  private:
    list<Pagina> *tablaHash;
    int capacidad;
    int numElem;

    unsigned int hash(string url);

public:
    TablaHash();
    TablaHash(int cap);
    ~TablaHash();
    void insertar(Pagina nueva);
    void redimensionar();
    Pagina* consultar(string url);
    int getNumElem();
};
#endif
