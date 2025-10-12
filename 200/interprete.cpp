#include <cctype>
#include "interprete.h"
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
	for(unsigned int i = 0; i<cadena.length(); i++){
		if (cadena[i] >= 'A' && cadena[i] <= 'Z'){
			salida.push_back(tolower(cadena[i]));
		}else if(cadena[i] == char(0xC3)){ //si es caracter no ASCII
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

	string palabra;
	int contadorDePalabras = 0;

	do{
		cin >> palabra;
		if (normalizar(palabra) == "findepagina"){break;}
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
	if (comando == "i"){
		INSERTAR(dic);
	}else if (comando == "u"){
		BUSCAR_URL(dic);
		cout<<"";
	}else if (comando == "b"){
		BUSCAR_PAL();
		cout<<"";
	}else if (comando == "a"){
		BUSCAR_AND();
		cout<<"";
	}else if (comando == "o"){
		BUSCAR_OR();
		cout<<"";
	}else if (comando == "p"){
		AUTOCOMP();
		cout<<"";
	}else if (comando == "s"){
		SALIR();
	}
}

