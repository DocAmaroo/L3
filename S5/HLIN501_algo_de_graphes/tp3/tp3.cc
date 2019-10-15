#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
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

void affichePL(int voisin, int ordre, int pere, int niveau){
  (voisin == -1)? cout << "RACINE : 0" : cout << "VOISIN : "<< voisin << " - PERE : "<< pere;
  cout << " - NIVEAU : "<< niveau;
  cout << " - ORDRE : "<< ordre << endl;
}

void parcoursLargeur(int n, vector<int> voisins[], int niveau[], int ordre[], int pere[]){

  // On initialise dv
  int* dv = new int[n];
  for(int i = 0 ; i < n ; i++){
    dv[i] = 0;
    ordre[i] = -1;
    pere[i] = -1;
    niveau[i] = -1;
  }

  // Choix de la racine
  int racine = 0;
  dv[racine] = 1;
  ordre[racine] = 1;
  pere[racine] = racine;
  niveau[racine] = 0;
  affichePL(-1, ordre[racine], pere[racine], niveau[racine]);
  
  // Compteur pour dire à quel moment on a vu notre élément
  int t = 2;

  // on crée une file
  queue<int> AT;

  // on ajoute la racine dans la file
  AT.push(racine);

  while( !AT.empty() ){
    
    int v = AT.front(); // on récupère l'élement en haut de la file

    AT.pop(); // on l'enlève de la file
    int size = (int)voisins[v].size();

    for( int i=0; i < size ; i++){

      int x = voisins[v][i];

      if ( dv[x] == 0 ){
        dv[x] = 1;
        AT.push(x);
        ordre[x] = t;
        t++;
        pere[x] = v;
        niveau[x] = niveau[v] + 1;

        affichePL(voisins[v][i], ordre[x], pere[x], niveau[x]);
      }
    }
  }
  delete[] dv;
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
  parcoursLargeur(n, voisins, niveau, ordre, pere);
  return EXIT_SUCCESS;
}
