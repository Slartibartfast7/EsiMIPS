#include "decodage.h"
#include "registre.h"
#include "memoire.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc != 3)
		printf("Usage: ./main [InputFile] [OutputFile]\n");
	else
		conversionFichier(argv[1], argv[2]);
	
	PC = DEBUT_PROGRAMME;
	ecritureMemoire(memoire, 12, 0x54, 8);
	ecritureMemoire(memoire, 24, 0x12345678, 32);
	afficherMemoire(memoire);
	return 0;
}
