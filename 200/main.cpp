#include "interprete.h"
using namespace std;

int main(void){
	string comando;
	DicPaginas dic;

	while(cin>>comando){
		Interprete(comando, dic);

	}
	return 0;
}


