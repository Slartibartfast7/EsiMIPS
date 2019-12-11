#include "decodage.h"
#include "registre.h"
#include "memoire.h"
#include "instructions.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc != 3)
		printf("Usage: ./main [InputFile] [OutputFile]\n");
	else
	{
		TAILLE_PROGRAMME = 0;
		conversionFichier(argv[1], argv[2]);
		PC = DEBUT_PROGRAMME;
		HI = 0;
		LO = 0;
		while(PC != DEBUT_PROGRAMME + TAILLE_PROGRAMME)
		{
			decoderInstruction(recupererInstruction(PC));
			afficherRegistres();
			//afficherMemoire(memoire);
			PC += 4;
		}
	}

	return 0;
}
