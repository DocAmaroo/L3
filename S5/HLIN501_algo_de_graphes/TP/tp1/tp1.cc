#include <cstdlib>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * @brief Crée un graphe random avec n sommets et m arêtes 
 * 
 * @param n -> nb sommets
 * @param m -> nb d'arête
 * @param edgy -> les arêtes
 */
void grapheRandomv1(int n, int m, int edgy[][2]){
  srand(time(NULL));
  for(int i=0;i<m;i++){
    edgy[i][0]=rand()%n;
    edgy[i][1]=rand()%n;
    cout<<"("<<edgy[i][0]<<","<<edgy[i][1]<<")"<<endl;
  }  
}

/**
 * @brief Renvoi vrai si il existe une arête entre i et j
 * 
 * @param i 
 * @param j 
 * @param m 
 * @param edgy 
 * @return res
 */
bool dejaArete(int i, int j, int m, int edgy[][2]){
  bool res = false;
  for(int k=0;k<m;k++){
    if(i==edgy[k][0] && j==edgy[k][1]){
      res = true;
    }
  }
  return res;
}

/**
 * @brief Crée un graphe random à n sommets et m arête et évite les doublons d'arête
 * 
 * @param n -> nb sommets
 * @param m -> nb d'arête
 * @param edgy -> les arêtes
 */
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

/**
 * @brief Permet de remplir le tableau comp[] 
 * Vérifiant que comp[i] == comp[j] si il existe un chemin de x à y
 * Autrement dit : x et y appartiennent à la même compo connexe
 * 
 * @param n -> nb sommets
 * @param m -> nb d'arête
 * @param edgy -> les arêtes
 * @param comp -> les composantes
 * 
 * Complexité : O(n*m)
 */

void composantes(int n, int m, int edgy[][2], int comp[]){
  int compi=0;
  int compj=0;

  // Initialisation
  for(int i=0;i<n;i++) { comp[i]=i; }

  // on parcours les arêtes 
  for(int j=0;j<m;j++){

    // on récupère un couple d'arête
    compi=comp[edgy[j][0]];
    compj=comp[edgy[j][1]];
    
    if(compi!=compj){

      // on met dans comp[k] la plus petite valeur des deux composantes
      if(compi<=compj){ 
        for(int k=0;k<n;k++){
          if(comp[k]==compj){
            comp[k]=compi;
          }
        }
      }
      
      else{
        for(int k=0;k<n;k++){
          if(comp[k]==compi){
            comp[k]=compj;
          }
        }
      }
    }
  }

  // affichage du tableau comp[]
  for(int l=0;l<n;l++){
    cout<<"comp("<<l<<")="<<comp[l]<<endl;
  }
}

/**
 * @brief Permet de remplir le tableau comp[] 
 * Vérifiant que comp[i] == comp[j] si il existe un chemin de x à y
 * Autrement dit : x et y appartiennent à la même compo connexe
 * 
 * @param n -> nb sommets
 * @param m -> nb d'arête
 * @param edgy -> les arêtes
 * @param comp -> les composantes
 * 
 * Complexité : O(n*m?)
 */
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

    int x = edgy[i][0], y = edgy[i][1];

    if(comp[x] != comp[y]){
      
      // Si nb_comp(x) > nb_comp(y) => ont les échanges
      if(sommets[comp[x]].size() > sommets[comp[y]].size()){ swap(x, y); }

      int aux = comp[x];

      // Tant que la pile de sommet n'est pas vide 
      // on récupère la valeur du haut de la pile et on dépile
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

/**
 * @brief Affichage des points isolés et du nb_comp à x sommets
 * 
 * @param n 
 * @param m 
 * @param comp 
 */
void ecritureTailles(int n, int m, int comp[]){
  cout << " ____ TAILLE ____ " << endl;
  int taille[n], nb[n+1];
  nb[n]=0;

  // initialisation (pas forcément necessaire)
  for(int i=0;i<n;i++){ taille[i]=0; nb[i]=0; }
  for(int j=0;j<n;j++){ taille[comp[j]]++; }
  for(int k=0;k<n;k++){ nb[taille[k]]++; }

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

  cout << "__ GRAPHE __ " << endl;
  grapheRandomv2(n,m,edgy);

  cout << "\n__ COMPOSANTE __ " << endl;
  composantes(n,m,edgy,comp);
  ecritureTailles(n,m,comp);

  cout << "\n__ COMPOSANTE V2 __ " << endl;
  composantes2(n,m,edgy,comp);
  ecritureTailles(n,m,comp);

  return EXIT_SUCCESS;
}
