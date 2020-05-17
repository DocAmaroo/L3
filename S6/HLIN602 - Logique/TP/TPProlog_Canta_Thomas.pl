/**
 * Logique 2 - TP Prolog
 *
 * Author : Canta Thomas (21607288) Gr.B
 * 
 * Copyright : 2020 Ⓒ
 */

% consult("TPProlog_Canta_Thomas").

% s(a,b).
% s(b,c).
% s(c,d).
% s(d,e).
% mi(X,Y,Z) :- s(X,Y), s(Y,Z).
% inf(X,Y) :- s(X,Y).
% inf(X,Z) :-  s(X,Y), inf(Y,Z).

%------------------------------------------------
% EXERCICE A
%------------------------------------------------
homme(alberto).
homme(jeanno).
homme(popaul).
homme(bertrand).
homme(louis).
homme(benoit).
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

%------------------------------------------------
% PREDICATS
%------------------------------------------------
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

%------------------------------------------------
% EXERCICE B
%------------------------------------------------
p([1|Z],Z).
q(X,Z) :- p(X,Y), p(Y,Z).

%------------------------------------------------
% EXERCICE C
%------------------------------------------------

%------------------------------------------------
% appartient
%------------------------------------------------
appartient(X, [X|_]).
appartient(X, [_|Y]) :- appartient(X, Y).

%------------------------------------------------
% non_appartient
%------------------------------------------------
non_appartient(X, L) :- not(appartient(X, L)).

%------------------------------------------------
% sans_repetition
%------------------------------------------------
sans_repetition([]).
sans_repetition([X|Y]) :- non_appartient(X,Y), sans_repetition(Y).

%------------------------------------------------
% ajout_tete
%------------------------------------------------
ajout_tete(X, L1, L2) :- [X|L1] == L2.

%------------------------------------------------
% ajout_queue
%------------------------------------------------
ajout_queue(X, [], [X]).
ajout_queue(X, [H|T], [H|L]) :- ajout_queue(X, T, L).

%------------------------------------------------
% supprimer
%------------------------------------------------
supprimer(L1, L2) :- L1 = L2.
supprimer(_, [], []).
supprimer(X, [X|Y], L2) :- supprimer(Y, L2).
supprimer(X, [H|T], [H|L]) :- supprimer(X, T, L).

%------------------------------------------------
% supprimer_fin
%------------------------------------------------
supprimer_fin([], []).
supprimer_fin([_|[]], []).
supprimer_fin([H|T], [H|L]) :- not([H|T] == [H|L]), supprimer_fin(T, L).

%------------------------------------------------
% fusion
%------------------------------------------------
fusion([], [], []).
fusion([], [X|T2], [X|T3]) :- fusion([], T2, T3).
fusion([X|T1], [], [X|T3]) :- fusion(T1, [], T3).
fusion([X1|T1], [X2|T2], [X1|[X2|T3]]) :- fusion(T1, T2, T3).

%------------------------------------------------
% concatener
%------------------------------------------------
concatener([], L, L).
concatener([X|T1], L2, [X|T2]) :- concatener(T1, L2, T2).

%------------------------------------------------
% inverser
%------------------------------------------------
inverser([], []).
inverser([X|T], L2) :- inverser(T, Y), concatener(Y, [X], L2).

%------------------------------------------------
% commun
%------------------------------------------------
commun(L1,L2,L3) :- commun_inter(L1,L2,[],L3).
commun_inter([],_,L3,L3).
commun_inter([X|L1],L2,L3m,L3):- appartient(X,L2) , not(appartient(X,L3m)), commun_inter(L1,L2,[X|L3m],L3),!.
commun_inter([_|L1],L2,L3m,L3) :- commun_inter(L1,L2,L3m,L3).

%------------------------------------------------
% ens
%------------------------------------------------
ens([],[]).
ens([X|L1],L2) :- appartient(X,L1),ens(L1,L2),!.
ens([X|L1],[X|L2]) :- ens(L1,L2).

%------------------------------------------------
% reunion
%------------------------------------------------
reunion2([], [], []).
reunion2([], [X|T2], [X|T3]) :- reunion2([], T2, T3).
reunion2([X|T1], L2, [X|T3]) :- reunion2(T1, L2, T3).
reunion(L1, L2, L3) :- sans_repetition(L1), sans_repetition(L2), reunion2(L1, L2, L3).

%------------------------------------------------
% reunionbis (non fonctionelle)
%------------------------------------------------
reunionbis2([], [], _).
reunionbis2([], [X|T2], [X|T3], 1) :- reunionbis2([], T2, T3).
reunionbis2([X|T1], L2, [X|T3], 1) :- reunionbis2(T1, L2, T3).
reunionbis(L1, L2, L3) :- reunionbis2(inverser(L1, _), inverser(L2, _), L3).