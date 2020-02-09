#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
typedef struct coord{int abs; int ord;} coord;

/**
 * @brief Création de pointRandom sauvegarder dans une structure points
 * 
 * @param n 
 * @param point 
 */
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

/**
 * @brief Calcule la distance entre le point[i] et point[j]
 * 
 * @param i 
 * @param j 
 * @param point 
 * @return double 
 */
double distance(int i, int j, coord point[]){

  int x = abs( point[j].abs - point[i].abs ) * abs( point[j].abs - point[i].abs );
  int y = abs( point[j].ord - point[i].ord ) * abs( point[j].ord - point[i].ord );
  int res = x+y;

  return res;

}

/**
 * @brief Calcule toutes les distances entre chaque point
 * 
 * @param n 
 * @param m 
 * @param point 
 * @param edge 
 */
void distances(int n, int m, coord point[], int edge[][3]){

  int k = 0;
  for( int i=0; i < n; i++ ){
    for ( int j=i+1; j < n; j++){
      edge[k][0] = i;
      edge[k][1] = j;
      edge[k][2] = distance(i, j, point);
      k++;
    }
  }
}

/**
 * @brief Affichage du tableau d'arête
 * 
 * @param m 
 * @param edge 
 */
void printEdge(int m, int edge[][3]){

  for (size_t i = 0; i < m; i++){
    cout << edge[i][0] << " " << edge[i][1] << " " << edge[i][2] << endl;
  }
  
}

/**
 * @brief Permet d'échanger deux arêtes
 * 
 * @param i 
 * @param j 
 * @param edge 
 */
void swap( int i, int j, int edge[][3]){
  int temp1 = edge[i][0], temp2 = edge[i][1], temp3 = edge[i][2];

  edge[i][0] = edge[j][0];
  edge[i][1] = edge[j][1];
  edge[i][2] = edge[j][2];
  
  edge[j][0] = temp1;
  edge[j][1] = temp2;
  edge[j][2] = temp3;
}

/**
 * @brief On tri le tableau d'arête par ordre de poids croissant
 * 
 * @param m 
 * @param edge 
 */
void tri(int m, int edge[][3]){
  int max = 0;
  for (size_t i = 0; i < m; i++)
  {    
    for ( size_t j = 0; j < m; j++)
    {
      if ( edge[i][2] < edge[j][2])
      {
        swap(i, j, edge);
        max = edge[i+1][2];
      }
    }
  }
  
  //cout << " ____ TRI EDGE ____" << endl;
  //printEdge(m, edge);
}

/**
 * @brief Création d'une arbre couvrant de poids minimum
 * 
 * @param n 
 * @param m 
 * @param edge 
 * @param arbre 
 * 
 * Complexité : O(n²+mlogn)
 */
void kruskal(int n, int m, int edge[][3], int arbre[][2]){
  
  //initialisation
  int comp[n], compi=0, compj=0, cpt=0;
  for(int i=0;i<n;i++) { comp[i]=i;}

  // Le tableau d'arête est déjà trié car appelé avant dans le main
  // tri(m, edge);

  // pour chaque arête
  for(int j=0;j<m;j++){
    
    compi=comp[edge[j][0]];
    compj=comp[edge[j][1]];
    
    // si pas dans la même composante
    if(compi!=compj){  
      
      // on ajoute dans l'arbre le couple de sommet
      arbre[cpt][0] = edge[j][0];
      arbre[cpt][1] = edge[j][1];
      cpt++;
    
      for(int k=0;k<n;k++){
        if(comp[k]==compj){
          comp[k]=compi;
        }
      }
    }
  }

  // affichage de l'arbre
  cout << "\n____ ARBRE ____" << endl;
  for(int l=0; l<cpt; l++){
    cout << "arbre("<<l<<") = ("<< arbre[l][0] << ", " << arbre[l][1] << ")" << endl;
  }
}

// O(mlog)
void kruskalOpti(int n, int m, int edge[][3], int arbre[][2]){
  int comp[n], x=0, y=0, cpt=0;
  vector<vector <int>> vect(n);

  for (int i = 0; i < n; i++) {
    comp[i] = i;
    vect[i].push_back(i);
  }

  for (int i = 0; i < m; i++) {
    
    x = edge[i][0];
    y = edge[i][1];
    
    // si pas dans la même composante
    if(comp[x] != comp[y]) {

      arbre[cpt][0] = x;
      arbre[cpt][1] = y;
      cpt++;

      if(vect[comp[x]].size() > vect[comp[y]].size()){ swap(x, y); }

      int aux = comp[x];
      while(!vect[aux].empty()){ // boucle tant que vect[aux] n'est pas vide
          int z = vect[aux].back(); // retourne la valeur en haut de vect[aux]
            comp[z] = comp[y];
              vect[comp[y]].push_back(z); // ajoute z au dessus de comp[y]
              vect[aux].pop_back(); // depile vect[aux]
      }
    }
  }
  
  // affichage de l'arbre
  cout << "\n____ ARBRE ____" << endl;
  for(int l=0; l<cpt; l++){
    cout << "arbre("<<l<<") = ("<< arbre[l][0] << ", " << arbre[l][1] << ")" << endl;
  }
}

/**
 * @brief Donnée avec l'énoncé -> voir affichage.cc
 * 
 * @param n 
 * @param point 
 * @param arbre 
 */
void affichageGraphique(int n, coord point[], int arbre[][2]);

int main() {
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 

  cout << "__ POINT RANDOM __" << endl;
  pointRandom(n, point);
  distances(n, m, point, edge);
  tri(m, edge);
  //kruskal(n, m, edge, arbre);
  kruskalOpti(n, m, edge, arbre);
  affichageGraphique(n, point, arbre);
  return EXIT_SUCCESS;
}
