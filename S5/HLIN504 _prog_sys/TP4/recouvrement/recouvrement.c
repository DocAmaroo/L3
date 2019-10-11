#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>

int main(int argc, char* const argv[]){
    printf("P1 avant recouvrement, [ nom : %s ], [ pid : %d]\n", argv[0], getpid());
    execl("/home/e20160004807/Cours/L3/S5/HLIN504 _prog_sys/TP4/recouvrement/recouvert", "filston", NULL);
}
