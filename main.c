#include "decodage.h"
#include "registre.h"
#include "memoire.h"
#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mode_pas_a_pas(char *inputFile)
{
	char entree = 0;
	TAILLE_PROGRAMME = 0;
	conversionFichier(inputFile, NULL);
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

void mode_test(char *inputFile, char *outputFile)
{
	conversionFichier(inputFile, outputFile);
}

void mode_interactif()
{

}

int main(int argc, char const *argv[])
{
	int i;
	char *inputFile;
	char *outputFile;

	for (i = 1; i < argc; i++)
	{
		if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) // aide
		{
			printf("Usage (interactif): ./emul-mips\n");
			printf("Usage (mode pas à pas): ./emul-mips -pas [InputFile]\n");
			printf("Usage (tests unitaires): ./emul-mips -tests [InputFile] [OutputFile]\n");
			break;
		}
		else if (!strcmp(argv[i], "-pas")) // mode pas à pas
		{
			if (argc != 3)
				printf("Usage (mode pas à pas): ./emul-mips -pas [InputFile]\n");
			else
			{
				inputFile = argv[(i == 2 ? 3 : 2)];
				mode_pas_a_pas(inputFile);
			}
			break;
		}
		else if (!strcmp(argv[i], "-tests")) // mode tests unitaires
		{
			if (argc != 4)
				printf("Usage (tests unitaires): ./emul-mips -tests [InputFile] [OutputFile]\n");
			else
			{
				inputFile = argv[(i == 2 ? 3 : 2)];
				outputFile = argv[(i == 2 ? 4 : 3)];
				mode_test(inputFile, outputFile);
			}
			break;
		}
		else // mode interactif
		{
			mode_interactif();
			break;
		}
	}

	return 0;
}
