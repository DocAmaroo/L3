#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {

    // test en cas d'erreur d'argument ou fichier inexistant
    if(argc != 2) {
        printf("You need to run this program with exactly one argument!\n");
        return 1;
    }

    int nb;
    int file = open("test.txt", O_RDONLY);
    int copy = open("output.txt", O_WRONLY);
    char* c;

    while ( 0 < ( nb = read(file, &c, 1) )){
        write(copy, &c, 1);
    }


    return 0;
}