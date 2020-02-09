#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>

//une var global
int status;

int main(){
    pid_t pid;

    int n = 4, tab[n];
    for (size_t i = 0; i < n; i++)
    {
        tab[i] = 0;
    }
    
    int patate = 3;
    status = 1;

    switch(pid = fork()){
        case -1:{ // echec du fork
            printf("Probleme : echec du fork") ;
            break ;
        }
        case 0:{  // c’est le descendant
            patate = 4;
            status = 2;
            for (size_t i = 0; i < n; i++)
            {
                tab[i] = 1;
            }
            printf("## VALEUR : \n[status = %d ]\n[patate = %d]\n", status, patate);
            for (size_t i = 0; i < n; i++)
            {
                printf("tab[%li] = %i\n", i, tab[i]);            
            }
            
            break ;
        }
        default:{  // c’est le parent
            printf("## Le processus fils c'est terminé, affichage du processus parent\n");

            int status;
            wait(&status);
            printf("## VALEUR : \n[status = %d ]\n[patate = %d]\n", status, patate);
            for (size_t i = 0; i < n; i++)
            {
                printf("tab[%li] = %i\n", i, tab[i]);            
            }
            break ;
        }
    }
}
