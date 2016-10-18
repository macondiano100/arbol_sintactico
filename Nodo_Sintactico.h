//
// Created by Antonio on 17/10/2016.
//

#ifndef ARBOL_SINTACTICO_NODO_SINTACTICO_H
#define ARBOL_SINTACTICO_NODO_SINTACTICO_H


#include <string>
#include <vector>
#include <bits/unique_ptr.h>
class Nodo_Sintactico;

class Nodo_Sintactico {
public:
    using puntero=std::unique_ptr<Nodo_Sintactico>;
    std::string etiqueta;
    std::string contenido;
    std::vector<puntero> hijos;
    Nodo_Sintactico(std::string etiqueta,std::string contenido=""):etiqueta(etiqueta),contenido(contenido),hijos(){}

    void agrega_hijo(puntero &&hijo);
};

template <class consumer> void preorden(Nodo_Sintactico *nodo, consumer funcion)
{
    funcion(nodo);
    for(auto&& hijo:nodo->hijos)
    {
        preorden(hijo.get(), funcion);
    }
}
template <class consumer> void posorden(Nodo_Sintactico *nodo, consumer funcion)
{
    for(auto&& hijo:nodo->hijos)
    {
        preorden(hijo.get(), funcion);
    }
    funcion(nodo);
}
template <class consumer,class consumer2> void pre_pos_orden(Nodo_Sintactico *nodo, consumer prefuncion,consumer2 posfuncion)
{
    prefuncion(nodo);
    for(auto&& hijo:nodo->hijos)
    {
        pre_pos_orden(hijo.get(), prefuncion,posfuncion);
    }
    posfuncion(nodo);
}
#endif //ARBOL_SINTACTICO_NODO_SINTACTICO_H
