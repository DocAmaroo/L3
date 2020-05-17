#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

static int i = 1;

//Question 2
// void gst(int s){
//     printf("\nOn est sympa on te donne du temps\n");

//     switch(i){
//         case 1:
//             printf("5 sec de plus\n");
//             alarm(5);
//             break;
//         case 2:
//             printf("3 sec de plus\n");
//             alarm(3);
//             break;
//         case 3:
//             printf("Trop tard !\n");
//             exit(1);
//             break;            
//     }
//     i++;
// }

void gst(int s){

    static int i = 1;

    switch(i){
        case 1:
            printf("\nIl te reste 5s\n");
            alarm(2);
            break;
        case 2:
            printf("Il te reste 3s\n");
            alarm(2);
            break;
        case 3:
            printf("PLUS QU'UNE SECONDE !!! ( sans vouloir te foutre la pression hein ! )\n");
            alarm(1);
            break;
        case 4:
            printf("ET C'EST TERMINE !\n");
            exit(1);
            break;     
    }
    i++;
}


int main(){
    struct sigaction action;
    action.sa_handler = gst;
    action.sa_flags = SA_RESTART;
    sigaction( SIGALRM, &action, NULL);
    printf("REPOND A LA QUESTION VITTEEEE (10s)!!!");
    alarm(5);
    int i; scanf("%d", &i);
    alarm(0);
    return 0;
}