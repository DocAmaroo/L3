#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>


int recvTCP(int socket, char *buffer, size_t length, unsigned int *nbBytesReceved, unsigned int * nbCallRecv){

  int received = 1;
  int nbBytes = length;

  while(received == 1){
    
    received = recv(socket, buffer, length, 0);

    if (received <= 0){
      return received;
    }

    buffer += received;
    nbBytes -= received;

    (*nbBytesReceved) += received;
    (*nbCallRecv)++;
  }
  
  return 1;
}

int main(int argc, char *argv[])
{
	 
 // ajout d'un paramètre
  if (argc<3){
    printf("utilisation: %s numero_port taille_param_recv\n", argv[0]);
    exit(1);
  }
  
/*  Création de la socket d'écoute, nomage et mise en écoute.*/
 
  int ds = socket(PF_INET, SOCK_STREAM, 0);


  // Penser à tester votre code progressivement.
  if (ds == -1){
    perror("Serveur : probleme creation socket");
    exit(1);
  }

  printf("Serveur : creation de la socket : ok\n");

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(atoi(argv[1]));

  if(bind(ds, (struct sockaddr*) &server, sizeof(server)) < 0){
    perror("Serveur : erreur bind");
    close(ds);
    exit(1);
  }

  printf("Serveur : nommage : ok\n");
  
  int ecoute = listen(ds, 10);
  if (ecoute < 0){
    printf("Serveur : je suis sourd(e)\n");
    close (ds);
    exit (1);
  } 

  printf("Serveur : mise en écoute : ok\n");
  printf("Serveur : j'attends la demande d'un client (accept) \n");

  while(1){
    struct sockaddr_in adCv ; // pour obtenir l'adresse du client accepté.
    socklen_t lgCv = sizeof (struct sockaddr_in);

    int dsCv = accept(ds, (struct sockaddr *) &adCv, &lgCv);
    if (dsCv < 0){
      perror ( "Serveur : probleme accept :");
      close(ds);
      exit (1);
    }

    printf("Serveur : le client %s:%d\n", inet_ntoa(adCv.sin_addr), ntohs(adCv.sin_port));

    /* Réception de messages, chaque message est un long int */
  
    long int messagesRecus[500]; // pour recevoir plusieurs éléments en bloc (jusqu'à 4000 octets)

    unsigned int nbTotalOctetsRecus = 0;
    unsigned int nbAppelRecv = 0;

    while(1){ 

      // je n'ai pas besoin de garder tous les messages, j'écrase les précédents.
      int rcv = recvTCP(dsCv, (char*)messagesRecus, atoi(argv[2]), &nbTotalOctetsRecus, &nbAppelRecv);  

      /* Traiter TOUTES les valeurs de retour (voir le cours ou la documentation). */
      if (rcv < 0){ 
        perror ("Serveur : probleme reception :");
        close(dsCv);
        break;
      }
      if (rcv == 0)
      {
        printf("Serveur : la socket a été fermée\n");
        close(dsCv);
        break;
      }

      printf("Serveur : j'ai reçu au total %d octets avec %d appels à recv \n", nbTotalOctetsRecus, nbAppelRecv);
    }
  }
  
  printf("Serveur : je termine\n");
  close(ds);
}








