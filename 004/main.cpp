#include <iostream>
#include "interprete.h"
#include "PaginaYDiccionario.h"
using namespace std;
int main(void){
	string comando;
	DicPaginas dic;
	
	while(cin>>comando){
		Interprete(comando, dic);
		if(comando=="s")
			break;
		
	}
	
	//SESION 8
	//Pagina miPagina;
	
	
	
	return 0;
}


