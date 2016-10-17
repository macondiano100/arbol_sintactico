//
// Created by Antonio on 15/10/2016.
//

#include <iostream>
#include "Parser.h"

bool Parser::comprueba(Tipo_Token t) {
    std::cout<<lexico->lexema()<<std::endl;
    if(lexico->tipo()==t){
        lexico++;
        return true;
    }
    else return false;
}

bool Parser::F() {
    return comprueba(Tipo_Token::ENTERO)|| comprueba(Tipo_Token::IDENTIFICADOR)||
            (comprueba(Tipo_Token::PARENTESIS_ABRE)&&E()&&comprueba(Tipo_Token::PARENTESIS_CIERRA));
}

bool Parser::M() {
    if(F())
    {
        while(comprueba(Tipo_Token::OP_MULT))
        {
            if(!F()) return false;
        }
        return true;
    }
    else return false;
}
bool Parser::A() {
    return comprueba(Tipo_Token::IDENTIFICADOR)&&comprueba(Tipo_Token::OP_ASIGNACION) && E() &&comprueba(Tipo_Token::SEMICOLON);
}
bool Parser::S() {
    while(lexico->tipo()==Tipo_Token::IDENTIFICADOR){
        if(!A()) return false;
    }
    return true;
}
bool Parser::E() {
    if(M())
    {
        while (comprueba(Tipo_Token::OP_SUMA))
        {
            if(!M()) return false;
        }
        return true;
    }
    else return false;
}

bool Parser::analiza() {
    return S() && comprueba(Tipo_Token::END);
}
