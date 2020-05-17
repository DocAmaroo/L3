Un message qui met trop de temps à arriver (> TTL) ou qui passe par plus de routeur que prévus => perte du paquet
les couches transport communique entre elles autre que pour les paquets, notamment pour parler de son état
# Etape 2

## Constats
$\mathbb{N} :$ Taille du message (ici 8 octets = long int)
$\mathbb{K} :$ Taille du buffer de réception
$i \ \ :$ Nombres d'itérations


var \ protocole | TCP | UDP
--- | --- | ---
$\mathbb{K} < \mathbb{N}$ | Réception **complète** de chaque paquet $\color{green}✔$ <br> Nécessite plus d'appel à `recv()` pour pouvoir lire chaque paquet. | Réception **incomplète** de chaque paquet ❌ <br> Chaque message reçu est **tronqué** par $(\mathbb{N} - \mathbb{K})$ octets, ceci implique une perte de donnée de $(\mathbb{N} - \mathbb{K}) * i$ octets.
$\mathbb{K} \geqslant \mathbb{N}$ | Réception **complète** de chaque paquet $\color{green}✔$ <br> Si il y avait des paquets dans la *"file d'attente"*, le buffer se remplit entièrement en prenant une partie du message suivant, réduisant le nombre d'appel à `recv()` | Réception **complète** de chaque paquet $\color{green}✔$ <br> Chaque paquet est lu un par un donc le nombre d'appel à `recv()` $ = i$.

# Etape 3

## Types de mode

TCP | UDP
--- | ---
fiable | non fiable
ordre garanti | ordre non garanti
duplication impossible | duplication possible
mode connecté | mode non connecté
serveur se referme après chaque fin de réception du client | serveur tourne en permanence
unicité des sockets dédiées à chaque client (réduit les chances de conflits ?) | une seule socket pour tout les clients (risque de conflits ?)

## Exemple pour l'envoi d'un message

##### [TCP & UDP] Création de la socket (client & server)
```cpp
/* int socket(int domain, int type, int protocol);
 * --- -1 en cas d'erreur
 */
int ds = socket(PF_INET, SOCK_STREAM, 0); // TCP
int ds = socket(PF_INET, SOCK_DGRAM, 0); // UDP
```

##### [TCP & UDP] Désignation de la socket (client & server)
```cpp
// client
struct sockaddr_in adrServ;
adrServ.sin_family = AF_INET;
adrServ.sin_addr.s_addr = inet_addr(..server_addres_ip..); //argv[1]
adrServ.sin_port = htons(..server_port..); //atoi(argv[2])

// server
struct sockaddr_in server;
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons(..server_port..); //atoi(argv[1])
```

##### [TCP only] Nommage (server only)
```cpp
/* int bind(int socket, const struct sockaddr *addr, socklen_t addrlen);
 * --- -1 en cas d'erreur
 */
int bnd = bind(ds, (struct sockaddr*) &server, sizeof(server) ) //
```

##### [TCP only] Mise en écoute de la socket (server only)
```cpp
/* int listen(int socket, int backlog);
 * --- -1 en cas d'erreur
 */
int lst = listen(ds, 10);
```

##### [TCP only] Traitement de la demande de connexion (server only)
```cpp
struct sockaddr_in adCv ; // pour obtenir l'adresse du client accepté.
socklen_t lgCv = sizeof (struct sockaddr_in);

/* int accept(int socket, struct sockaddr *addr, socklen_t *addrlen);
 * --- -1 en cas d'erreur
 */
int dsCv = accept(ds, (struct sockaddr *) &adCv, &lgCv);
```

##### [TCP & UDP] Demande de connexion au server (client only)
```cpp
socklen_t lgAdr = sizeof(struct sockaddr_in); // on récupère la taille de l'adresse

/* int connect(int socket, const struct sockaddr *addr, socklen_t addrlen);
 * --- -1 en cas d'erreur
 */ 
int conn = connect(ds, (struct sockaddr *) &adrServ, lgAdr);
```

##### [TCP & UDP] Envoi & Réception d'un message
```cpp
/*
 * int send(int socket, const void *buffer, size_t length, int flags);
 * --- -1 en cas d'erreur
 * --- nombre d'octets envoyé sinon
 */
int snd = send(ds, buffer, strlen(buffer), 0); 

/*
 * int recv(int socket, const void *buffer, size_t length, int flags);
 * return :
 * --- -1 en cas d'erreur
 * --- nombre d'octets reçu sinon
 */
int rcv = recv (ds, &reponse, sizeof(int), 0); // -1 en cas d'erreur
```

