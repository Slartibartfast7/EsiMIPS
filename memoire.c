#include "memoire.h"
#include <stdlib.h>
#include <stdio.h>

void ecritureMemoire(int32_t* memoire, int32_t adresse, int32_t valeur)
//Ajoute une entrée à la mémoire à l'index correspondant à l'adresse indiquée
{
	memoire[adresse] = valeur;
}

int32_t lectureMemoire(int32_t* memoire, int32_t adresse)
//Renvoie la valeur présente dans la mémoire à l'index correspondant à l'adresse indiquée, -1 si l'index n'existe pas
{
	return memoire[adresse];
}

void afficherMemoire(int32_t* memoire)
{
	int i;
	printf("MEMOIRE :\n==========================================================\n");
	for(i = 0; i < TAILLE_MEMOIRE; i+=4)
	{
		printf("@%03d:\t%08X\t@%03d:\t%08X\t@%03d:\t%08X\t@%03d:\t%08X\n", i,memoire[i], i+1, memoire[i+1], i+2, memoire[i+2], i+3, memoire[i+3]);
	}
	printf("==========================================================\n");
}