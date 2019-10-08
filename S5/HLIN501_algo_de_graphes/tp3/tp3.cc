#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void affichageVector( vector<int> v ){
  int i=0;
  cout << "[ ";
  while( i < v.size() - 1 ){
    cout << v[i] << ", ";
    i++;
  }
  cout << v[i] <<" ]" << endl;
}

void affichageAllVector(int n, vector<int> v[] ){
  for( int i=0; i < n; i++ ){
    cout << "Vector " << i << " : ";
    if( v[i].size() == 0 ) { cout << "[ ]" << endl; }
    else{ affichageVector(v[i]); }
  }
}

void voisinRandom(int n, int m, vector<int>voisins[]){

  int point1;
  int point2;
  bool pas_bon = false;

  srand(time(NULL));
  
  for (int i = 0; i < m; i++)
  {
    do{
      point1 = rand()%n;
      point2 = rand()%n;

      if ( point1 == point2 ){
        pas_bon = false;
        continue;
      }

      for( int i=0; i < voisins[point1].size(); i++){
        if ( voisins[point1][i] == point2 ){
          pas_bon = true;
          break;
        }
      }

      for( int i=0; i < voisins[point2].size(); i++){
        if ( voisins[point2][i] == point1 ){
          pas_bon = true;
          break;
        }
      }
    }
    while( pas_bon );

    voisins[point1].push_back(point2);
    voisins[point2].push_back(point1);
  }
  
  affichageAllVector(n, voisins);

}


int main()
{
  int n;                                    // Le nombre de sommets.
  int m;                                    // Le nombre d'aretes.
  cout << "Entrer le nombre de sommets: ";
  cin >> n;
  cout << "Entrer le nombre d'aretes: ";
  cin >> m;
  vector<int> voisins[n];                   // Les listes des voisins. 
  int pere[n];                              // L'arbre en largeur.
  int ordre[n];                             // L'ordre de parcours.
  int niveau[n];                            // Le niveau du point.

  voisinRandom(n, m, voisins);
  return EXIT_SUCCESS;
}
