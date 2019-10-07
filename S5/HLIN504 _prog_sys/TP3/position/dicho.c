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