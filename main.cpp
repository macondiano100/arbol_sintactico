#include <iostream>
#include <sstream>
#include "Parser.h"
using namespace std;
int main() {
    stringstream s("a=a*2;b=2+3;");
    Parser p(s);
    cout<<p.analiza();
    return 0;
}