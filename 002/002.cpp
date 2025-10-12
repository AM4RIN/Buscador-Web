/*
 * Algoritmos y Estructuras de Datos
 * 
 * Sesión 8-10-24
 * 
 * IMPORTANTE:
 * Se puede usar funciones de librerías especificas (mayor eficiencia) (tolower/toupper)
 * Las tildes, los caracteres especiales utilizan un byte de 'control' (C3)
 * Al leer la entrada si el 1er byte es un C3 se hace un análisis de casos para normalizarlo
 * g++ -Wall para confirmar que no produce warnigns 
 * */

#include <iostream>
#include <string>
#include <cctype>

using namespace std; 

void SeparaPalabras(string entrada, int& contador);
string normalizar(string cadena);

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
		cout<<contador<<". "<<entrada<<" -> "<<normalizar(entrada)<<endl;
		contador++;
	}
}

//2) Función: normalizar texto
string normalizar(string cadena){
	string salida = "";
	for(unsigned i = 0; i<cadena.length(); i++){
		if (cadena[i] >= int('A') && cadena[i] <= int('Z')){
			salida.push_back(tolower(cadena[i]));
		}else if(cadena[i] == static_cast<char>(0xC3)){ //si es caracter no ASCII
			if (i + 1 < cadena.length()){
			
				switch(cadena[i+1]){
					case static_cast<char>(0xA1): //á
					case static_cast<char>(0x81): //Á
						salida.push_back('a');
						i++;
						break;
				
					case static_cast<char>(0xA9): //é
					case static_cast<char>(0x89): //É
						salida.push_back('e');
						i++;
						break;
				
					case static_cast<char>(0xAD): //í
					case static_cast<char>(0x8D): //Í
						salida.push_back('i');
						i++;
						break;
				
					case static_cast<char>(0xB3): //ó
					case static_cast<char>(0x93): //Ó
						salida.push_back('o');
						i++;
						break;
				
					case static_cast<char>(0xBA): //ú
					case static_cast<char>(0x9A): //Ú
					case static_cast<char>(0xBC): 
					case static_cast<char>(0x9C):
						salida.push_back('u');
						i++;
						break;
				
					case static_cast<char>(0x91): //Ñ
						salida.push_back(static_cast<char>(0xC3));
						salida.push_back(static_cast<char>(0xB1));
						i++;
						break;
					
					default: //Otro caracter
						salida.push_back(cadena[i]);
						break;
			
					}
				
				} else {
					salida.push_back(cadena[i]); // Agregar el byte actual si no hay siguiente
				}
		}else{
			salida.push_back(cadena[i]);
		}
	}
	return salida;
}



	

