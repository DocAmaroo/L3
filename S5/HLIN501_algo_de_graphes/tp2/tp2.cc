#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
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

double distance(int i, int j, coord point[]){

  int x = abs( point[j].abs - point[i].abs ) * abs( point[j].abs - point[i].abs );
  int y = abs( point[j].ord - point[i].ord ) * abs( point[j].ord - point[i].ord );
  int res = x+y;

  return res;

}

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

void printEdge(int m, int edge[][3]){

  for (size_t i = 0; i < m; i++){
    cout << edge[i][0] << " " << edge[i][1] << " " << edge[i][2] << endl;
  }
  
}

void swap( int i, int j, int edge[][3]){
  int temp1 = edge[i][0], temp2 = edge[i][1], temp3 = edge[i][2];

  edge[i][0] = edge[j][0];
  edge[i][1] = edge[j][1];
  edge[i][2] = edge[j][2];
  
  edge[j][0] = temp1;
  edge[j][1] = temp2;
  edge[j][2] = temp3;
}

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
  printEdge(m, edge);
}

void kruska(int n, int m, int edge[][3], int arbre[][2]){
  
  int comp[n];
  int compi=0;
  int compj=0;
  int cpt=0;

  for(int i=0;i<n;i++) {
    comp[i]=i;
  }

  for(int j=0;j<m;j++){
    
    compi=comp[edge[j][0]];
    compj=comp[edge[j][1]];
    
    if(compi!=compj){  
      
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

  for(int l=0; l<cpt; l++){
    cout << "arbre("<<l<<") = "<< arbre[l][0] << " - " << arbre[l][1] <<endl;
  }
}

void affichageGraphique(int n, coord point[], int arbre[][2]);

int main()
{
  int n;             //Le nombre de points.
  cout << "Entrer le nombre de points: ";
  cin >> n;
  int m=n*(n-1)/2;   // Le nombre de paires de points.
  coord point[n];    // Les coordonnees des points dans le plan.
  int edge[m][3];    // Les paires de points et le carre de leur longueur.
  int arbre[n-1][2]; // Les aretes de l'arbre de Kruskal. 

  pointRandom(n, point);
  distances(n, m, point, edge);
  tri(m, edge);
  kruska(n, m, edge, arbre);
  affichageGraphique(n, point, arbre);
  return EXIT_SUCCESS;
}
