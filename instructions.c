#include "instructions.h"
#include "memoire.h"
#include "registre.h"
#include <stdio.h>

int OPCODES_R[] = {32, 36, 26, 8, 16, 18, 24, 37, 2, 0, 42, 2, 34, 12, 38};
int OPCODES_IJ[] = {8, 4, 7, 6, 5, 2, 3, 15, 35, 43};
void (*FCT_OPCODES_EXEC_R[])(int32_t) = {executer_add, executer_and, executer_div, executer_jr, executer_mfhi, executer_mflo, executer_mult, executer_or, executer_rotr, executer_sll, executer_slt, executer_srl, executer_sub, executer_syscall, executer_xor};
void (*FCT_OPCODES_EXEC_IJ[])(int32_t) = {executer_addi, executer_beq, executer_bgtz, executer_blez, executer_bne, executer_j, executer_jal, executer_lui, executer_lw, executer_sw};

int32_t recupererInstruction(int adresse)
{
	int32_t instruction = 0;
	if(adresse < DEBUT_PROGRAMME) perror("Mauvaise adresse");
	if(adresse % 4 != 0) perror("Adresse non alignée");
	instruction += (lectureMemoire(memoire, adresse) << 24);
	instruction += (lectureMemoire(memoire, adresse+1) << 16);
	instruction += (lectureMemoire(memoire, adresse+2) << 8);
	instruction += lectureMemoire(memoire, adresse+3);
	return instruction;
}
void decoderInstruction(int32_t instruction)
{
	int i;
	//printf("%08X\n", instruction);
	if((instruction & 0xFC000000) == 0) //R-Type
	{
		for(i = 0; i < sizeof(OPCODES_R)/sizeof(int); i++)
		{
			if((instruction & 0x3F) == OPCODES_R[i])
			{
				if(instruction == 0)
					executer_nop(instruction);
				else if((instruction & 0x3F) == 2)
				{
					if(instruction & 0x00200000)
						executer_rotr(instruction);
					else
						executer_srl(instruction);
					break;
				}
				else
					(*FCT_OPCODES_EXEC_R[i])(instruction);
			}
		}
	}
	else //I/J-Type
	{
		for(i = 0; i < sizeof(OPCODES_IJ)/sizeof(int); i++)
		{
			if(((instruction & 0xFC000000) >> 26) == OPCODES_IJ[i])
				(*FCT_OPCODES_EXEC_IJ[i])(instruction);
		}
	}
}

void executer_add(int32_t instruction)
{
	printf("C'est un ADD $%d,$%d,$%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
	//Integer Overflow ??
	int32_t temp;
	temp = lectureRegistre((instruction & 0x03E00000) >> 21) + lectureRegistre((instruction & 0x001F0000) >> 16);
	ecritureRegistre((instruction & 0x0000F800) >> 11,temp);
}
void executer_addi(int32_t instruction)
{
	printf("C'est un ADDI $%d,$%d,%d\n", (instruction & 0x001F0000) >> 16, (instruction & 0x03E00000) >> 21, (int16_t)(instruction & 0x0000FFFF));
	//Integer Overflow ??
	int32_t temp;
	temp = lectureRegistre((instruction & 0x001F0000) >> 16) + lectureRegistre((instruction & 0x03E00000) >> 21) + (int16_t)(instruction & 0x0000FFFF);
	ecritureRegistre((instruction & 0x001F0000) >> 16,temp);
}
void executer_and(int32_t instruction)
{
	printf("C'est un AND $%d,$%d,$%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
	ecritureRegistre((instruction & 0x0000F800) >> 11,lectureRegistre((instruction & 0x03E00000) >> 21) & lectureRegistre((instruction & 0x001F0000) >> 16));
}
void executer_beq(int32_t instruction)
{
	printf("C'est un BEQ $%d,$%d,%d\n", (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16, (int16_t)(instruction & 0x0000FFFF));
	if (lectureRegistre((instruction & 0x03E00000) >> 21) == lectureRegistre((instruction & 0x001F0000) >> 16))
		PC += ((int16_t)(instruction & 0x0000FFFF) << 2);
}
void executer_bgtz(int32_t instruction)
{
	printf("C'est un BGTZ $%d,%d\n", (instruction & 0x03E00000) >> 21, (int16_t)(instruction & 0x0000FFFF));
	if (lectureRegistre((instruction & 0x03E00000) >> 21) > 0)
		PC += ((int16_t)(instruction & 0x0000FFFF) << 2);
}
void executer_blez(int32_t instruction)
{
	printf("C'est un BLEZ $%d,%d\n", (instruction & 0x03E00000) >> 21, (int16_t)(instruction & 0x0000FFFF));
	if (lectureRegistre((instruction & 0x03E00000) >> 21) <= 0)
		PC += ((int16_t)(instruction & 0x0000FFFF) << 2);
}
void executer_bne(int32_t instruction)
{
	printf("C'est un BNE $%d,$%d,%d\n", (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16, (int16_t)(instruction & 0x0000FFFF));
	if (lectureRegistre((instruction & 0x03E00000) >> 21) != lectureRegistre((instruction & 0x001F0000) >> 16))
		PC += ((int16_t)(instruction & 0x0000FFFF) << 2);
}
void executer_div(int32_t instruction)
{
	printf("C'est un DIV $%d,$%d\n", (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
	int32_t q,r;
	if((lectureRegistre((instruction & 0x001F0000) >> 16)) != 0)
	{
		q = ((lectureRegistre((instruction & 0x03E00000) >> 21)) / (lectureRegistre((instruction & 0x001F0000) >> 16)));
		r = ((lectureRegistre((instruction & 0x03E00000) >> 21)) % (lectureRegistre((instruction & 0x001F0000) >> 16)));
	}
	LO = q;
	HI = r;
}
void executer_j(int32_t instruction)
{
	uint32_t addr = (instruction & 0x03FFFFFF) << 2;
	printf("C'est un J 0x%08X\n", addr);
	PC = addr;

}
void executer_jal(int32_t instruction)
{
	printf("C'est un JAL %d\n", (instruction & 0x03FFFFFF));
}
void executer_jr(int32_t instruction)
{
	printf("C'est un JR $%d\n", (instruction & 0x03E00000) >> 21);
}
void executer_lui(int32_t instruction)
{
	printf("C'est un LUI $%d,%d\n", (instruction & 0x001F0000) >> 16, (int16_t)(instruction & 0x0000FFFF));
	ecritureRegistre((instruction & 0x001F0000) >> 16, (int16_t)(instruction & 0x0000FFFF) << 16);
}
void executer_lw(int32_t instruction)
{
	printf("C'est un LW $%d,%d($%d)\n", (instruction & 0x001F0000) >> 16, (int16_t)(instruction & 0x0000FFFF), (instruction & 0x03E00000) >> 21);
	int16_t offset = (int16_t)(instruction & 0x0000FFFF);
	int32_t address = lectureRegistre((instruction & 0x03E00000) >> 21) + offset;
	if ((address & 0x00000003) != 0)
		printf("Exception, adresse incorrecte\n");
	else
	{
		ecritureRegistre(((instruction & 0x001F0000) >> 16), lectureMemoire(memoire, address) << 24);
		ecritureRegistre(((instruction & 0x001F0000) >> 16), lectureMemoire(memoire, address+1) << 16);
		ecritureRegistre(((instruction & 0x001F0000) >> 16), lectureMemoire(memoire, address+2) << 8);
		ecritureRegistre(((instruction & 0x001F0000) >> 16), lectureMemoire(memoire, address+3));
	}
}
void executer_mfhi(int32_t instruction)
{
	printf("C'est un MFHI $%d\n", (instruction & 0x0000F800) >> 11);
	ecritureRegistre((instruction & 0x0000F800) >> 11 , HI);
}
void executer_mflo(int32_t instruction)
{
	printf("C'est un MFLO $%d\n", (instruction & 0x0000F800) >> 11);
	ecritureRegistre((instruction & 0x0000F800) >> 11 , LO);
}
void executer_mult(int32_t instruction)
{
	//HI NE MARCHE PAS POUR LE MOMENT
	printf("C'est un MULT $%d,$%d\n", (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
	int64_t prod;
	prod = (int64_t)(lectureRegistre((instruction & 0x03E00000) >> 21)) * (int64_t)(lectureRegistre((instruction & 0x001F0000) >> 16));
	//printf("%016X\n", (lectureRegistre((instruction & 0x03E00000) >> 21)));
	//printf("%016lX * %016lX\n", (int64_t)(lectureRegistre((instruction & 0x03E00000) >> 21)), (int64_t)(lectureRegistre((instruction & 0x001F0000) >> 16)));
	//printf("PROD : %016lX\n", prod);
	LO = prod & 0x00000000FFFFFFFF;
	HI = (prod & 0xFFFFFFFF00000000) >> 32;
}
void executer_nop(int32_t instruction)
{
	printf("C'est un NOP\n");
}
void executer_or(int32_t instruction)
{
	printf("C'est un OR $%d,$%d,$%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
	ecritureRegistre((instruction & 0x0000F800) >> 11,lectureRegistre((instruction & 0x03E00000) >> 21) | lectureRegistre((instruction & 0x001F0000) >> 16));
}
void executer_rotr(int32_t instruction)
{
	printf("C'est un ROTR $%d,$%d,%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x001F0000) >> 16, (instruction & 0x000007C0) >> 6);
}
void executer_sll(int32_t instruction)
{
	printf("C'est un SLL $%d,$%d,%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x001F0000) >> 16, (instruction & 0x000007C0) >> 6);
	ecritureRegistre(((instruction & 0x0000F800) >> 11), (lectureRegistre((instruction & 0x001F0000) >> 16) << ((instruction & 0x000007C0) >> 6)));
}
void executer_slt(int32_t instruction)
{
	printf("C'est un SLT $%d,$%d,$%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
}
void executer_srl(int32_t instruction)
{
	printf("C'est un SRL $%d,$%d,%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x001F0000) >> 16, (instruction & 0x000007C0) >> 6);
	ecritureRegistre(((instruction & 0x0000F800) >> 11), (lectureRegistre((instruction & 0x001F0000) >> 16) >> ((instruction & 0x000007C0) >> 6)));
}
void executer_sub(int32_t instruction)
{
	// NE MARCHE PAS POUR LES NOMBRES NEGATIFS
	printf("C'est un SUB $%d,$%d,$%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
	int64_t res = (lectureRegistre((instruction & 0x03E00000) >> 21) - lectureRegistre((instruction & 0x001F0000) >> 16));
	if (res > 4294967296)
		printf("Exception : overflow\n");
	else
		ecritureRegistre(((instruction & 0x0000F800) >> 11), (lectureRegistre((instruction & 0x03E00000) >> 21) - lectureRegistre((instruction & 0x001F0000) >> 16)));
}
void executer_sw(int32_t instruction)
{
	printf("C'est un SW $%d,%d($%d)\n", (instruction & 0x001F0000) >> 16, (int16_t)(instruction & 0x0000FFFF), (instruction & 0x03E00000) >> 21);
	int16_t offset = (int16_t)(instruction & 0x0000FFFF);
	int32_t address = lectureRegistre((instruction & 0x03E00000) >> 21) + offset;
	if ((address & 0x00000003) != 0)
		printf("Exception, adresse incorrecte\n");
	else
		ecritureMemoire(memoire, address, lectureRegistre((instruction & 0x001F0000) >> 16), 32);
}
void executer_syscall(int32_t instruction)
{
	printf("C'est un SYSCALL\n");
}
void executer_xor(int32_t instruction)
{
	printf("C'est un XOR $%d,$%d,$%d\n", (instruction & 0x0000F800) >> 11, (instruction & 0x03E00000) >> 21, (instruction & 0x001F0000) >> 16);
	ecritureRegistre(((instruction & 0x0000F800) >> 11), (lectureRegistre((instruction & 0x03E00000) >> 21) ^ lectureRegistre((instruction & 0x001F0000) >> 16)));
}
