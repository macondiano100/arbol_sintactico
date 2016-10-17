//
// Created by Antonio on 15/10/2016.
//

#ifndef ARBOL_SINTACTICO_PARSER_H
#define ARBOL_SINTACTICO_PARSER_H

#include "lexico/lexico.h"

class Parser {
    using Tipo_Token=Token::Tipo_Token ;
    Lexico lexico;
    bool S();
    bool A();
    bool E();
    bool M();
    bool F();
    bool comprueba(Token::Tipo_Token);
public:
    Parser(std::istream &archivo):lexico(archivo){lexico++;}
    bool analiza();
};


#endif //ARBOL_SINTACTICO_PARSER_H
