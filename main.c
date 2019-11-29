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
	ecritureRegistre(2,15);
	afficherRegistres();
	printf("%X\n",lectureRegistre(2) );
	return 0;
}
