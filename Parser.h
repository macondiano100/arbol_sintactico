//
// Created by Antonio on 15/10/2016.
//

#ifndef ARBOL_SINTACTICO_PARSER_H
#define ARBOL_SINTACTICO_PARSER_H

#include <string>
#include "lexico/lexico.h"
#include "Nodo_Sintactico.h"
using puntero_nodo=Nodo_Sintactico::puntero ;
class Parser {
    using Tipo_Token=Token::Tipo_Token ;
    Lexico lexico;
    puntero_nodo S();
    puntero_nodo A();
    puntero_nodo E();
    puntero_nodo M();
    puntero_nodo F();
    bool comprueba(Token::Tipo_Token);
    Token token_actual;
    puntero_nodo arbol;
public:
    Parser(std::istream &archivo):lexico(archivo){lexico++;}
    bool analiza();

    void xml(std::ostream &out);
};


#endif //ARBOL_SINTACTICO_PARSER_H
