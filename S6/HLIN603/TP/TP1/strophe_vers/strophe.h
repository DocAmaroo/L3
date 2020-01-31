#ifndef __STROPHE_H
#define __STROPHE_H

#include "vers.h"

class Strophe
{
    private:
        Vers** suiteVers;
        int nbVers;
    public:
        Strophe();
        virtual ~Strophe();
        virtual void saisie(std::istream&);
        virtual Vers* vers(int) const;
        virtual void affiche(std::ostream&)const;
};

#endif