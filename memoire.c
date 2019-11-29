#include "memoire.h"
#include <stdlib.h>
#include <stdio.h>

memoire* initMemoire(void)
//Initialise la liste chaînée représentant la mémoire
{
	memoire* memoireProc = (memoire*)malloc(sizeof(memoire));
	if(memoireProc == NULL) perror("Echec lors de la création de la mémoire");
	return memoireProc;
}

void ecritureMemoire(memoire* memoireProc, int adresse, int valeur)
//Ajoute une entrée à la mémoire à l'index correspondant à l'adresse indiquée
{
	// if(memoireProc != NULL)
	// {
	// 	memoire* suivant = memoireProc->suivant;
	// 	while(suivant->adresse < adresse)
	// 		suivant = memoireProc->suivant;
	// }
}

int lectureMemoire(memoire* memoireProc, int adresse)
//Renvoie la valeur présente dans la mémoire à l'index correspondant à l'adresse indiquée, -1 si l'index n'existe pas
{
	return 0;
}