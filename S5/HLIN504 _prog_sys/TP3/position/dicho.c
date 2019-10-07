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

    char* toFind = argv[2];
    int file_length = lseek(file, 0, SEEK_END);
    char* c;
    int nb;
    
    /**
     * @brief On se met au milieu du fichier
     * Si code ASCII du caractère au centre est < a celui qu'on cherche
     * alors on positionne notre curseur au centre pour lire la suite
     * Sinon il entre le début et la moitié
     */
    lseek(file, 0, SEEK_CUR);
    nb = read(file, &c, 1);
    printf("c = %c", c);


    return 0;
}

// https://www.geeksforgeeks.org/lseek-in-c-to-read-the-alternate-nth-byte-and-write-it-in-another-file/
