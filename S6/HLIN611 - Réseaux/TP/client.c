#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>

int OCTET_RECEIVED = 0;

/* long message pour les test :
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Praesent congue nunc a eros venenatis aliquam. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Mauris euismod magna eu tempus feugiat. Aliquam dolor libero, sagittis a ligula ut, finibus pretium neque. Cras sit amet rutrum dui, vel cursus lacus. Phasellus lectus nisl, blandit in egestas id, auctor in nibh. Aliquam eleifend, tellus sed euismod porta, elit sapien molestie arcu, eget hendrerit lectus tortor at dolor. Nullam rutrum erat sit amet libero accumsan sagittis. Sed hendrerit justo nec augue tempus, at ornare dolor accumsan. Vivamus sed nunc sit amet lorem auctor consectetur. Morbi vel facilisis ex. Maecenas ultrices enim est, a sollicitudin quam viverra vitae. Donec vel euismod velit. Integer porttitor justo at orci interdum sodales. In accumsan est nec elementum scelerisque. Nunc gravida porta nisl, ac feugiat leo. Sed sodales, nisi eget gravida commodo, tortor nulla hendrerit magna, tincidunt tincidunt orci risus et quam. Donec ultricies enim non ex pellentesque, et elementum augue dictum. Suspendisse dapibus erat sit amet fermentum ornare. In ac hendrerit tortor. Sed dapibus, nulla ut tempus tincidunt, nunc est sagittis tortor, a dignissim lacus nisi vel sapien. Proin consequat eget elit vel imperdiet. Nam at eleifend velit. Fusce vel tortor et ligula elementum auctor. Nulla ornare ex ut quam dignissim semper. Sed vitae leo et risus luctus venenatis. Vivamus condimentum at sapien non varius. Aenean id urna porttitor, suscipit purus id, sollicitudin eros. Quisque in felis quis dolor condimentum facilisis. Proin quam lorem, facilisis sed suscipit at, fringilla in augue. Phasellus mattis sed nulla eu mollis. Phasellus eget purus auctor, tristique quam a, dignissim augue. Sed dolor eros, tristique vel ligula ut, euismod lacinia diam. Sed nec fermentum ante, id blandit nisi. Etiam eu sapien lacinia, pellentesque nibh non, faucibus nisl. Proin pretium magna massa, aliquet egestas tortor pharetra ac. Ut portti
*/

int sendTCP(int socket, char* msg, int size){

	int snd = 0, rcv = 0, reponse = 0;

	if ( strlen(msg) < size ){
		snd = send(socket, msg, strlen(msg), 0);
	} else {
		snd = send(socket, msg, size, 0);
	}

	if (snd == -1){
		return 0;
	} else {
		rcv = recv(socket, &reponse, sizeof(int), 0);

		if(rcv == -1) {
			perror("Erreur: ");
			exit(1);
		}
		else if(rcv == 0) {
			printf("Le socket a été fermé.\n");
			exit(1);
		} else {
			OCTET_RECEIVED += rcv;
		}
	}

	return 1;
}

int main(int argc, char *argv[]) {

	if (argc != 4){
		printf("utilisation : %s ip_serveur port_serveur nb_iterations\n", argv[0]);
		exit(0);
	}

	/* Etape 1 : créer une socket */
	int ds = socket(PF_INET, SOCK_STREAM, 0);

	if (ds == -1){
		printf("Client : pb creation socket\n");
		exit(1);
	}

	printf("Client : creation de la socket : ok\n");


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
	if (conn < 0){
		perror ("Client : pb au connect :");
		close (ds);
	}

	printf("Client : demande de connexion reussie \n");

	/* Etape 4 : envoyer un message au serveur. Ce message est une chaîne de caractères saisie au clavier. Vous pouvez utiliser une autre fonction pour la saisie. */

	int snd = 0,
	octetSended = 0,
	nbCallToSend = 0;

	printf("saisir un message à envoyer (moins de 1500 caracteres) \n");

	int sizeMax = 1500;
	char m[sizeMax+2];

	fgets(m, sizeof(m), stdin);
	m[strlen(m)-1]  = '\0';
	int nbOctet = strlen(m);

	// on envoit la taille du message au serveur
	snd = send(ds, &nbOctet, sizeof(int), 0);

	int i = 0;
	while (i < atoi(argv[3]) ){

		snd = sendTCP(ds, m, nbOctet);

		if ( snd ){
			octetSended += nbOctet;
		}

		nbCallToSend++;

		i++;
	}

	printf("\n____ Quota\n");
	printf("Client : Nombre d'appel à la fonction send = %i\n", nbCallToSend);
	printf("Client : Au total j'ai envoyé %i octets et le serveur me répond qu'il a reçu : %d octets \n", octetSended, OCTET_RECEIVED) ;
	printf("Client : La perte d'octets s'élève à %d%%\n", (100-(OCTET_RECEIVED*100)/octetSended) );

	close (ds);
	printf("Client : je termine\n");
}

// int recvTCP(int socket, char* msg, int size){

// 	int reponse = 0;
// 	int rcv = recv (socket, &reponse, size, 0);

// 	if(rcv == -1) {
// 		perror("Erreur: ");
// 		exit(1);
// 	}
// 	else if(rcv == 0) {
// 		printf("Le socket a été fermé.\n");
// 		exit(1);
// 	} else {
// 		return reponse;
// 	}
// }