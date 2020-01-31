#include <iostream>
#include <string>
#include "strophe.h"

using namespace std;

int main(int argc, char* argv[]){

    string p1 = "j'aime la galette";
    // Vers* v1 = new Vers();
    Vers* v2 = new Vers(p1);
    
    v2->affiche(cout);
    
    Strophe* s1 = new Strophe();

    s1->affiche
    return 0;
}