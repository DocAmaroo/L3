#ifndef _COMPTEREMUNERE_
#define _COMPTEREMUNERE_

#include "CompteBancaire.h"

class CompteRemunere : public virtual CompteBancaire{
    public :
        double bonus;

    public :
        CompteRemunere(double solde=1000, double bonus=0.10);
        virtual ~CompteRemunere();
};

#endif