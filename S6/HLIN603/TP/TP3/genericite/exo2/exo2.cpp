#include <iostream>
#include <string.h>

#include "exo2.h"

using namespace std;

// _____ BOUTEILLE _____
CasierBouteille::CasierBouteille(){
    for (int i=0; i<6; i++){
        cases[i]=NULL;
    }
}

CasierBouteille::~CasierBouteille(){}

void CasierBouteille::range(Bouteille* bouteille, int numeroCase){
    cases[numeroCase]=bouteille;
}

// _____ OEUF _____
CasierOeuf::CasierOeuf(){
    for (int i=0; i<6; i++){
        cases[i]=NULL;
    }
}

CasierOeuf::~CasierOeuf(){}

void CasierOeuf::range(Oeuf* oeuf, int numeroCase){
    cases[numeroCase]=oeuf;
}

// _____ CASIER 6 _____
template<typename produit>
Casier6<produit>::Casier6(){
    for( int i=0; i < 6; i++){ 
        cases[i] = NULL;
    }
}

template<typename produit>
Casier6<produit>::~Casier6(){}

template<typename produit>
void Casier6<produit>::range(produit* p, int numeroCase){
    cases[numeroCase]= p;
}

template<typename produit>
void afficheCasier(Casier6<produit> produits){
    cout << "Casier : [";
    for ( int i=0; i < 6; i++ ){
        cout << " " << produits[i];
    }
    cout << " ]" << endl;
}