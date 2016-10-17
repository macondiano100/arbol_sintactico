//
// Created by Antonio on 15/10/2016.
//

#include <iostream>
#include "Parser.h"

bool Parser::comprueba(Tipo_Token t) {
    if(lexico->tipo()==t){
        token_actual=*lexico;
        lexico++;
        return true;
    }
    else return false;
}

Nodo_Sintactico * Parser::F() {
    if(comprueba((Tipo_Token::ENTERO))) return new Nodo_Sintactico("entero",token_actual.lexema());
    else if(comprueba(Tipo_Token::IDENTIFICADOR))
    {
        return new Nodo_Sintactico("identificador",token_actual.lexema());
    }
    else if(comprueba(Tipo_Token::PARENTESIS_ABRE)){
        auto nodo=E();
        if(nodo!= nullptr&&comprueba(Tipo_Token::PARENTESIS_CIERRA)) return nodo;
        else return nullptr;
    }
    return nullptr;
}

Nodo_Sintactico * Parser::M() {
    Nodo_Sintactico *aux,*res;
    aux=F();
    if(aux!= nullptr)
    {
        res=aux;
        while(comprueba(Tipo_Token::OP_MULT))
        {
            aux=new Nodo_Sintactico("multiplicacion");
            aux->hijos.push_back(res);
            res=aux;
            aux=F();
            if(aux== nullptr) return nullptr;
            else{
                res->hijos.push_back(aux);
            }
        }
        return res;
    }
    else return nullptr;
}
Nodo_Sintactico * Parser::A() {
    if (comprueba(Tipo_Token::IDENTIFICADOR))
    {
        auto res=new Nodo_Sintactico("asignacion");
        res->hijos.push_back(new Nodo_Sintactico("identificador",token_actual.lexema()));
        if(comprueba(Tipo_Token::OP_ASIGNACION)){
            Nodo_Sintactico* aux=E();
            if(aux != nullptr && comprueba(Tipo_Token::SEMICOLON)) {
                res->hijos.push_back(aux);
                return res;
            }
        }
    }
    return nullptr;
}
Nodo_Sintactico * Parser::S() {
    Nodo_Sintactico* nodo=new Nodo_Sintactico("programa");
    while(lexico->tipo()==Tipo_Token::IDENTIFICADOR){
        auto aux=A();
        if(aux!= nullptr) nodo->hijos.push_back(aux);
        else return nullptr;
    }
    return nodo;
}
Nodo_Sintactico * Parser::E() {
    Nodo_Sintactico* aux,*res;
    aux=M();
    if(aux!= nullptr)
    {
        res=aux;
        while (comprueba(Tipo_Token::OP_SUMA))
        {
            aux=new Nodo_Sintactico("suma");
            aux->hijos.push_back(res);
            res=aux;
            aux=M();
            if(aux== nullptr) return nullptr;
            else {
                res->hijos.push_back(aux);
            }
        }
        aux=new Nodo_Sintactico("expresion");
        aux->hijos.push_back(res);
        res=aux;
        return res;
    }
    else return nullptr;
}

bool Parser::analiza() {
    auto nodo=S();
    pre_pos_orden(nodo, [](Nodo_Sintactico *nodo) {
        std::cout<<"<"<< nodo->etiqueta << ">" << nodo->contenido << std::endl;
    },
    [](Nodo_Sintactico *nodo)
    {
        std::cout<<"</"<< nodo->etiqueta << ">"<< std::endl;
    }
    );
    return nodo!= nullptr;
    //return S() && comprueba(Tipo_Token::END);
}
