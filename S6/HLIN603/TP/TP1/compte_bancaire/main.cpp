#include <iostream>
#include <string>

#include "CompteBancaire.h"
#include "CompteRemunere.h"
#include "CompteDepot.h"

int main(int argc, char* argv[]){

    CompteBancaire cb;
    cb.depose(250);

    CompteRemunere cr;
    cr.depose(250);

    CompteDepot cd;
    cd.depose(250);

    return 0;
}