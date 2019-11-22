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
	char *instructionHexa = malloc(9*sizeof(char));
	// Obtention de l'OPCODE
	i = 0;
	while (bufptrEntree[i] != ' ')
	{
		opcode[i] = bufptrEntree[i];
		i++;
	}
	opcode[i] = '\0';

	i = 0;
	while (strcmp(BIN_OPCODES[i], opcode))
	{
		printf("%d\n", i);
		i++;
	}

	bufptrSortie = (*FCT_OPCODES[i])(bufEntree);
	sprintf(instructionHexa,"%08X",(unsigned int)strtol(bufptrSortie, NULL, 2));
	return instructionHexa;
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
        printf("Ligne : %s\n", ligne);
        //ON LECRIT EN HEXA
        printf("Ligne décodé : %s\n", decodeInstruction(ligne));
    }
    fclose(fichier);
}

char* conversionBinaire(const int aConvertir, const int taille)
{
	//Convertit une valeur en binaire
	char* binaire = malloc((taille + 1)*sizeof(char));
	int i;
    for(i = taille-1; i >= 0; --i)
    {
        sprintf(binaire+(taille-1-i),"%c",(aConvertir & (1 << i)) ? '1' : '0');
    }
	binaire[(taille-1-i)] = '\0';
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

char *decode_add(const char* instruction)
{
	char* instructionBinaire = malloc(33*sizeof(char));
	int tOperande;

	sprintf(instructionBinaire, "000000");
	tOperande = (int)strtol(operande(instruction,2)+1,NULL, 10);
	sprintf(instructionBinaire+6, conversionBinaire(tOperande,5));
	tOperande = (int)strtol(operande(instruction,3)+1,NULL, 10);
	sprintf(instructionBinaire+6+5, conversionBinaire(tOperande,5));
	tOperande = (int)strtol(operande(instruction,1)+1,NULL, 10);
	sprintf(instructionBinaire+6+5+5, conversionBinaire(tOperande,5));
	sprintf(instructionBinaire+6+5+5+5, "00000");
	sprintf(instructionBinaire+6+5+5+5+5, "100000");
	//printf("%s\n", instructionBinaire);
	return instructionBinaire;
}
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
char *decode_sw(const char* instruction){return NULL;}
char *decode_syscall(const char* instruction){return NULL;}
char *decode_xor(const char* instruction){return NULL;}