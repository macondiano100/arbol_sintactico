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
    Nodo_Sintactico(std::string etiqueta,std::string contenido=""):etiqueta(etiqueta),contenido(),hijos(){}

};


#endif //ARBOL_SINTACTICO_NODO_SINTACTICO_H
