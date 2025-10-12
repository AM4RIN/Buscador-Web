#include <iostream>
#include <string>

using namespace std; 

void SeparaPalabras(string entrada, int& contador);

int main(void){
	
	int contador;
	string entrada;

	SeparaPalabras(entrada, contador);

	return 0;
}

//1) Función: línea por cada palabra
void SeparaPalabras(string entrada, int& contador){
	contador = 1;
	while(cin>>entrada){
		cout<<contador<<". "<<entrada<<endl;
		contador++;
	}
}
	

