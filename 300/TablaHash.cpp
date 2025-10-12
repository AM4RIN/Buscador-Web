#include "TablaHash.h"

unsigned int TablaHash::hash(string url){
        unsigned int valorHash = 0;
        int suma =17;
       for (unsigned int i = 0; i < url.length(); i++) { 
                valorHash = (valorHash * suma ^ (unsigned char) url[i])% capacidad;
        }
        return valorHash % capacidad;
}


TablaHash::TablaHash(){
        capacidad = 100001; 
        tablaHash = new list<Pagina>[capacidad];
        numElem = 0;
}

TablaHash::TablaHash(int cap){
        capacidad = cap;
        tablaHash = new list<Pagina>[capacidad];
        numElem = 0;
}


TablaHash::~TablaHash(){
        delete[] tablaHash;
}

void TablaHash::insertar(Pagina nueva) {
	
    if ( (double) numElem / capacidad > 2){
		redimensionar();
    }

	int posicion = hash(nueva.getURL()); 

	list<Pagina>::iterator iterador = tablaHash[posicion].begin(); 

        while(iterador != tablaHash[posicion].end() && iterador->getURL() < nueva.getURL()){
                iterador++;
        }

        if(iterador == tablaHash[posicion].end() || iterador->getURL() != nueva.getURL()){
                tablaHash[posicion].insert(iterador, nueva);
                numElem++; 
        }
        else 
        {
                iterador->setTitulo(nueva.getTitulo()); 
                iterador->setRelevancia(nueva.getRelevancia()); 
        }
        
}


void TablaHash::redimensionar() {

	int capacidadAntigua = capacidad; 
	capacidad *= 2;

	TablaHash nuevaTabla(capacidad);
	for(int i = 0; i < capacidadAntigua; i++){
		list<Pagina>::iterator it = tablaHash[i].begin();
		while(it != tablaHash[i].end()){ 
			nuevaTabla.insertar(*it); 
			it++;
		}
	}
	delete[] tablaHash;
	tablaHash = nuevaTabla.tablaHash;
	nuevaTabla.tablaHash = NULL;
}


Pagina* TablaHash::consultar(string url){
    Pagina* p = NULL; 
    int posicion = hash(url); 
        list<Pagina>::iterator iterador = tablaHash[posicion].begin();

	while(iterador != tablaHash[posicion].end() && iterador->getURL() < url){
		iterador++;
	}

   	if(iterador != tablaHash[posicion].end() && iterador->getURL() == url){
		p=&(*iterador);

	}
	return p;
}

int TablaHash::getNumElem(){
        return numElem;
}
