#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void grapheRandomv1(int n, int m, int edgy[][2]){
  srand(time(NULL));
  for(int i=0;i<m;i++){
    edgy[i][0]=rand()%n;
    edgy[i][1]=rand()%n;
    cout<<"("<<edgy[i][0]<<","<<edgy[i][1]<<")"<<endl;
  }  
}

bool dejaArete(int i, int j, int m, int edgy[][2]){
  for(int k=0;k<m;k++)
    if(i==edgy[k][0] && j==edgy[k][1])
      return true;
  return false;
}

void grapheRandomv2(int n, int m, int edgy[][2]){
  int i=0;
  int j=0;
  int temp=0;
  srand(time(NULL));
  for(int k=0;k<m;k++){
    do{
      i=rand()%n;
      j=rand()%n;
    }while(i==j && dejaArete(i,j,k,edgy));
    if(i>j){
      temp=i;
      i=j;
      j=temp;
    }
    edgy[k][0]=i;
    edgy[k][1]=j;
    cout<<"("<<edgy[k][0]<<","<<edgy[k][1]<<")"<<endl;
  }  
}

// O(n*m)
void composantes(int n, int m, int edgy[][2], int comp[]){
  int compi=0;
  int compj=0;

  // Initialisation
  for(int i=0;i<n;i++) {
    comp[i]=i;
  }

  // on parcours les arêtes 
  for(int j=0;j<m;j++){
    compi=comp[edgy[j][0]]; // on récupère un couple d'arête
    compj=comp[edgy[j][1]];
    if(compi!=compj){
      if(compi<=compj){ // on met dans comp la plus petite valeur des deux composantes
        for(int k=0;k<n;k++){
          if(comp[k]==compi){
            comp[k]=compj;
          }
        }
      }
      
      else{
        for(int k=0;k<n;k++){
          if(comp[k]==compj){
            comp[k]=compi;
          }
        }
      }
    }
  }
  for(int l=0;l<n;l++){
    cout<<"comp("<<l<<")="<<comp[l]<<endl;
  }
}

void composantes2(int n, int m, int edgy[][2], int comp[]){
  int compi=0;
  int compj=0;
  int tailleMin = 0;

  // on crée un vecteur de vecteur
  vector<vector<int>> sommets(n);

  //Initialisation
  for(int i=0;i<n;i++) {
    comp[i]=i;

    vector<int> v;
    v.push_back(i);
    sommets[i] = v;

  }

  // on parcours les arêtes 
  for(int i = 0; i < m; i++){

    int x = edgy[i][0]; int y = edgy[i][1];

    if(comp[x] != comp[y]){
      
      // Si le nombre de composante x > Nombre de composantes y ont les échanges
      if(sommets[comp[x]].size() > sommets[comp[y]].size())
        swap(x, y);

      int aux = comp[x];

      // tant que la pile de sommet de aux n'est pas vide on récupère la valeur du haut de la pile et on dépile
      while(!sommets[aux].empty()){
        int z = sommets[aux].back();
        comp[z] = comp[y];
        sommets[comp[y]].push_back(z);
        sommets[aux].pop_back();
      }
    }
  }
  
  for(int l=0;l<n;l++){
    cout<<"comp("<<l<<")="<<comp[l]<<endl;
  }
}


void ecritureTailles(int n, int m, int comp[]){
  int taille[n], nb[n+1];
  nb[n]=0;
  for(int i=0;i<n;i++){
    taille[i]=0;
    nb[i]=0;
  }
  for(int j=0;j<n;j++)
    taille[comp[j]]++;
  for(int k=0;k<n;k++)
    nb[taille[k]]++;
  cout<<"Il y a "<<nb[1]<<" points isoles."<<endl;
  for(int l=2;l<n+1;l++)
    if(nb[l]!=0)
      cout<<"Il y a "<<nb[l]<<" composantes de taille "<<l<<"."<<endl;
}

int main(){
  int n;     // Nombre de sommets.	
  int m;     // Nombre d'aretes.	
  cout << "Entrer le nombre de sommets:";
  cin >> n;
  cout << "Entrer le nombre d'aretes:";
  cin >> m;
  int edgy[m][2];    // Tableau des aretes.
  int comp[n];       // comp[i] est le numero de la composante contenant i.

  grapheRandomv2(n,m,edgy);
  //composantes(n,m,edgy,comp);
  ecritureTailles(n,m,comp);
  composantes2(n,m,edgy,comp);
  ecritureTailles(n,m,comp);

  return EXIT_SUCCESS;
}
