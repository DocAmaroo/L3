#include <iostream>
#include <string>

#include "CompteRemunere.h"

using namespace std;

CompteRemunere::CompteRemunere(double _solde, double _bonus) : bonus(_bonus){}

CompteRemunere::~CompteRemunere(){
    setSolde(solde + solde*bonus);
}