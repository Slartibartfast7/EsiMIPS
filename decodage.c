#include "decodage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// char *decodeInstruction(char *bufEntree)
// {
// 	int i;
// 	char *bufptrEntree = bufEntree;
// 	char bufptrSortie[33];
// 	char opcode[8];
// 	char *operandes[3];

// 	// Obtention de l'OPCODE
// 	i = 0;
// 	while (bufptr != ' ')
// 	{
// 		opcode[i] = bufptr;
// 		bufptr++;
// 		i++;
// 	}
// 	opcode[i] = '\0';

// 	i = 0;
// 	while (!strcmp(BIN_OPCODES[i], opcode))
// 	{
// 		i++;
// 	}

// 	bufptrSortie = *FCT_OPCODES[i](bufEntree);

// 	return bufptrSortie;
// }

void lectureFichier(const char* fichierEntree)
{
	//Ouvre le fichier d'entrée, traduit chacune des lignes en hexadécimale
	int lecture;
	size_t taille = 20;
	char* ligne = (char *)malloc(taille * sizeof(char));
	FILE* fichier = fopen(fichierEntree, "r");
	if(fichier == NULL) perror("Problème lors de l'ouverture du fichier");
	while((lecture = getline(&ligne, &taille, fichier)) != -1)
	{
        printf("Ligne : %s", ligne);
        //ON LECRIT EN HEXA
    }
    fclose(fichier);
}

char* conversionBinaire(const int aConvertir, char* binaire)
{
	//Convertit une valeur < à 256 en binaire
	int i;
    for(i = 7; i >= 0; --i)
    {
        sprintf(binaire+(7-i),"%c",(aConvertir & (1 << i)) ? '1' : '0');
    }
	binaire[(7-i)] = '\0';
	return binaire;
}

char* operande(const char* instruction, int rangOperande)
//A partir d'une instruction, donne l'opérande indiquée
{
	char* testFrontiere = malloc(20*sizeof(char));
	int i;
	testFrontiere = strchr(instruction, ' ') + 1;
	for(i = 0; i < rangOperande -1; i++)
		testFrontiere = strpbrk(testFrontiere, ",(") + 1;
	i = 0;
	while(testFrontiere[i] != ',' && testFrontiere[i] != '(' && testFrontiere[i] != ')' && i<strlen(testFrontiere))
		i++;
	char* operande = malloc(sizeof(char)*(i+1));
	strncpy(operande,testFrontiere,i);
	operande[i] = '\0';
	return operande;
}

void decode_add(const char* instruction);
void decode_addi(const char* instruction){}
void decode_and(const char* instruction){}
void decode_beq(const char* instruction){}
void decode_bgtz(const char* instruction){}
void decode_blez(const char* instruction){}
void decode_bne(const char* instruction) {}
void decode_div(const char* instruction){}
void decode_j(const char* instruction){}
void decode_jal(const char* instruction){}
void decode_jr(const char* instruction){}
void decode_lui(const char* instruction){}
void decode_lw(const char* instruction){}
void decode_mfhi(const char* instruction){}
void decode_mflo(const char* instruction){}
void decode_mult(const char* instruction){}
void decode_nop(const char* instruction){}
void decode_or(const char* instruction){}
void decode_rotr(const char* instruction){}
void decode_sll(const char* instruction){}
void decode_slt(const char* instruction){}
void decode_srl(const char* instruction){}
void decode_sub(const char* instruction){}
void decode_sw(const char* instruction){}
void decode_syscall(const char* instruction){}
void decode_xor(const char* instruction){}
