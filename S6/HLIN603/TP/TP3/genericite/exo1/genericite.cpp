#include <iostream>

using namespace std;

template<typename elt> void echange(elt& e1, elt& e2){
    elt aux=e1; e1=e2; e2=aux;
}

template<typename elt> void triBulles(elt T[], int tailleT){
    int i=tailleT-2,j; bool ech=true;
    while (i>=0 && ech){
        ech=false;
        for (j=0; j<=i; j++){
            if (T[j]>T[j+1]){
                echange(T[j],T[j+1]); ech=true;
            }
        }
        i--;
    }
}

template<typename T> void afficheTab(T tab[], int n){
    cout << "tab : [";
    for ( int i=0; i < n; i++ ){
        cout << " " << tab[i];
    }
    cout << " ]" << endl;
}

int main(int argc, const char** argv){

    string test[5] = {"allo", "alhuile", "albert", "alamoniac", "alouette"}; 
    triBulles(test, 5);
    afficheTab(test,5);
    
    return 0;
}

// CasierBouteille::CasierBouteille(){
//     for (int i=0; i<6; i++){
//         cases[i]=NULL;
//     }
// }

// CasierBouteille::~CasierBouteille(){}

// void CasierBouteille::range(Bouteille* bouteille, int numeroCase){
//     cases[numeroCase]=bouteille;
// }

// CasierOeuf::CasierOeuf(){ 
//     for (int i=0; i<6; i++){
//         cases[i]=NULL;
//     }
// }

// CasierOeuf::~CasierOeuf(){}

// void CasierOeuf::range(Oeuf* oeuf, int numeroCase){
//     cases[numeroCase]=oeuf;
// }