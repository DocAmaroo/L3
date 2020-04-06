# Résolution pour le calcul des prédicats
---

## Règles de résolution

### Distributivité du $\forall$

#### Sur le $\land$
Pour toutes formules F et G et pour toute variable x, on a :
$$(i) : ({\forall}xF) {\land} ({\forall}xG) \equiv {\forall}x(F{\land}G) : (ii)$$

#### Sur le $\lor$
$$(i) : ({\forall}xF) {\lor} ({\forall}xG) \equiv {\forall}x(F{\lor}G) : (ii)$$

Cette formule n'est pas toujours vrai.
Si on prend $F = P(x)$ et $G = I(x)$ avec :
&emsp; $P(x) : {\forall}x \in \mathbb{N}\ | \ x \ est \ pair$
&emsp; $I(x) : {\forall}x \in \mathbb{N}\ | \ x \ est \ impair$
On a bien $(ii)$ (tout entier est pair ou impair) mais on à pas $(i)$ (il faux que tout entier soit pair ou que tout entier soit impair).

### Distributivité du $\exists$
#### Sur le $\land$
$$(i) : ({\exists}xF) {\land} ({\exists}xG) \equiv {\exists}x(F{\land}G) : (ii)$$
Cette formule n'est pas toujours vrai.
Si on prend $F = P(x)$ et $G = I(x)$ avec :
&emsp; $P(x) : {\forall}x \in \mathbb{N}\ | \ x \ est \ pair$
&emsp; $I(x) : {\forall}x \in \mathbb{N}\ | \ x \ est \ impair$
On a bien $(i)$ (il existe un entier pair et il existe un entier impair) mais on à pas $(ii)$ (il n'existe pas d'entier qui soit pair et impair).

#### Sur le $\lor$
Pour toutes formules F et G et pour toute variable x, on a :
$$(i) : ({\exists}xF) {\lor} ({\exists}xG) \equiv {\exists}x(F{\lor}G) : (ii)$$

### Formes prénexes
#### Commutations
> $\neg({\forall}xF)\equiv{\exists}x({\neg}F)$
> $\neg({\exists}xF)\equiv{\forall}x({\neg}F)$

#### "Remontée" des quantificateurs
Soit x une variable qui **n'apparrait pas** dans G _(qui ne soit pas libre dans G suffit)_ alors :

> $(\forall xF) \land G \equiv \forall x (F \land G)$
> $(\exists xF) \land G \equiv \exists x (F \land G)$
> 
> $(\forall xF) \lor G \equiv \forall x (F \lor G)$
> $(\exists xF) \lor G \equiv \exists x (F \lor G)$
>
> $(\forall xF) \implies G \equiv \exists x (F \implies G)$
> $(\exists xF) \implies G \equiv \forall x (F \implies G)$
> $G \implies (\forall xF) \equiv \forall x (F \implies G)$
> $G \implies (\exists xF) \equiv \exists x (F \implies G)$

### Forme de Skolem
Le but de la forme Skolem est de simplifié l'écriture de notre langage.
Soit $F$ une formule prénexe
Supposons $F$ est satisfiable <small>(il existe une interprétation qui rend F vraie)</small>
Lorsqu'on à un quantificateur $\exists s$, la ou les valeurs de $s$ qui rendent $F$ vraie dépendent des variables quantifiées universellement $(\forall)$ qui précèdent $\exists s$

#### Fonction de Skolem
Prenons un exemple :

$$\exists x \ \exists y \ \forall z \ \exists w \ \exists u \ \exists v\ ((R(x,y) \implies ((\neg F(z,u,v)) \lor K(w))) \land G(v))$$

Se transforme en :

$$ ((R(a,b) \implies ((\neg F(z,u,f(z,u))) \lor K(g(z)))) \land G(f(z,u)))$$

$a, b$ : deux constantes
$g$ : un nouveau symbole de fonction à 1 argument
$f$ : un nouveau symbole de fonction à 2 arguments

On peut éliminer les quantificateur existentielles $(\exists)$ et obtenir la formule suivant :
$$ \forall z \ \forall u \ ((R(a,b) \implies ((\neg F(z,u,f(z,u))) \lor K(g(z)))) \land G(f(z,u)))$$

#### Satisfiabilité
Soit $G$ une formule sous forme prénexe
Soit $G'$ la forme Skolem de $G$
> $G$ satisfiable $\iff G'$ est satisfiable

### Forme Clausale
Lorsqu'une formule est sous forme Skolem, la partie sans quantificateurs peut se mettre sous forme normal conjonctive :
$$ \forall x \ \forall y ... \ (C_1 \land ... \ \land C_n) \equiv (\forall x \ \forall y ... \ C_1)  \land ... \ \land (\forall x \ \forall y ... \ C_n)) $$

On peut aussi écrire l'ensemble des solutions de la forme clausale comme suit :
$S = \{C_1, ..., C_n\}$

#### Théorème de Herbrand
On voudrait montrait qu'une formule $F$ est **insatisfiable**.
D'après ce qui précède il suffit de montrer que sa **forme clausale** est **insatisfiable** et pour cela on utilise le théorème de Herbrand.

> Une forme clausale est insatisfiable $\iff$ il est possible de remplacer dans chaque clause les variables par des *termes de Herbrand* tel que l'ensemble des clauses obtenues soit inconsistant.

Les termes de Herbrand sont les termes obtenus à partir des constantes et des fonctions.
Par exemple de ce qu'on a obtenus précédemment : $f(z,u)$, $g(z)$

<small> On pourrait avoir des formes plus compliqué comme : $f(g(\alpha), \beta)$</small>

### Unification
Soient $t_1, t_2$ deux termes.
>Unifier $t_1$ et $t_2$ consiste à trouver une subsitution des variables qui les rendent égaux.
Exemples :
1. Soient $t_1$ = $f(x, g(y))$ et $t_2$ = $f(g(u), g(z))$.
Prenons la substitution suivante :
$\sigma : x \mapsto g(u)$
$\ \ \ \ \ \ z \mapsto y$ 
On a bien $\sigma t_1 = f(g(u), g(y)) = \sigma t_2$.
$\,$
2. Soient $t_1$ = $f(x, g(y))$ et $t_2$ = $f(g(u), h(z))$.
Il n'y a pas de substitution unifiant ces deux termes !
Seules **les variables** sont **substituables**, or ici cela imposerait que $g = h$.
$\,$
3. Soient $t_1$ = $h(x, g(x), x)$ et $t_2$ = $h(g(u), g(g(z)), z)$.
Pour unifier ces termers, il faut que $x = g(u) = z$.
De plus il faudrait que $g(x) = g(g(z))$ et donc $g(z) = x$.
Ceci entraîne $z = g(z)$ ce qui n'est pas possible.

#### Unification de formules
>L'unification sur les formules permet de transformer deux formules atomiques $R(...)$ et $(\neg R(...))$ de sorte que l'une soit la négation de l'autre.

Par exemple unifions :

$$ R(f(x,x)), g(z)) \ et \ (\neg R(f(u,g(v)), g(u))) $$

Prenons la substitution suivante :
$\sigma : u \mapsto z$
$\ \ \ \ \ \ u \mapsto x, g(v)$

On obtient donc :
$$ R(f(g(v),g(v))), g(g(v))) \ et \ (\neg R(f(g(v),g(v)), g(g(v)))) $$

### Méthode de résolution
Pour prouver par résolution que la conjonction des $C_i$ entraîne la disjonction des $B_i$ $((\land C_i) \implies (\lor B_i))$.
Autrement dit que :

$$C_1,...,C_n \vdash B_1, ..., B_n$$

On cherche une contradiction dans la conjonction :

$$ C_1,...,C_n, (\neg B_1), ..., (\neg B_n) $$

Pour ce faire la méthode est la suivante :
1. Ecrire chaque $C_i$ et $(\neg B_j)$ comme une clause $C_k$ et utiliser des variables différentes dans les diverses clauses.
2. Unifier <small>_(éventuellement)_</small> plusieurs atomes positifs d'une clause et plusieurs atomes négatifs d'une autres clause <small>(_plusieurs sinon la méthode n'est pas complète_)</small>.
3. Simplifier les deux clauses unifiées.

Le but final est de montrer que les hypothèses plus la négation du but sont contradictoire