#ifndef _EXO2_
#define _EXO2_

class Bouteille{

};

class Oeuf{

};

class CasierBouteille {
    private:
        Bouteille* cases[6];
    public:
        CasierBouteille();
        virtual ~CasierBouteille();
        virtual void range(Bouteille* bouteille, int numeroCase);
};

class CasierOeuf {
    private:
        Oeuf* cases[6];
    public:
        CasierOeuf();
        virtual ~CasierOeuf();
        virtual void range(Oeuf* oeuf, int numeroCase);
};

template<typename produit>
class Casier6{
    private:
        produit* cases[6];
    public:
        Casier6();
        virtual ~Casier6();
        virtual void range(produit* _produit, int numeroCase);
        void afficheCasier(Casier6<produit> _produit);

};

#endif