#include <stdio.h>
#include <stdlib.h>
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

    pid_t nPid;
    for( int i=0; i < n; i++){
        if ((nPid = fork())==0){
            printf("un nouveau descendant %i  de parent %i ! i=%i\n",getpid(), getppid(),i);
            
            // c'est peut être pas ouf mais ça marche
            char* pid;
            pid += sprintf(pid, "%d", getpid());
            execl("/bin/kill", "kill", "-9", pid, NULL);
        }
        else{
            int status;
            wait(&status); //chaque parent attend la fin de ses enfants}
        }
    }
}