#include "decodage.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	if (argc != 3)
		printf("Usage: ./main [InputFile] [OutputFile]\n");
	else
		conversionFichier(argv[1], argv[2]);
	// printf("OPERANDE:%s\n",operande("SW $3,10($0)",1));
	// printf("%s\n",decodeInstruction("ADDI $8,$0,1"));
	return 0;
}
