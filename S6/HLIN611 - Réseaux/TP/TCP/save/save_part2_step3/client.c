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

	if (argc != 4){
		printf("utilisation : %s ip_serveur port_serveur nb_iterations\n", argv[0]);
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
     
	int snd = 0, reponse = 0, rcv = 0, 
	octetSended = 0, realOctetSended = 0,
	octetReceived = 0,
	nbCallToSend = 0;

	printf("saisir un message à envoyer (moins de 1500 caracteres) \n");
	
	int size_m = 1500;
	char m[size_m];

	fgets(m, sizeof(m), stdin);
	m[strlen(m)-1]  = '\0';
	int nbOctet = strlen(m);

	// on envoit la taille du message au serveur
	snd = send(ds, &nbOctet, sizeof(int), 0);

	int i = 0;
	while (i < atoi(argv[3]) ){

		if ( strlen(m) < size_m-1 ){
			snd = send(ds, m, strlen(m), 0);
		} else {
			snd = send(ds, m, size_m-1, 0);
		}

		printf("%d\n", snd);
		if (snd == -1){
			perror("Client erreur : ");
			exit(1);
		}

		nbCallToSend++;
		octetSended += snd;

		rcv = recv (ds, &reponse, sizeof(int), 0);

		if(rcv == -1) {
			perror("Erreur: ");
			exit(1);
		}
		else if(rcv == 0) {
			printf("Le socket a été fermé.\n");
			exit(1);
		}

		octetReceived += reponse;
		
		i++;
	}

	printf("\n____ Quota\n");
	printf("Client : Nombre d'appel à la fonction send = %i\n", nbCallToSend);
	printf("Client : Au total j'ai envoyé %i octets et le serveur me répond qu'il a reçu : %d octets \n", octetSended, octetReceived) ;
	printf("Client : La perte d'octets s'élève à %d%%\n", (100-(octetReceived*100)/octetSended) );

	close (ds);
	printf("Client : je termine\n");
}


/* long message pour les test :
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent congue nunc a eros venenatis aliquam. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Mauris euismod magna eu tempus feugiat. Aliquam dolor libero, sagittis a ligula ut, finibus pretium neque. Cras sit amet rutrum dui, vel cursus lacus. Phasellus lectus nisl, blandit in egestas id, auctor in nibh. Aliquam eleifend, tellus sed euismod porta, elit sapien molestie arcu, eget hendrerit lectus tortor at dolor. Nullam rutrum erat sit amet libero accumsan sagittis. Sed hendrerit justo nec augue tempus, at ornare dolor accumsan. Vivamus sed nunc sit amet lorem auctor consectetur. Morbi vel facilisis ex. Maecenas ultrices enim est, a sollicitudin quam viverra vitae. Donec vel euismod velit. Integer porttitor justo at orci interdum sodales. In accumsan est nec elementum scelerisque. Nunc gravida porta nisl, ac feugiat leo. Sed sodales, nisi eget gravida commodo, tortor nulla hendrerit magna, tincidunt tincidunt orci risus et quam. Donec ultricies enim non ex pellentesque, et elementum augue dictum. Suspendisse dapibus erat sit amet fermentum ornare. In ac hendrerit tortor. Sed dapibus, nulla ut tempus tincidunt, nunc est sagittis tortor, a dignissim lacus nisi vel sapien. Proin consequat eget elit vel imperdiet. Nam at eleifend velit. Fusce vel tortor et ligula elementum auctor. Nulla ornare ex ut quam dignissim semper. Sed vitae leo et risus luctus venenatis. Vivamus condimentum at sapien non varius. Aenean id urna porttitor, suscipit purus id, sollicitudin eros. Quisque in felis quis dolor condimentum facilisis. Proin quam lorem, facilisis sed suscipit at, fringilla in augue. Phasellus mattis sed nulla eu mollis. Phasellus eget purus auctor, tristique quam a, dignissim augue. Sed dolor eros, tristique vel ligula ut, euismod lacinia diam. Sed nec fermentum ante, id blandit nisi. Etiam eu sapien lacinia, pellentesque nibh non, faucibus nisl. Proin pretium magna massa, aliquet egestas tortor pharetra ac. Ut porttitor lorem at dapibus efficitur. Suspendisse odio nisi, volutpat nec turpis eu, facilisis auctor elit.
*/