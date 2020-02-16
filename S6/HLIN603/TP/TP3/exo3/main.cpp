#include <iostream>

#include "exo3.h"

using namespace std;

int main(int argc, const char* argv[] ){
    Oeuf* oeuf;
    Casier6<Oeuf>* casier;
    afficheCasier(casier);
    casier->range(oeuf, 4);
    return 0;
}