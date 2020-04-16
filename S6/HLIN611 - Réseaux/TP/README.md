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

Connecté (TCP) | Non connecté (UDP)
-------------- | ------------------
\- serveur se referme après chaque fin de réception du client | \+ serveur tourne en permanence
\+ unicité des sockets dédiées à chaque client (réduit les chances de conflits ?) | \- une seule socket pour tout les clients (risque de conflits ?)


