#include "Pagina.h"
#include "Diccionario.h"
#include "Interprete.h"

string Pagina::leer(){
        int relevanciaLeida;
        std::cin>>relevanciaLeida;
        setRelevancia(relevanciaLeida);
        cin.ignore();

        string urlLeida;
        urlLeida=normalizar(urlLeida);
        std::getline(cin, urlLeida); 
        setURL(urlLeida);

        string tituloLeido;
        std::getline(cin, tituloLeido);
        setTitulo(tituloLeido);
        return getURL();
}

void Pagina::escribir(DicPaginas & dic){
        cout <<dic.contadorPaginas()<<". "<<getURL()<<", "<<getTitulo()<<", Rel. "<<getRelevancia()<<endl;
}


void Pagina::escribirNum(DicPaginas & dic, int indice){
        cout <<indice<<". "<<getURL()<<", "<<getTitulo()<<", Rel. "<<getRelevancia()<<endl;
}

string Pagina::getURL(){
        return URL;
}

string Pagina::getTitulo(){
        return titulo;
}

int Pagina::getRelevancia(){
        return relevancia;
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
