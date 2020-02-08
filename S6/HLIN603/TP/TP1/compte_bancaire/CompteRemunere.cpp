#include <iostream>
#include <string>

#include "CompteRemunere.h"

using namespace std;

CompteRemunere::CompteRemunere(double _solde, double _bonus) : bonus(_bonus){}

CompteRemunere::~CompteRemunere(){
    setSolde(solde + solde*bonus);
}

void CompteRemunere::depose(double somme){
    cout << "CR : depot " << somme << endl;
    setSolde(getSolde() + somme + (0.1*somme));
}

