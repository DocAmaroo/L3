#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc , char * argv[]) {

    // test en cas d'erreur d'argument ou fichier inexistant
    if(argc != 3) {
        printf("You need to run this program with exactly two argument : filename char\n");
        return 1;
    }

    int file = open(argv[1] , O_RDONLY);

    if(file < 0) {
        printf("Can't open %s\n" , argv[1]);
        return 2;
    }

    /**
     * @brief Déclaration des variables
     * 
     */
    char toFind = argv[2][0],
    c;

    int deb = 0,
    fin = lseek(file, 0, SEEK_END)-1,
    mid = 0;

    /**
     * @brief Si fin = 0 => fichier vide
     * 
     */
    if ( fin == 0 ){
        printf("Votre fichier est vide !\n");
        exit(EXIT_FAILURE);
    }

    /**
     * @brief On se met au milieu du fichier
     * Tant que le curseur de début est < curseur de fin et
     * qu'on a pas trouvé notre caractère on continue la boucle
     */ 
    while( deb <= fin && c != toFind )
    {
        mid = (deb+fin)/2; // Nouveau milieu
        lseek(file, mid, SEEK_SET); // positionne le curseur au centre
        read(file, &c, 1); // on récupère le nouveau caractère
        
        /**
         * @brief Si le caractère ASCII du fichier est < à celui qu'on recherche
         * alors il est dans la partie entre mid et fin
         */
        if ( c < toFind ){
            deb = mid+1;
        }

        /**
         * @brief Sinon c'est entre deb et mid 
         */
        else{
            fin = mid-1;
        }
        printf("END : deb = %i | fin = %i | mid = %i\n", deb,fin,mid);
        
    }

    printf("c = %c", c);
    if ( c == toFind ){
        printf("Votre caractère a été trouvé en position %i\n", mid);
    }
    else{
        printf("Votre caractère est introuvable !\n");
    }
    close(file);
    return 0;
}