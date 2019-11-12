#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
typedef struct coord{int abs; int ord;} coord;

void affichageGraphique(int n, int m, coord point[], int tab[][2], string name){
  ofstream output;                           
  output.open(name,ios::out);
  output << "%!PS-Adobe-3.0" << endl;
  output << "%%BoundingBox: 0 0 612 792" << endl;
  output << endl;  
  for(int i=0;i<n;i++)
    {
      output << point[i].abs << " " << point[i].ord << " 3 0 360 arc" <<endl;
      output << "0 setgray" <<endl;
      output << "fill" <<endl;
      output << "stroke"<<endl;
      output << endl;
    }
  output << endl;
  
  int taille = 0;
  if ( name == "Arbre.ps"){
    taille = n;
  }
  else{
    taille = m;
  }
  for(int i=0;i<taille;i++){
    output << point[tab[i][0]].abs << " " << point[tab[i][0]].ord << " moveto" << endl;
    output << point[tab[i][1]].abs << " " << point[tab[i][1]].ord << " lineto" << endl;
    output << "stroke" << endl;
    output << endl;
  }
  output << "showpage";
  output << endl;
}
