#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>

int main(){
    pid_t pid;switch(pid = fork()){
        case -1:{ // echec du fork
            printf("Probleme : echec du fork") ;
            break ;
        }
        case 0:{  // c’est le descendant
            printf("du descendant : valeur de retour de fork() : %d\n", pid);
            printf("du descendant : je suis %d de parent %d \n", getpid(),getppid()) ;
            break ;
        }
        default:{  // c’est le parent
            printf("du parent : valeur de retour de fork() : %d\n", pid);
            printf("du parent : je suis %d de parent %d \n",getpid(), getppid());
            break ;
        }
    }
    printf("Qui suis-je ? : %d\n",getpid());
}
