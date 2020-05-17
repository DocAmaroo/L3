#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

void gst(int s){
    printf("\nCRTL+C\n");
}

int main(){
    struct sigaction action;
    action.sa_handler = gst; //SIG_IGN pour ignorer l'évenement
    sigaction( SIGINT, &action, NULL);
    while(1);
    return 0;
}