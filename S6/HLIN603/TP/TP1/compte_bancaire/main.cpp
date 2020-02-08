#include <iostream>
#include <string>

#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteDepot.h"
#include "CompteRemunereAvecCarteCredit.h"

int main(int argc, char* argv[]){

    CompteBancaire cb;
    cb.depose(100); 

    CompteRemunere cr;
    cr.depose(100);

    CompteDepot cd;
    cd.depose(100);

    CompteRemunereAvecCarteCredit crcd;
    crcd.depose(100);

    int n = 2;
    CompteBancaire* CompteVP[n];
    CompteVP[0] = new CompteRemunere();
    CompteVP[1] = new CompteDepot();

    for ( int i=0; i < n; i++){
        CompteVP[i]->depose(100);
    }

    return 0;
}