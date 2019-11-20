#include "decodage.h"

char *decodeInstruction(char *bufEntree)
{
	int i;
	char *bufptrEntree = bufEntree;
	char bufptrSortie[33];
	char opcode[8];
	char *operandes[3];

	// Obtention de l'OPCODE
	i = 0;
	while (bufptr != ' ')
	{
		opcode[i] = bufptr;
		bufptr++;
		i++;
	}
	opcode[i] = '\0';

	i = 0;
	while (!strcmp(BIN_OPCODES[i], opcode))
	{
		i++;
	}

	bufptrSortie = *FCT_OPCODES[i](bufEntree);

	return bufptrSortie;
}

void lectureFichier(const char* fichierEntree)
{

}
