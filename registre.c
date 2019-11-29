#include "registre.h"
#include <stdio.h>

void ecritureRegistre(int registre, int valeur)
//Ecrit la valeur indiquée dans le registre indiqué
{
	registreProc[registre] = valeur;
}

int lectureRegistre(int registre)
//Renvoie la valeur présente dans le registre indiquée
{
	return registreProc[registre];
}

void afficherRegistres(void)
//Affiche les valeurs des 32 registres et des registres HI et LO
{
	for(int i = 0; i < 32; i+=2)
		printf("@%2d:\t%02X\t\t@%2d:\t%02X\n", i,registreProc[i], i+1, registreProc[i+1]);
	printf("HI :\t%02X\t\tLO :\t%02X\n", HI,LO);
}