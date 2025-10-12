#include "PaginaYDiccionario.h"
#include "interprete.h"


// Implementacion métodos leer y escribir de Pagina
void Pagina::leer(){	
	int relevanciaLeida;
	std::cin>>relevanciaLeida;
	setRelevancia(relevanciaLeida); // Lee relevancia y la guarda en atributo relevancia (set)
	cin.ignore(); 
	
	string urlLeida;
	urlLeida=normalizar(urlLeida);
	std::getline(cin, urlLeida); // Lee URL
	setURL(urlLeida);
	
	
	string tituloLeido;
	std::getline(cin, tituloLeido); // Lee titulo
	setTitulo(tituloLeido);
	
}

void Pagina::escribir(DicPaginas & dic){
	cout <<dic.contadorPaginas()<<". "<<getURL()<<", "<<getTitulo()<<", Rel. "<<getRelevancia()<<endl;
}



// Implementacion getters/setters de Pagina
string Pagina::getURL(){
	string copia = URL;
	return copia;	
}

string Pagina::getTitulo(){
	string copia = titulo;
	return copia;	
}

int Pagina::getRelevancia(){
	int copia = relevancia;
	return copia;	
}
	
void Pagina::setTitulo(string nuevoTitulo){
	titulo = nuevoTitulo;
}

void Pagina::setRelevancia(int nuevaRelevancia){
	relevancia = nuevaRelevancia;
}

void Pagina::setURL(string nuevaURL){
	URL = nuevaURL;
}

// Implementacion constructor de Pagina
DicPaginas::DicPaginas () {
contador= 0;
}


/* Se leerán los datos de la página, y después se almacenará en el diccionario.
 *  Si ya existe esa URL, se debe actualizar el título y la relevancia.*/
 
int DicPaginas::contadorPaginas()
		{return contador;}
 
void DicPaginas::insertarPagina(Pagina nueva){
	list<Pagina>::iterator iteradorDiccionario; // Defino iterador que va pasando por cada pagina
	
	iteradorDiccionario = paginas.begin(); // accedo a la primera pagina del diccionario
	
	// Mientras no salgo del diccionario y la url es menor (para insertar ordenadas por url)
	while(iteradorDiccionario != paginas.end() && (*iteradorDiccionario).getURL() < nueva.getURL()){ 
		iteradorDiccionario++; // Avanzo
	}
	
	// Si he llegado al final o la url no es la que busco
	if(iteradorDiccionario == paginas.end() || (*iteradorDiccionario).getURL() != nueva.getURL()){
		paginas.insert(iteradorDiccionario, nueva); // Inserto nueva pagina
		contador++; // Aumento contador
	}	
	else // Si entro en el else quiere decir que ya existia la pagina y estoy en ella
	{
		(*iteradorDiccionario).setTitulo(nueva.getTitulo()); // actualizo titulo
		(*iteradorDiccionario).setRelevancia(nueva.getRelevancia()); // actualizo relevancia

	} 
	

}

Pagina * DicPaginas::consultar(string url){
	Pagina * p = NULL ; 
	list<Pagina>::iterator iteradorDiccionario; // Defino iterador que va pasando por cada pagina
	iteradorDiccionario= paginas.begin();
	
		// Mientras no salgo del diccionario y no encuentra URL
	while(iteradorDiccionario != paginas.end() && (*iteradorDiccionario).getURL() != url){ 
	iteradorDiccionario++; // Avanzo
	
	}
	
	if(iteradorDiccionario != paginas.end()){ // Si lo he encontrado (no he llegado al final)
		p=&(*iteradorDiccionario); // Asigno puntero a pagina
		
	}

	return p;
}
