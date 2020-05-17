#include <stdio.h>
#include <unistd.h> //fork(), getpid(),
#include <sys/types.h> //toutes
#include <sys/wait.h>

int main( int argc, char* const argv[] ){
    printf("> ");
    char cmd[30];
    scanf("%s", cmd);
    system(cmd);
}