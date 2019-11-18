#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void exercice1(){
    int tube[2];
    int p = pipe(tube);
    int cpt = 0;
    char c = 'a';
    while(1){
        write(tube[1], &c, sizeof(char));
        cpt++;
        printf("%i\n", cpt/1024);
    }
}

void crible(int* in){
    close(in[1]);
    int P;
    int r = read(in[0],&P,sizeof(int));
    if(r<=0){
        if(r<0)
            fprintf(stderr,"Erreur de read n°1.\n");
        return;
    }
    printf("p = %i\n", P);
    int out[2];
    if ( pipe(out) == -1 ){perror("Problème de tube dans crible");}
    pid_t f = fork();

    if ( f == 0 ){
        close(in[0]);
        crible(out);
    }
    else{
        if ( f > 0 ){
            close(out[0]);
            int i;
            while( r = read(in[0], &i, sizeof(int)) ){
                if(r<=0){
                    if(r<0)
                        fprintf(stderr,"Erreur de read n°1.\n");
                    return;
                }
                if ( i % P != 0 ){
                    write(out[1], &i, sizeof(int));
                }
            }
            close(in[0]);
            close(out[1]);
            wait(0);
        }
        else{
            printf("Erreur de fork()");
        }
    }
}

void eratosthene(int argc, const char* argv[]){
    int borne;
    if ( argc != 2 ){ fprintf(stderr, "Syntaxe : %s n\n", argv[0]); exit(1); }
    else if ( (borne = atoi(argv[1]) ) < 2 ){ fprintf(stderr, "Syntaxe : n entier < 2"); exit(2);}
    int tube[2];
    pid_t fils;
    if ( pipe(tube)==-1 ){ perror("Problème de tube"); exit(1); }
    switch(fils = fork()){
        case -1:
            printf("Error de fork()\n");
            exit(4);
            break;
        case 0:
            crible(tube);
            exit(0);
            break;
        default :
            close(tube[0]);
            for( int i = 2; i <= borne; i++ ){
                write(tube[1], &i, sizeof(int));
            }
            close(tube[1]);
            wait(0);
            break;
    }
}
int main(int argc, const char* argv[]){
    //exercice1();
    eratosthene(argc, argv);
    return 0;
}
