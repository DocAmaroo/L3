    #include <iostream>
#include<string>
#include "vers.h"
#include "strophe.h"

using namespace std;

Strophe::Strophe(){
    suiteVers=NULL;
    nbVers=0;
} //constructeur par défaut

Strophe::~Strophe(){
    if (suiteVers){
        delete[] suiteVers;
    } //destructeur 
}// on ne détruit que le tableau, pas les vers.


Vers* Strophe::vers(int i) const {
    if (i>=0 && i<nbVers) {
        return suiteVers[i]; 
    } else{
        return NULL;
    } 
}//constructeur paramétré, renvoie le tableau de Vers

void Strophe::saisie(istream& is){ //fonction qui remplit suiteVers avec ce que rentre l'utilisateur
    if (suiteVers) {
        delete[] suiteVers;
    }
    cout << "Entrer le nombre de vers : " << endl;
    is>>nbVers; suiteVers = new Vers*[nbVers];
    for (int i=0; i<nbVers; i++){
        Vers *v=new Vers(); 
        v->saisie(is); 
        suiteVers[i]=v;
    }
}

void Strophe::affiche(ostream& os) const { //fonction qui affiche le contenu de suiteVers
    for (int i=0; i<nbVers; i++){
        suiteVers[i]->affiche(os); os << endl;
    }
}