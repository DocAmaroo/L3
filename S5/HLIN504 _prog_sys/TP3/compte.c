#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void compte( size_t *buffer, char const *argv ){
    FILE* f = fopen(argv, "r");
    char c = fgetc(f);
    size_t res = 0;

    while( c != EOF ){
        res++;
        c = fgetc(f);
    }

    fclose(f);
}

int main(int argc, char const *argv[]){
    if ( argc < 2 ){
        printf("[ ERROR ] no file name give \n");
        exit(0);
    }

    char buffer = malloc(128*sizeof(char));
    compte(buffer, argv[1]);

    return 0;

}