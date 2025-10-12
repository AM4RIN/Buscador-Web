#ifndef INTERPRETE_H
#define INTERPRETE_H
#include "Diccionario.h"

class DicPaginas;

string normalizar(string cadena);
void Interprete (string comando, DicPaginas &dic);
void INSERTAR (DicPaginas &dic);
void BUSCAR_URL (DicPaginas &dic);
void BUSCAR_PAL (DicPaginas &dic);
void BUSCAR_AND ();
void BUSCAR_OR ();
void AUTOCOMP();
void SALIR();

#endif
