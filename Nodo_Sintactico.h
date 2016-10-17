//
// Created by Antonio on 17/10/2016.
//

#ifndef ARBOL_SINTACTICO_NODO_SINTACTICO_H
#define ARBOL_SINTACTICO_NODO_SINTACTICO_H


#include <string>
#include <vector>
class Nodo_Sintactico {
public:
    std::string etiqueta;
    std::string contenido;
    std::vector<Nodo_Sintactico*> hijos;
    Nodo_Sintactico(std::string etiqueta,std::string contenido=""):etiqueta(etiqueta),contenido(contenido),hijos(){}

};

template <class consumer> void preorden(Nodo_Sintactico *nodo, consumer funcion)
{
    funcion(nodo);
    for(auto&& hijo:nodo->hijos)
    {
        preorden(hijo, funcion);
    }
}
template <class consumer> void posorden(Nodo_Sintactico *nodo, consumer funcion)
{
    for(auto&& hijo:nodo->hijos)
    {
        preorden(hijo, funcion);
    }
    funcion(nodo);
}
template <class consumer,class consumer2> void pre_pos_orden(Nodo_Sintactico *nodo, consumer prefuncion,consumer2 posfuncion)
{
    prefuncion(nodo);
    for(auto&& hijo:nodo->hijos)
    {
        pre_pos_orden(hijo, prefuncion,posfuncion);
    }
    posfuncion(nodo);
}
#endif //ARBOL_SINTACTICO_NODO_SINTACTICO_H
