#include <iostream>
#include <sstream>
#include "Parser.h"
using namespace std;
int main() {
    stringstream s("");
    Parser p(s);
    cout<<p.analiza();
    return 0;
}