#ifndef _COMPTEDEPOT_
#define _COMPTEDEPOT_

#include "CompteBancaire.h"

class CompteDepot : public virtual CompteBancaire{

    private :
        int frais;

    public :
        CompteDepot(double solde=1000, double frais=100);
        virtual ~CompteDepot();
};

#endif