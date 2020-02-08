#ifndef _COMPTEREMUNEREAVECCARTECREDIT_
#define _COMPTEREMUNEREAVECCARTECREDIT_

#include "CompteRemunere.h"

class CompteRemunereAvecCarteCredit : public virtual CompteRemunere{

    private :
        int frais;
        double solde;
    
    public :
        CompteRemunereAvecCarteCredit(double solde=1000, double frais=5);
        virtual ~CompteRemunereAvecCarteCredit();
};

#endif