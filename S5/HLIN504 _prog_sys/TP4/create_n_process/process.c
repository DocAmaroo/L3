#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>

int main(int argc, char* const argv[]){
    int n = 0;
    do{
        printf("Combien de processus voulez-vous créer (> 2) ? ");
        scanf("%i",&n);
    }
    while( n <= 2 );

    pid_t pid;
    switch(pid = fork()){
        case -1:{ // echec du fork
            printf("Probleme : echec du fork") ;
            break ;
        }
        case 0:{  // c’est le descendant
            break ;
        }
        default:{  // c’est le parent
            break ;
        }
    }
}