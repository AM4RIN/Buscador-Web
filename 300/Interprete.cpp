#include <cctype>
#include "Interprete.h"

string normalizar(string cadena){
	string salida = "";
	for(unsigned int i = 0; i<cadena.length(); i++){
		if (cadena[i] >= 'A' && cadena[i] <= 'Z'){
			salida.push_back(tolower(cadena[i]));
		}else if(cadena[i] == char(0xC3)){
			switch(cadena[++i]){
				case char(0xA1): case char(0x81): salida.push_back('a'); break;
				case char(0xA9): case char(0x89): salida.push_back('e'); break;
				case char(0xAD): case char(0x8D): salida.push_back('i'); break;
				case char(0xB3): case char(0x93): salida.push_back('o'); break;
				case char(0xBA): case char(0x9A): case char(0xBC): case char(0x9C):
					salida.push_back('u');
					break;

				case char(0x91): salida.push_back((char) 0XC3); 
						 salida.push_back((char) 0XB1);
						 break;

				default: salida.push_back((char) 0XC3);
					salida.push_back(cadena[i]);
			}

		}else salida.push_back(cadena[i]);
	}
	return salida;
}

void INSERTAR (DicPaginas &dic) {

	Pagina nuevaPag;	
	nuevaPag.leer();	
	dic.insertarPagina(nuevaPag);
	
	string palabra;
	int contadorDePalabras = 0;

	Pagina* ref =  dic.consultar(nuevaPag.getURL()); 
	do{	
		cin >> palabra;
		if (normalizar(palabra) == "findepagina"){
			break;
		}
		dic.insertarPalabra(normalizar(palabra), ref);
		contadorDePalabras++;
	}
	while(true);

	nuevaPag.escribir(dic); 	
	cout << contadorDePalabras << " palabras"<<endl;
}

void BUSCAR_URL (DicPaginas &dic){
	string URL;
	cin.ignore(1); 
	getline(cin, URL);

	int numeroDeURLs = 0;
	Pagina* encontrada= dic.consultar(URL);
	
	cout << "u " << URL << endl;
	if (encontrada != NULL){ 
		numeroDeURLs=1;
		encontrada->escribirNum(dic, numeroDeURLs);
	}
	cout << "Total: "<< numeroDeURLs <<" resultados" << endl;
	
}

void BUSCAR_PAL (DicPaginas &dic){
	string palabra;
	cin >> palabra;
	
	string normalizada = normalizar(palabra);
	list<Pagina*>lista = dic.buscarPalabra(normalizada);
	cout << "b " << normalizada << endl;
	
	int paginasAsociadas = 0;
	
	for(Pagina *pagina : lista) {
		paginasAsociadas++;
		pagina->escribirNum(dic, paginasAsociadas);
	}

	cout<< "Total: " << paginasAsociadas << " resultados" << endl;

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
	if (comando == "i"){
		INSERTAR(dic);
	}else if (comando == "u"){
		BUSCAR_URL(dic);
	}else if (comando == "b"){
		BUSCAR_PAL(dic);
	}else if (comando == "a"){
		BUSCAR_AND();
	}else if (comando == "o"){
		BUSCAR_OR();
	}else if (comando == "p"){
		AUTOCOMP();
	}else if (comando == "s"){
		SALIR();
	}
}

