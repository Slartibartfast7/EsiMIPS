#include "decodage.h"
#include "registre.h"
#include "memoire.h"
#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	if (argc != 3)
		printf("Usage: ./main [InputFile] [OutputFile]\n");
	else
	{
		char entree = 0;
		TAILLE_PROGRAMME = 0;
		conversionFichier(argv[1], argv[2]);
		printf("Le programme fait %d octets\n", TAILLE_PROGRAMME);
		printf("Il se trouve en mémoire à partir de l'adresse %d\n", DEBUT_PROGRAMME);
		PC = DEBUT_PROGRAMME;
		HI = 0;
		LO = 0;
		while(PC != DEBUT_PROGRAMME + TAILLE_PROGRAMME + 4)
		{
			while(entree != 'n')
			{

				if(entree != '\n')
				{
					printf("Press\tn to go to the next instruction\n");
					printf("\tr to see the registers\n");
					printf("\tm to see the memory\n");
				}
				entree = getchar();
				switch(entree)
				{
					case('n'):system("clear");decoderInstruction(recupererInstruction(PC));PC += 4;break;
					case('r'):system("clear");afficherRegistres();;break;
					case('m'):system("clear");afficherMemoire(memoire);break;
				}
			}
			entree = 0;
		}
		system("clear");
		printf("Execution du programme terminée\n");
	}

	return 0;
}
