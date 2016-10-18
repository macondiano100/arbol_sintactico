//
// Created by Antonio on 17/10/2016.
//

#include "Nodo_Sintactico.h"

void Nodo_Sintactico::agrega_hijo(Nodo_Sintactico::puntero&& hijo) {
    hijos.push_back(std::move(hijo));
}
