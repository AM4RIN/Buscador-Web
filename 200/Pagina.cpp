#include "Pagina.h"
#include "Diccionario.h"
#include "interprete.h"
// Implementacion métodos leer y escribir de Pagina
void Pagina::leer(){
        int relevanciaLeida;
        std::cin>>relevanciaLeida;
        setRelevancia(relevanciaLeida); // Lee y guarda relevancia
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
        cout <<dic.contadorPaginas()<<". "<<URL<<", "<<titulo<<", Rel. "<<relevancia<<endl;
}


// Implementacion getters/setters de Pagina
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
