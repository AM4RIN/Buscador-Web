#include "TablaHash.h"
const int CAPACIDAD_INICIAL = 100001;

//METODOS PRIVADOS AUXILIARES

unsigned int TablaHash::hash(string url){
        unsigned int valorHash = 0;
        int suma = 17;
       for (int i = 0; i < url.length(); i++) { // quitamos http: (0-4) que es comun en todos
                valorHash = (valorHash * suma ^ (unsigned char) url[i])% capacidad;
        }
        return valorHash;
}


// Redimensionar la tabla
void TablaHash::redimensionar() {

	int capacidadAntigua = capacidad; //guardo capacidad para recorrer tabla
	capacidad *= 2; // establezco nueva capacidad

	TablaHash nuevaTabla(capacidad); // creo tabla +grande
	for(int i = 0; i < capacidadAntigua; i++){ //Recorriendo tabla antigua
		list<Pagina>::iterator it = tablaHash[i].begin(); // Pos. inicial de cada lista
		while(it != tablaHash[i].end()){ // mientras queden paginas en esa lista (cubeta)
			nuevaTabla.insertar(*it); // inserto en la nueva las paginas
			it++; // Avanzo a siguiente posicion de la lista
		}
	}
	delete[] tablaHash; // libero tabla antigua
	tablaHash = nuevaTabla.tablaHash; // reasigno nueva tabla
	nuevaTabla.tablaHash = NULL;
	/* la nueva tabla, al ser variable local, se libera
	* automaticamente ya que está definido su destructor y como su puntero apunta tambien
	* a la antigua, tambien liberariamos la antigua (cosa que no queremos) por lo que
	* apuntamos a null para que no se libere la antigua
	*/
}

//PARTE PUBLICA

//Constructor
TablaHash::TablaHash(){
        capacidad = CAPACIDAD_INICIAL;
        tablaHash = new list<Pagina>[capacidad]; // tabla de cubetas de paginas
        numElem = 0;
}

TablaHash::TablaHash(int cap){
        capacidad = cap;
        tablaHash = new list<Pagina>[capacidad]; // tabla de cubetas de paginas
        numElem = 0;
}

//Destructor
TablaHash::~TablaHash(){
        delete[] tablaHash;
}

// Inserta una página en la tabla de dispersión
void TablaHash::insertar(Pagina nueva) {

	// Si n/B es mayor que 2 hago tabla mas grande
        if ( (double) numElem / capacidad > 2){
                redimensionar();
        }

	int posicion = hash(nueva.getURL()); // Calculo posicion de insercion

	list<Pagina>::iterator iterador = tablaHash[posicion].begin(); // iterador que va pasando por cada pagina

        // Mientras no salgo del diccionario y la url es menor (para insertar ordenadas por url)
        while(iterador != tablaHash[posicion].end() && iterador->getURL() < nueva.getURL()){
                iterador++; // Avanzo
        }

        // Si he llegado al final o la url no es la que busco
        if(iterador == tablaHash[posicion].end() || iterador->getURL() != nueva.getURL()){
                tablaHash[posicion].insert(iterador, nueva); // Inserto nueva pagina
                numElem++; // Aumento contador de paginas
        }
        else // Si entro en el else quiere decir que ya existia la pagina y estoy en ella
        {
                iterador->setTitulo(nueva.getTitulo()); // actualizo titulo
                iterador->setRelevancia(nueva.getRelevancia()); // actualizo relevancia

        }

}

// Devuelve puntero a Pagina que tenga esa URL
Pagina* TablaHash::consultar(string url){
    Pagina* p = NULL; //Inicializo valor de retorno
    int posicion = hash(url); // Calculo posicion a consultar de tabla
    // primera posicion de la lista en la posicion calculada de la tabla
        list<Pagina>::iterator iterador = tablaHash[posicion].begin();

	while(iterador != tablaHash[posicion].end() && iterador->getURL() < url){
		iterador++; // Avanzo
	}

   	if(iterador != tablaHash[posicion].end() && iterador->getURL() == url){ // Si lo he encontrado (no he llegado al final)
		p=&(*iterador); // Asigno puntero a pagina

	}

	return p;
}


// Devuelve el número total de elementos en la tabla de dispersión
int TablaHash::getNumElem(){
        return numElem;
}
