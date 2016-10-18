#include <iostream>
#include <sstream>
#include "Parser.h"
using namespace std;
/**
 * TODO
 * 1-revisar la generacion del arbol (necesito ver el formato que quiere franco)
 * 2- Ya sé, el código está feo, no se burlen prros >:v
 */
int main() {
    ifstream in("entrada.txt");
    ofstream out("salida.txt");
    Parser p(in);
    p.analiza();
    p.xml(out);
    return 0;
}