#include "decodage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *BIN_OPCODES[] = {"ADD", "ADDI", "AND", "BEQ", "BGTZ", "BLEZ", "BNE", "DIV", "J", "JAL", "JR", "LUI", "LW", "MFHI", "MFLO", "MULT", "NOP", "OR", "ROTR", "SLL", "SLT", "SRL", "SUB", "SW", "SYSCALL", "XOR"};
char *(*FCT_OPCODES[])(const char*) = {decode_add, decode_addi, decode_and, decode_beq, decode_bgtz, decode_blez, decode_bne, decode_div, decode_j, decode_jal, decode_jr, decode_lui, decode_lw, decode_mfhi, decode_mflo, decode_mult, decode_nop, decode_or, decode_rotr, decode_sll, decode_slt, decode_srl, decode_sub, decode_sw, decode_syscall, decode_xor};

char *decodeInstruction(char *bufEntree)
{
	int i;
	char *bufptrEntree = bufEntree;
	char *bufptrSortie;
	char opcode[8];

	// Obtention de l'OPCODE
	i = 0;
	while (bufptrEntree[i] != ' ')
	{
		opcode[i] = bufptrEntree[i];
		bufptrEntree++;
		i++;
	}
	opcode[i] = '\0';

	i = 0;
	while (!strcmp(BIN_OPCODES[i], opcode))
	{
		i++;
	}

	bufptrSortie = (*FCT_OPCODES[i])(bufEntree);

	return bufptrSortie;
}

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

char *decode_add(const char* instruction){return NULL;}
char *decode_addi(const char* instruction){return NULL;}
char *decode_and(const char* instruction){return NULL;}
char *decode_beq(const char* instruction){return NULL;}
char *decode_bgtz(const char* instruction){return NULL;}
char *decode_blez(const char* instruction){return NULL;}
char *decode_bne(const char* instruction) {return NULL;}
char *decode_div(const char* instruction){return NULL;}
char *decode_j(const char* instruction){return NULL;}
char *decode_jal(const char* instruction){return NULL;}
char *decode_jr(const char* instruction){return NULL;}
char *decode_lui(const char* instruction){return NULL;}
char *decode_lw(const char* instruction){return NULL;}
char *decode_mfhi(const char* instruction){return NULL;}
char *decode_mflo(const char* instruction){return NULL;}
char *decode_mult(const char* instruction){return NULL;}
char *decode_nop(const char* instruction){return NULL;}
char *decode_or(const char* instruction){return NULL;}
char *decode_rotr(const char* instruction){return NULL;}
char *decode_sll(const char* instruction){return NULL;}
char *decode_slt(const char* instruction){return NULL;}
char *decode_srl(const char* instruction){return NULL;}
char *decode_sub(const char* instruction){return NULL;}
char *decode_sw(const char* instruction){printf("Coucou\n");return NULL;}
char *decode_syscall(const char* instruction){return NULL;}
char *decode_xor(const char* instruction){return NULL;}