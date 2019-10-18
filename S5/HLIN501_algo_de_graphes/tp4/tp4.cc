#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

const int N=1400;
const int M=(N*(N-1))/2;
  
typedef struct coord{int abs; int ord;} coord;

void pointRandom(int n,coord point[]);
float distance(coord p1,coord p2);
void voisins(int n,int dmax,coord point[],vector<int> voisin[],int &m);
void voisins2arete(int n,vector<int>voisins[],int arete[][2]);
void affichageGraphique(int n,int m,coord point[],int arete[][2],string name);
bool existe(int n,int dis[],bool traite[],int &x);
void dijkstra(int n,vector<int> voisin[],coord point[],int pere[]);
int construireArbre(int n,int arbre[][2],int pere[]);

int
main()
{
  int n;                           // Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n; 
  int dmax=50;                     // La distance jusqu'a laquelle on relie deux points.
  coord point[N];                  // Les coordonnees des points.
  vector<int> voisin[N];           // Les listes de voisins.          
  int arbre[N-1][2];               // Les aretes de l'arbre de Dijkstra.
  int pere[N];                     // La relation de filiation de l'arbre de Dijkstra.
  int m;                           // Le nombre d'aretes
  int arete[M][2];                 // Les aretes du graphe
  return EXIT_SUCCESS;
}
