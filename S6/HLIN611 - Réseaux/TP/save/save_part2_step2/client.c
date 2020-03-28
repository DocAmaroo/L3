	#include <stdio.h> 
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netdb.h>
	#include <stdlib.h>
	#include <arpa/inet.h>
	#include <string.h>

	/* Rôle du client : envoyer une demande de connexion à un serveur,
		envoyer une chaîne de caractères à ce serveur (la chaîne de
		caractère est à saisir au clavier), recevoir un entier et comparer
		cet entier avec le nombre d'octets envoyés. L'idée est de mettre en
		place les bases qui vous permettront par la suite une mise en
		oeuvre correcte des communications en TCP et de vérifier les
		échanges effectués */

	int main(int argc, char *argv[]) {

	/* je passe en paramètre l'adresse de la socket d'écoute du serveur
			(IP et numéro de port). Je teste donc le passage de parametres */

	if (argc != 3){
		printf("utilisation : %s ip_serveur port_serveur\n", argv[0]);
		exit(0);
	}

	/* Etape 1 : créer une socket */   
	int ds = socket(PF_INET, SOCK_STREAM, 0);

	/* /!\ : Il est indispensable de tester les valeurs de retour de
			toutes les fonctions et agir en fonction des valeurs possibles.*/
	if (ds == -1){
		printf("Client : pb creation socket\n");
		exit(1); // je choisis ici d'arrêter le programme car le reste
				// dépendent de la réussite de la création de la socket.
	}

	/* J'alimente le programme avec des traces d'exécution pour observer ce
			qui se produit à l'exécution et pour mieux localiser les erreurs. */
	printf("Client : creation de la socket : ok\n");

	// Je peux déjà tester l'exécution de cette étape avant de passer à la suite.

	/* Etape 2 : designer la socket du serveur : avoir une structure qui
			contient l'adresse de cette socket (IP + numéro de port. */
	struct sockaddr_in adrServ;
	adrServ.sin_addr.s_addr = inet_addr(argv[1]) ;
	adrServ.sin_family = AF_INET;
	adrServ.sin_port = htons(atoi(argv[2]));

	socklen_t lgAdr = sizeof(struct sockaddr_in);
		
	/* Etape 3 : envoyer une demande de connexion au serveur.*/
	int conn = connect(ds, (struct sockaddr *) &adrServ, lgAdr);

	// je traite les valeurs de retour
	if (conn <0){
		perror ("Client : pb au connect :");
		close (ds); // je libère les ressources avant de terminer.
		exit (1); // je choisi de quitter le programme : la suite dépend
				// de la réussite de l'envoi de la demande de connexion.
	}

	// je continue à alimenter le programme avec traces d'exécution
	printf("Client : demande de connexion reussie \n");

	// Je peux tester l'exécution de cette étape avant de passer à la suite.

	/* Etape 4 : envoyer un message au serveur. Ce message est une chaîne de caractères saisie au clavier. Vous pouvez utiliser une autre fonction pour la saisie. */
     
	int snd = 0, reponse = 0, rcv = 0, octetSended = 0, octetReceived = 0;

	printf("saisir un message à envoyer (moins de 200 caracteres) \n");
	
	int size_m = 1500;
	char m[size_m];

	fgets(m, sizeof(m), stdin);
	m[strlen(m)-1]  = '\0';
	int nbOctet = strlen(m);

	// on envoit la taille du message au serveur
	snd = send(ds, &nbOctet, sizeof(int), 0);

	for( int i=0; i<2; i++ ){
		
		if ( strlen(m) < size_m-1 ){

			snd = send(ds, m, strlen(m), 0);
		} else {
			snd = send(ds, m, size_m-1, 0);
		}
		if (snd == -1){
			perror("Client erreur : ");
			exit(1);
		}
		octetSended += snd;
	}

	printf("Client : envoi fait, j'attends la reponse du serveur \n");

	rcv = recv (ds, &reponse, sizeof(int), 0) ;
	
	if(rcv == -1) {
		perror("Erreur: ");
		exit(1);
	}
	else if(rcv == 0) {
		printf("Le socket a été fermé.\n");
		exit(1);
	}

	octetReceived += reponse;

	//printf("Client : Nombre d'appel à la fonction send = %i\n", appelToSend);
	printf("Client : Au total j'ai envoyé %i octets et le serveur me répond qu'il a reçu : %d octets \n", octetSended, octetReceived) ;
	printf("Client : La perte de paquet s'élève à %d%%\n", 100-(octetReceived*100)/octetSended );


	/* Etape 7 : je termine proprement. */

	close (ds);
	printf("Client : je termine\n");
}
