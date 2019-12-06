#include "registre.h"
#include <stdio.h>

void ecritureRegistre(uint32_t registre, uint32_t valeur)
//Ecrit la valeur indiquée dans le registre indiqué
{
	registreProc[registre] = valeur;
}

uint32_t lectureRegistre(uint32_t registre)
//Renvoie la valeur présente dans le registre indiquée
{
	return registreProc[registre];
}

void afficherRegistres(void)
//Affiche les valeurs des 32 registres et des registres HI et LO
{
	int i;
	printf("REGISTRES :\n==========================================================\n");
	for(i = 0; i < 32; i+=2)
		printf("@%02d:\t%08X\t\t@%02d:\t%08X\n", i,registreProc[i], i+1, registreProc[i+1]);
	printf("HI :\t%08X\t\tLO :\t%08X\n", HI,LO);
	printf("==========================================================\n");
}