#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>

int main(int argc, char* const argv[]){
    printf("P2 après recouvrement, [ nom : %s ], [ pid : %d]\n", argv[0], getpid());
}
