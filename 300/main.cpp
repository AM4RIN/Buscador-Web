#include "Interprete.h"

int main(void){
    string comando;
    DicPaginas dic;

    while(cin>>comando){
        Interprete(comando, dic);
		if(comando == "s") 
			break;
    }
    return 0;
}
