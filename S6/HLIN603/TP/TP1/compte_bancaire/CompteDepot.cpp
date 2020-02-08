#include <iostream>
#include <string>
#include "CompteDepot.h"

using namespace std;

CompteDepot::CompteDepot(double _solde, double _frais) : frais(_frais){}

CompteDepot::~CompteDepot(){
    setSolde(solde - frais);
}

void CompteDepot::depose(double somme){
    cout << "CD : depot " << somme << endl;
    if( solde > 1000 ){
        setSolde(getSolde() + somme + 10);
    }else{
        setSolde(getSolde() + somme - 1);
    }
}