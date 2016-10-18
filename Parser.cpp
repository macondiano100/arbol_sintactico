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

puntero_nodo Parser::F() {
    if(comprueba((Tipo_Token::ENTERO))) return puntero_nodo(new Nodo_Sintactico("entero",token_actual.lexema()));
    else if(comprueba(Tipo_Token::IDENTIFICADOR))
    {
        return puntero_nodo(new Nodo_Sintactico("identificador",token_actual.lexema()));
    }
    else if(comprueba(Tipo_Token::PARENTESIS_ABRE)){
        auto nodo=E();
        if(nodo!= nullptr&&comprueba(Tipo_Token::PARENTESIS_CIERRA)) return nodo;
        else return nullptr;
    }
    return nullptr;
}
puntero_nodo Parser::M() {
    puntero_nodo aux,res;
    aux=F();
    if(aux!= nullptr)
    {
        res=std::move(aux);
        while(comprueba(Tipo_Token::OP_MULT))
        {
            aux.reset(new Nodo_Sintactico("multiplicacion"));
            aux->agrega_hijo(std::move(res));
            res=std::move(aux);
            aux=F();
            if(aux== nullptr) return nullptr;
            else{
                res->agrega_hijo(std::move(aux));
            }
        }
        return res;
    }
    else return nullptr;
}

puntero_nodo Parser::E() {
    puntero_nodo aux,res;
    aux=M();
    if(aux!= nullptr)
    {
        res=std::move(aux);
        while (comprueba(Tipo_Token::OP_SUMA))
        {
            aux.reset(new Nodo_Sintactico("suma"));
            aux->agrega_hijo(std::move(res));
            res=std::move(aux);
            aux=M();
            if(aux== nullptr) return nullptr;
            else {
                res->agrega_hijo(std::move(aux));
            }
        }
        aux.reset(new Nodo_Sintactico("expresion"));
        aux->agrega_hijo(std::move(res));
        res=std::move(aux);
        return res;
    }
    else return nullptr;
}
 puntero_nodo Parser::A() {
    if (comprueba(Tipo_Token::IDENTIFICADOR))
    {
        auto res=puntero_nodo(new Nodo_Sintactico("asignacion"));
        res->agrega_hijo(puntero_nodo(new Nodo_Sintactico("identificador",token_actual.lexema())));
        if(comprueba(Tipo_Token::OP_ASIGNACION)){
            auto aux=E();
            if(aux != nullptr && comprueba(Tipo_Token::SEMICOLON)) {
                res->agrega_hijo(std::move(aux));
                return res;
            }
        }
    }
    return nullptr;
}
void Parser::xml(std::ostream &out)
{
    if(arbol!= nullptr)
    pre_pos_orden(arbol.get(),
                  [&](Nodo_Sintactico *nodo) {
                      out<<"<"<< nodo->etiqueta << ">"<<std::endl;
                      if(!(nodo->contenido.empty()))out<<nodo->contenido<< std::endl;
                  },
                  [&](Nodo_Sintactico *nodo)
                  {
                      out<<"</"<< nodo->etiqueta << ">"<< std::endl;
                  }
    );
}
puntero_nodo Parser::S() {
    auto nodo=puntero_nodo(new Nodo_Sintactico("programa"));
    while(lexico->tipo()==Tipo_Token::IDENTIFICADOR){
        auto aux=A();
        if(aux!= nullptr) nodo->agrega_hijo(std::move(aux));
        else return nullptr;
    }
    return nodo;
}
bool Parser::analiza() {
    auto nodo=S();
    if(nodo!= nullptr)
        arbol=std::move(nodo);
    return nodo!= nullptr &&comprueba(Tipo_Token::END);
}

