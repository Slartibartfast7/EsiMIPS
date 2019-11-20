#include "decodage.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
	lectureFichier("tests/in1.txt");
	printf("OPERANDE:%s\n",operande("SW $3,10($0)",1));
	return 0;
}