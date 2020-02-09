#include <stdio.h>

int main(int argc, char** argv, char** arge){
    printf("nb d'arguments (paramètres) : %d /n", argc);
    for(int i=0; i<argc; i++){
        printf("%d, %s/n", i , argv[i]);
    }
    int i=0;
    while(arge[i]!=NULL){
        printf("%d, %s/n", i , arge[i]);
        i++;
    }
    printf("nombre de variables d'environnement : %d/n" , i);
}