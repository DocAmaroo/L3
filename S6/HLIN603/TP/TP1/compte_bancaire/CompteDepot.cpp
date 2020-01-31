#include <iostream>
#include <string>

#include "CompteDepot.h"

CompteDepot::CompteDepot(double _solde, double _frais) : frais(_frais){}

CompteDepot::~CompteDepot(){
    setSolde(solde - frais);
}