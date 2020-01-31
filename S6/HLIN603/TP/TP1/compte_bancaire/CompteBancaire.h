#ifndef _COMPTEBANCAIRE_
#define _COMPTEBANCAIRE_

class CompteBancaire{
    public :
        double solde;
        
    public :
        CompteBancaire(double solde=1000);
        virtual ~CompteBancaire();

        virtual double getSolde() const;
        virtual void setSolde(double);
        virtual void depose(double);
};

#endif