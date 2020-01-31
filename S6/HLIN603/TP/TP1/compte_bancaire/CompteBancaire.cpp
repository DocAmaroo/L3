#include <iostream>
#include <string>
#include "CompteBancaire.h"

using namespace std;

CompteBancaire::CompteBancaire(double _solde) : solde(_solde){}

CompteBancaire::~CompteBancaire(){
    cout << "La banque vous doit : " << solde << endl;
}

double CompteBancaire::getSolde() const{
    return solde;
}
void CompteBancaire::setSolde(double new_solde){
    solde = new_solde;
}

void CompteBancaire::depose(double depot){
    setSolde( depot + getSolde()); 
}