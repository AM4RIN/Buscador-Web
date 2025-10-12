#include "interprete.h"
#include "PaginaYDiccionario.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//int contador = 0;
//1) Función: línea por cada palabra
void SeparaPalabras(string entrada, int &contador){
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

void INSERTAR (DicPaginas &dic) {
	
	Pagina nuevaPag;
	nuevaPag.leer();
	
	string palabra;
	int contadorDePalabras = 0;
	
	do{
		cin>>palabra;
		string normalizada = normalizar(palabra);
		if (normalizada == "findepagina"){break;}
		contadorDePalabras++;
		}
	while(true);
	
	
	dic.insertarPagina(nuevaPag);
	nuevaPag.escribir(dic);
	cout << contadorDePalabras << " palabras"<<endl;

}


void BUSCAR_URL (DicPaginas &dic){
	
	string URL;
	cin.ignore(1); //Ignora el primer caracter de la cadena que es un espacio
	getline(cin, URL);
	
	int numero = 0; // Inicializo a 0
	Pagina* encontrada= dic.consultar(URL); 
	
	if (encontrada != NULL){ // si la encuentra
		numero=1;
		cout << "u " << URL << endl;
		cout <<numero<<". "<<encontrada->getURL()<<", "<<encontrada->getTitulo()<<", Rel. "<<encontrada->getRelevancia()<<endl;
		cout << "Total: "<< numero <<" resultados" << endl;
	}else{
		cout << "u " << URL << endl;
		cout << "Total: "<< numero <<" resultados" << endl;
	}
		
}

void BUSCAR_PAL (){
	
	string palabra;
	cin >> palabra;
	cout << "b " << normalizar(palabra) << endl<< "Total: 0 resultados" << endl;
}

void BUSCAR_AND (){
	
	string palabras;
	getline(cin, palabras);
	cout << "a" << normalizar(palabras) << endl<< "Total: 0 resultados" << endl;
}

void BUSCAR_OR (){
	
	string palabras;
	getline(cin, palabras);
	cout << "o" << normalizar(palabras) << endl<< "Total: 0 resultados" << endl;
}

void SALIR(){
	cout <<"Saliendo..."<<endl;
}

void AUTOCOMP(){
	string palabra;
	getline(cin, palabra);
	cout << "p" << normalizar(palabra) << endl<< "Total: 0 resultados" << endl;
}

void Interprete (string comando, DicPaginas &dic){
	if (comando == "i")
		INSERTAR(dic);
	else if (comando == "u")
		BUSCAR_URL(dic);
	else if (comando == "b")
		BUSCAR_PAL();
	else if (comando == "a")
		BUSCAR_AND();
	else if (comando == "o")
		BUSCAR_OR();
	else if (comando == "p")
		AUTOCOMP();
	else if (comando == "s")
		SALIR();
}

