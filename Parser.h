//
// Created by Antonio on 15/10/2016.
//

#ifndef ARBOL_SINTACTICO_PARSER_H
#define ARBOL_SINTACTICO_PARSER_H

#include "lexico/lexico.h"
#include "Nodo_Sintactico.h"

class Parser {
    using Tipo_Token=Token::Tipo_Token ;
    Lexico lexico;
    Nodo_Sintactico * S();
    Nodo_Sintactico * A();
    Nodo_Sintactico * E();
    Nodo_Sintactico * M();
    Nodo_Sintactico * F();
    bool comprueba(Token::Tipo_Token);
    Token token_actual;
public:
    Parser(std::istream &archivo):lexico(archivo){lexico++;}
    bool analiza();
};


#endif //ARBOL_SINTACTICO_PARSER_H
