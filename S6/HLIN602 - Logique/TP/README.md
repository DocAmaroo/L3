# Prolog

### Commande d'éxécution
```prolog
consult(filename).
%ou
consult("filename.pl").
```

## Exercice A
### (i)

```prolog
homme(alberto).
femme(benoit).
femme(X). 
hommme(X).
parent(marie, sophie).
femme(X), parent(X, jeanno).
parent(popaul, X).
homme(X), parent(X,Y)
```

### (ii)
```prolog
pere(X,Y) :- homme(X), parent(X,Y).
mere(X,Y) :- femme(X), parent(X,Y).
fils(X,Y) :- homme(Y), parent(X,Y).
fille(X,Y) :- femme(Y), parent(X,Y).
grand_pere(X,Y) :- pere(X,Z), parent(Z,Y).
grand_mere(X,Y) :- mere(X,Z), parent(Z,Y).
grandparent(X,Y) :- grand_pere(X,Y); grand_mere(X,Y).
frere(X,Y) :- homme(X), pere(Z,X), pere(Z,Y), mere(W,X), mere(W,Y).
soeur(X,Y) :- femme(X), pere(Z,X), pere(Z,Y), mere(W,X), mere(W,Y).
demifrere(X,Y) :- homme(X), not(frere(X,Y)), (pere(Z,X), pere(Z,Y); mere(W,X), mere(W,Y)).
demisoeur(X,Y) :- femme(X), not(soeur(X,Y)), (pere(Z,X), pere(Z,Y); mere(W,X), mere(W,Y)).
cousin(X,Y) :- not(soeur(X,Y)), not(frere(X,Y)), not(demifrere(X,Y)), not(demisoeur(X,Y)), grandparent(Z,X), grandparent(Z,Y).
```