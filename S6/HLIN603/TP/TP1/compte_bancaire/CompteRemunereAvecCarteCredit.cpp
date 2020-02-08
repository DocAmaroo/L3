#include <iostream>
#include <string>
#include "CompteRemunereAvecCarteCredit.h"

using namespace std;

CompteRemunereAvecCarteCredit::CompteRemunereAvecCarteCredit(double _solde, double _frais) : frais(_frais){}

CompteRemunereAvecCarteCredit::~CompteRemunereAvecCarteCredit(){
    setSolde(getSolde() - frais);
}