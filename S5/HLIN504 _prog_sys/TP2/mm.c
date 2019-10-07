#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "mm.h"

/**
 * Crèe un nouveau jeu en générant aléatoirement un nouveau mot secret
 * composé de TAILLE lettres comprises entre 0 et 9.
 * @return un pointeur sur le jeu créé dans le tas (donc à detruire !)
 */

mm mm_creer(){
	srand (time(NULL));

	mm jeu = malloc(sizeof(struct mm));

	jeu->secret[TAILLE] = '\0';
	jeu->nbessais = 0;

	for (int i = 0; i < TAILLE; i++)
	{
		jeu->secret[i] = rand()%10 + '0';
	}

	for (int i = 0; i < TAILLE; i++)
	{
		printf("%c", jeu->secret[i]); 
	}
	printf("\n");
	return jeu;
}

/**
 * Supprime un jeu en désallouant la mémoire
 * @param mm un pointeur sur la structure de jeu
 */
void mm_detruire(mm jeu){
	free(jeu);
}

/**
 * teste un mot essai face au mot secret stocké dans le jeu
 * @param jeu un pointeur sur la structure de jeu
 * @param essai la chaîne de caractères proposée par le joueur humain
 * @returns un entier contenant (TAILLE+1)*nb lettres bien placées + nb lettres
 * mal placées; -1 si l'essai est erroné (nb lettres, ...)
 */
int mm_test(mm jeu, char* essai){
	
	int res = 0;
	int bien_place = 0;
	int mal_place = 0;

	/**
	 * @brief Teste si l'utilisateur donne bien 4 chiffres
	 * 
	 */
	if ( strlen(essai) != TAILLE ){
		return -1;
	}
	
	for (size_t i = 0; i < TAILLE; i++)
	{
		if ( essai[i] == jeu->secret[i]){
			bien_place++;
		}
		else{
			for (size_t j = 0; j < TAILLE; j++)
			{
				if ( essai[i] == jeu->secret[j] )
				{
					mal_place++;
				}
			}
		}
	}
	res = (TAILLE+1)*bien_place + mal_place;
	return res;
}

/** Retourne le nb d'essais déjà effectués 
 * @param jeu un pointeur sur la structure de jeu
 * @returns le nombre d'essais
 */
int mm_nbessais(mm jeu){
	return jeu->nbessais;
}

