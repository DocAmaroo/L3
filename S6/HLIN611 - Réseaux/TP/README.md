# Modèle OSI et TCP/IP

<table>
    <tr>
        <th> OSI </th>
        <th> Description </th>
        <th> TCP/IP </th>
    </tr>
    <tr>
        <td style="background-color:lightgreen"> Application </td>
        <td> Services applicatifs au plus proche des utilisateurs </td>
        <td style="background-color:lightgreen" rowspan="3"> Application </td>
    </tr>
    <tr>
        <td style="background-color:lightgreen"> Présentation </td>
        <td> Encode, encrypte, compresse les données utiles </td>
    </tr>
    <tr>
        <td style="background-color:lightgreen"> Session </td>
        <td> Etablit des sessions entre des applications </td>
    </tr>
    <tr>
        <td style="background-color:lightblue"> Transport </td>
        <td> Etablit, maintien et termine des sessions entre des périphériques terminaux </td>
        <td style="background-color:lightblue"> Transport </td>
    </tr>
    <tr>
        <td style="background-color:orange"> Réseau </td>
        <td> Adresse les interfaces globalement et détermine les meilleurs chemins à travers un inter-réseau </td>
        <td style="background-color:orange"> Internet </td>
    </tr>
    <tr>
        <td style="background-color:lightpink"> Liaison de données </td>
        <td> Adresse localement les interfaces, livre les informations localement, méthode MAC </td>
        <td rowspan="2" style="background-color:lightpink"> Accès au réseau </td>
    </tr>
    <tr>
        <td style="background-color:lightpink"> Physique </td>
        <td> Encodage du signal, câblage et connecteurs, spécifications physiques </td>
    </tr>
</table>

#### Plus en détail dans le modèle TCP/IP
##### Couche Application
- Elle est la couche de communication qui s’interface avec les utilisateurs.
- Exemples de protocoles applicatifs : HTTP, DNS, DHCP, FTP, …

*Matériel : Ordinateur*
##### Couche Transport
- Elle est responsable du dialogue entre les hôtes terminaux d’une communication.
- Les applications utiliseront TCP pour un transport fiable et UDP sans ce service.
- Les routeurs NAT et les pare-feu opèrent un filtrage au niveau de la couche transport.

*Matériel : Ordinateur, routeur NAT, pare-feux*
##### Couche Internet
- Elle permet de déterminer les meilleurs chemins à travers les réseaux en fonction des adresses IPv4 ou IPv6 à portée globale.
- Les routeurs transfèrent le trafic IP qui ne leur est pas destiné.

*Matériel : Routeurs*
##### Couche Accès au réseaux
- TCP/IP ne s’occupe pas de la couche Accès Réseau
- Elle organise le flux binaire et identifie physiquement les hôtes
- Elle place le flux binaire sur les supports physiques
- Les commutateurs, cartes réseau, connecteurs, câbles, etc. font partie de cette couche

*Matériel : Commutateurs, cartes d’interface réseau, câblage*

# Structure d'un en-tête IPV4
- Version : définit la version du paquet IP
- Service différenciés : Définit la priorité de chaque paquet.
- Des champs permettant d'identifier et valider le paquet
- Des champs gardant une trace des paquets qui ont été fragmentés lors d'une transmission sur un support avec un MTU _(Maximum Transmission Unit)_ inférieur
- TTL : valeur décrémenté à chaque passage à travers un routeur
- Protocoles : Indique le type de protocole de couche supérieur _(TCP / UDP )_
- Adresse IP source
- Adresse IP de destination

# Cheminement d'un paquet dans le modèle TCP/IP

Avant d'arriver à sa destination final un paquet aurait obtenu 4 en-têtes au total.

##### 1er en-tête : couche application
Il permet à deux ordinateurs de se comprendre. Il permet de savoir comment interpréter les données (type de compression, syntaxe...)

##### 2nd en-tête : couche transport
Il suis le message tout le long de son acheminement en s'adaptant si il rencontre des problèmes (bouchons / erreur). Le message peut-être découpé en plusieurs morceau pour respecter les normes de certains réseau

##### 3eme en-tête : couche réseau
Indique le chemin jusqu'au prochain routeur

##### 4eme en-tête : couche liaison
Permet de s'adapter au réseau par lequel il passe pour respecter le type de matériel (type de codage, niveau électrique...)


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

