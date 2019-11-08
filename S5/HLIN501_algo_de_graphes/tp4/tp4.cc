#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;
  
typedef struct coord{int abs; int ord;} coord;

void pointRandom(int n, coord point[]){

  srand(time(NULL));

  int x = 0;
  int y = 0;
  for ( int i=0; i < n; i++){
    
    x = rand()%613;
    y = rand()%792;
    
    cout << "( " << x << ", " << y << " )" << endl;
    point[i].abs = x;
    point[i].ord = y;
  }
}

double distance(coord p1, coord p2){

  double x = abs( p2.abs - p1.abs ) * abs( p2.abs - p1.abs );
  double y = abs( p2.ord - p1.ord ) * abs( p2.ord - p1.ord );
  double res = sqrt(x+y);

  return res;
}

void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m){
  m = 0;
  for( int i=0; i < n; i++ ){
    for ( int j=i+1; j < n; j++ ){
      if ( dmax > distance(point[i],point[j]) ){
        voisin[i].push_back(j);
        voisin[j].push_back(i);
        m++;
        cout << " m = " << m << endl;
      }
    }
  }
}

/**
 * @brief Affiche tout les éléments d'un vecteur
 * 
 * @param v 
 */
void affichageVector( vector<int> v ){
  int i=0;
  cout << "[ ";
  while( i < v.size() - 1 ){
    cout << v[i] << ", ";
    i++;
  }
  cout << v[i] <<" ]" << endl;
}

/**
 * @brief Affiche tout les éléments de chaque vecteur
 * 
 * @param n 
 * @param v 
 */
void affichageAllVector(int n, vector<int> v[] ){
  cout << "\n## AFFICHAGE DES VOISINS" << endl;
  for( int i=0; i < n; i++ ){
    cout << "Sommet " << i << " : ";
    if( v[i].size() == 0 ) { cout << "[ ]" << endl; }
    else{ affichageVector(v[i]); }
  }
}

void voisins2arete(int n,vector<int>voisin[],int arete[][2]){
  int cpt = 0;
  for ( int i=0; i < n; i++ ){
    for ( int j=0; j < voisin[i].size(); j++ ){
      if ( i < voisin[i][j] ){
        arete[cpt][0] = i;
        arete[cpt][1] = voisin[i][j];
        cpt++;
      }
    }
  }
}

void affichageArete(int m, int arete[][2] ){
  cout << "\n## AFFICHAGE DES ARETES" << endl;
  for( int i=0; i < m; i++ ){
    cout << "Arete " << i << " : " << arete[i][0] << ", " << arete[i][1] << endl;    
  }
}

void affichageGraphique(int n, int m, coord point[], int arete[][2], string name);

bool existe(int n,int dis[],bool traite[],int &x){
  for ( int i=0; i < n; i++ ){
    if ( traite[i] == 0 ){
      if ( dis[i] < x){
        
      }
      return true;
    }
  }
  return false;
}
void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]){
  int racine = 0;
  int d[n];
  int traite[n];
  for( int i=0; i < n; i++ ){
    d[i] = -1;
    traite[i] = 0; 
  }
  pere[0] = racine;
  d[racine] = 0;
  while( existe(n, dis) )
}

int construireArbre(int n,int arbre[][2],int pere[]);

int main(){
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax=300;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.          
  int arbre[N-1][2];               // Les aretes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes
  int arete[M][2];                 // Les aretes du graphe
  string name = "Graphe.ps";

  pointRandom(n, point);
  voisins(n, dmax, point, voisin, m);
  affichageAllVector(n, voisin);
  voisins2arete(n, voisin, arete);
  affichageGraphique(n, m, point, arete, name);
  affichageArete(m, arete);
  cout << "Nb arête " << m << endl;

  return EXIT_SUCCESS;
}
