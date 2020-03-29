#include <stdio.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int OCTET_RECEIVED = 0;

int recvTCP(int socket, char* msg, int size){
	
	int rcv = recv (socket, msg, size, 0);

	if(rcv == -1) {

		perror("Erreur: ");
		return -1;
	
	}
	
	else if(rcv == 0) {
	
		printf("Le socket a été fermé.\n");
		return 0;
	
	} else {

		printf("Nb octet lus : %d\n", rcv);
		
		int snd = send(socket, &rcv, sizeof(int), 0);

		if (snd == -1){
			printf("Serveur : send n'a pas fonctionné\n");
		}

		OCTET_RECEIVED += size;
		printf("Serveur : j'ai reçu %d octets\n", OCTET_RECEIVED);
		return 1;
	}
}

int main(int argc, char *argv[]){

	if (argc<2){
		printf("utilisation: %s numero_port\n", argv[0]);
		exit(1);
	}

	/* Etape 1 : créer une socket (la socket qui permettra de recevoir
		les demandes de connexion.*/

	int ds = socket(PF_INET, SOCK_STREAM, 0);

	if (ds == -1){
		perror("Serveur : probleme creation socket");
		exit(1);
	}

	// J'alimente le programme avec traces d'exécution pour observer ce
	// qui se produit à l'exécution et mieux localiser les erreurs. 
	printf("Serveur : creation de la socket : ok\n");

	/* Etape 2 : nommer la socket. Elle aura une ou des IP de la machine
		sur laquelle le programme sera exécuté et le numéro de port passé
		en paramètre*/


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


	/* Etape 3 : mise en ecoute de la socket nommée. Cette opération
		dédie la socket à la réception des demandes de connexion. Pour
		cet exercice, limiter la file des demandes de connexions à 5. */

	int ecoute = listen(ds, 10);
	if (ecoute < 0){
		printf("Serveur : je suis sourd(e)\n");
		close (ds);
		exit (1);
	} 

	printf("Serveur : mise en écoute : ok\n");

	/* Etape 4 : attendre et traiter une demande de connexion d'un
		client. Rappel : lorsque le serveur accepte une demande de
		connexion, il crée une nouvelle socket. Cette dernière est
		connectée à celle du client et elle est à utiliser pour
		communiquer avec lui.*/

	printf("Serveur : j'attends la demande d'un client (accept) \n"); 

	struct sockaddr_in adCv ; // pour obtenir l'adresse du client accepté.
	socklen_t lgCv = sizeof (struct sockaddr_in);

	int dsCv = accept(ds, (struct sockaddr *) &adCv, &lgCv);
	if (dsCv < 0){
		perror ( "Serveur, probleme accept :");
		close(ds);
		exit (1);
	}

	printf("Serveur : le client %s:%d\n", inet_ntoa(adCv.sin_addr), ntohs(adCv.sin_port));

	/* Etape 5 : réception d'un message de type chaîne de caractères */

	int rcv = 0, taille = 0, nbCallToRecv = 0;

	char buffer[4000];

	//on récupère la taille du message
	rcv = recv(dsCv, &taille, sizeof(int), 0);
	
	if(rcv == -1) {
		perror("Erreur: ");
		exit(1);
	} else if(rcv == 0) {
		printf("Le socket a été fermé.\n");
		exit(1);
	}

	while(1){

		//on lit le message
		rcv = recvTCP(dsCv, buffer, taille);
		nbCallToRecv++;

		if ( rcv <= 0 ) {
			break;
		}
	}
	
	printf("Serveur : Nombre total d'appel à recv() = %d\n", nbCallToRecv);

	// Etape 7 : fermeture de la socket du client
	printf("Serveur : fin du dialogue avec le client\n");
	close (dsCv);

	// Etape 8 : pour cet exercice, je ne traite qu'un client, donc, je termine proprement.
	close (ds);
	printf("Serveur : je termine\n");
}
