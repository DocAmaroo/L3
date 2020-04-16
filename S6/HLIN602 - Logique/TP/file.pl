%mémo cd("../../mydoc/classes/FAC/L3/S6/HLIN602 - Logique/TP").%
% s(a,b).
% s(b,c).
% s(c,d).
% s(d,e).
% mi(X,Y,Z) :- s(X,Y), s(Y,Z).
% inf(X,Y) :- s(X,Y).
% inf(X,Z) :-  s(X,Y), inf(Y,Z).

% ----------- Exercice A
homme(alberto).
homme(jeanno).
homme(popaul).
homme(bertrand).
homme(louis).
homme(benoit).
% homme(edgar).
femme(germaine).
femme(christianedelacompta).
femme(simone).
femme(marie).
femme(sophie).
femme(madeleinestmichel).
parent(alberto, jeanno).
parent(jeanno, popaul).
parent(popaul, bertrand).
parent(popaul, sophie).
parent(jeanno, simone).
parent(louis, benoit).
parent(popaul, edgar).
parent(germaine, jeanno).
parent(christianedelacompta, simone).
parent(christianedelacompta, popaul).
parent(simone, benoit).
parent(marie, bertrand).
parent(marie, sophie).
parent(madeleinestmichel, edgar).

%____ PREDICATS
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
ancetre(X,Y) :- parent(X,Y).
ancetre(X,Y) :- parent(X,A), ancetre(A,Y).
descendant(X,Y) :- parent(Y,X).
descendant(X,Y) :- parent(Y,A), descendant(X,A).
memefamille(X,Y) :- ancetre(A,X), ancetre(A,Y).

% ----------- Exercice B
q(X,Z) :− p(X,Y),p(Y,Z).
p([1|Z],Z).