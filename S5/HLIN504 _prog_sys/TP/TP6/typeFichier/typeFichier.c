#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    struct stat buffer;
    int res = lstat(argv[1], &buffer);
    if( res < 0){
        printf("ERROR");
        exit(0);
    }

    if ( S_ISREG( buffer.st_mode )){
        printf("je suis un fichier\n");
    }

    else if ( S_ISDIR( buffer.st_mode )){
        printf("je suis un dossier\n");
    }

    else if ( S_ISLNK( buffer.st_mode )){
        printf("je suis un lien\n");
    }

    else {
        printf("je suis autre chose\n");
    }
}