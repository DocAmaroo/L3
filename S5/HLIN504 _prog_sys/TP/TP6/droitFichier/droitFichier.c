#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main( int argc, char* const argv[]){

    if ( argc != 2 ){
        printf("[Error] Pas de fichier donné en paramètre\n");
        exit(0);
    }

    struct stat buffer;
    int res = lstat(argv[1], &buffer);

    if ( res < 0 ){
        printf("[Error] Fichier incorrect !\n");
        exit(0);
    }

    (buffer.st_mode & S_IRUSR)? printf("r") : printf("-");
    (buffer.st_mode & S_IWUSR)? printf("w") : printf("-");
    (buffer.st_mode & S_IXUSR)? printf("x") : printf("-");
    (buffer.st_mode & S_IRGRP)? printf("r") : printf("-");
    (buffer.st_mode & S_IWGRP)? printf("w") : printf("-");
    (buffer.st_mode & S_IXGRP)? printf("x") : printf("-");
    (buffer.st_mode & S_IROTH)? printf("r") : printf("-");
    (buffer.st_mode & S_IWOTH)? printf("w") : printf("-");
    (buffer.st_mode & S_IXOTH)? printf("x") : printf("-");

    printf("\n");
    return 0;

}