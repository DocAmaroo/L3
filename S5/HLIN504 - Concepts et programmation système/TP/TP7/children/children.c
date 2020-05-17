#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

void gst(int s){
    printf("J'ai perdu un enfant :'( \n");
}


int main(){
    struct sigaction action;
    action.sa_handler = gst;
    action.sa_flags = SA_RESTART;
    sigaction( SIGCHLD, &action, NULL);

    pid_t pid = fork();
    
    switch(pid){
        case -1:{ // echec du fork
            printf("Probleme : echec du fork\n") ;
            break ;
        }
        case 0:{  // c’est le descendant
            printf("je vais mourir : je suis %d de parent %d \n", getpid(),getppid()) ;
            break ;
        }
        default:{  // c’est le parent
            printf("Père [ %d ]\n", getppid());
            pid = fork();
            wait(NULL);
            switch(pid){
                case 0:{
                    printf("je vais mourir : je suis %d de parent %d \n", getpid(),getppid());
                    break;
                }
                default:{
                    printf("[ pass ] C'est le père\n");
                    wait(NULL);
                    break;
                }
            }
            break ;
        }
    }

    return 0;
}