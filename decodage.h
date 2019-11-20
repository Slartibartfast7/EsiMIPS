#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lectureFichier(const char* fichierEntree);
char* conversionBinaire(const int aConvertir, char* binaire);
char* operande(const char* instruction, int rangOperande);