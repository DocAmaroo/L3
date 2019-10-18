#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char * argv[]) {
    int position = 0, nb;
    char c[16];

    // test en cas d'erreur d'argument ou fichier inexistant
    if(argc != 2) {
        printf("You need to run this program with exactly one argument!\n");
        return 1;
    }

    int file = open(argv[1] , O_RDONLY);

    if(file < 0) {
        printf("Can't open %s\n" , argv[1]);
        return 2;
    }

    // tant que qu'on peut lire 16 caractères
    while(0 < (nb = read(file , &c , 16))) {

        // on affiche la position : 000000xx
        printf("%8.8x : ", position);
        position += 16;

        // on lit les 16 caractères
        for(int i = 0 ; i < nb ; i++) {
            char code = c[i];
            printf("%2.2hhx" , code);
                       
            // tout les deux caractères on ajoute un espace
            if(i % 2)
            {
                printf(" ");
            }
        }

        // si on a moins que 16 caractère, on arrive en fin de fichier
        if(nb < 16) {
            for(int i = nb ; i < 16 ; i++) {
                printf("  ");
                if(i % 2)
                    printf(" ");
            }
        }
        printf("%s", c);
        printf("\n");
    }
    close(file);
    return 0;
}