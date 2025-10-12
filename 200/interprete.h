#ifndef INTERPRETE_H
#define INTERPRETE_H
#include "Diccionario.h"

using namespace std;
class DicPaginas;
extern DicPaginas dic;

void SeparaPalabras(string entrada, int &contador);
string normalizar(string cadena);
void Interprete (string comando, DicPaginas &dic);
void INSERTAR (DicPaginas &dic);
void BUSCAR_URL (DicPaginas &dic);
void BUSCAR_PAL ();
void BUSCAR_AND ();
void BUSCAR_OR ();
void AUTOCOMP();
void SALIR();
extern int contador;



#endif
