#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main( int argc, char* const argv[]){
    if ( argc < 2 ){
        fprintf(stderr, "Donner un argument !");
    }
    else {
        int err = unlink(argv[1]);
        if ( err < 0 ){
            fprintf(stderr, "Erreur a la suppression de %s\n", argv[1]);
            fprintf(stderr, "Erreur n°%d signifiant %s\n", err, strerror(errno));
        }
        else{
            printf("Suppression de %s réussie !\n", argv[1]);
        }
    }
}