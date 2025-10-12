/*
 * Algoritmos y Estructuras de Datos
 * 
 * Sesión 15-10-24
 * 
 * IMPORTANTE:
 * Se puede usar funciones de librerías especificas (mayor eficiencia) (tolower/toupper)
 * Las tildes, los caracteres especiales utilizan un byte de 'control' (C3)
 * Al leer la entrada si el 1er byte es un C3 se hace un análisis de casos para normalizarlo
 * g++ -Wall para confirmar que no produce warnigns 
 * 
 * 
hay que ir obligatorio a la semana 7 8 y 10
crear el esqueleto del programa principal de la practica, no funcionalidad de los comandos (ni arboles ni diccionarios)
un procedimiento para cada comando: funcion interprete analisis de casos que en funcion de la primera letra se llama a un procedimiento o a otro.
el texto que pasas primero se normaliza
cuando insertamos contador enlace titulo y relevancia devuelve n palabras de pagina
s es para romper el bucle de la semana pasada (hasta que detecte la letra s)
 * 
 * */

#include <iostream>
#include <string>
#include <cctype>

using namespace std; 

void SeparaPalabras(string entrada, int& contador);
string normalizar(string cadena);


void Interprete (string comando);
void INSERTAR ();
void BUSCAR_URL ();
void BUSCAR_PAL ();
void BUSCAR_AND ();
void BUSCAR_OR ();
void AUTOCOMP();
void SALIR();


int contador = 0;

int main(void){
	string comando;
	
	while(cin>>comando){
		Interprete(comando);
		if(comando=="s")
			break;
		
	}
	
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


void INSERTAR (){
	contador++;
	
	string relevancia;
	cin>>relevancia;
	cin.ignore();
	
	string URL;
	getline(cin, URL);
	
	string titulo;
	getline(cin, titulo);
	
	string palabra;
	int contadorDePalabras = 0;
	
	cin>>palabra;
	string normalizada = normalizar(palabra);
	while(normalizada != "findepagina"){
		contadorDePalabras++;
		cin>>palabra;
		normalizada = normalizar(palabra);
	}
	
	cout << contador<<". "<<URL<<", "<<titulo<<", Rel. "<<relevancia<<endl;
	cout << contadorDePalabras<<" palabras"<<endl;

}

void BUSCAR_URL (){
	
	string URL;
	getline(cin, URL);
	cout << "u" << URL << endl << "Total: 0 resultados" << endl;
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

void Interprete (string comando){
	if (comando == "i")
		INSERTAR();
	else if (comando == "u")
		BUSCAR_URL();
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



/*
 * EJ 004
 * list<T> modificar solo insertar y buscarURL
 * 
 * insertar nueva pagina, buscar pagina por url y devolver n de paginas de url
 * hacer clase pagina
*/

