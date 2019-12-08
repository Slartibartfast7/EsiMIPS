#include "instructions.h"
#include "memoire.h"
#include "registre.h"
#include <stdio.h>

int OPCODES_R[] = {32, 36, 26, 8, 16, 18, 24, 37, 2, 0, 42, 2, 34, 12, 38};
int OPCODES_IJ[] = {8, 4, 7, 6, 5, 2, 3, 15, 35, 43};
void (*FCT_OPCODES_EXEC_R[])(uint32_t) = {executer_add, executer_and, executer_div, executer_jr, executer_mfhi, executer_mflo, executer_mult, executer_or, executer_rotr, executer_sll, executer_slt, executer_srl, executer_sub, executer_syscall, executer_xor};
void (*FCT_OPCODES_EXEC_IJ[])(uint32_t) = {executer_addi, executer_beq, executer_bgtz, executer_blez, executer_bne, executer_j, executer_jal, executer_lui, executer_lw, executer_sw};

uint32_t recupererInstruction(int adresse) 
{
	uint32_t instruction = 0;
	if(adresse < DEBUT_PROGRAMME) perror("Mauvaise adresse"); 
	if(adresse % 4 != 0) perror("Adresse non alignée");
	instruction += (lectureMemoire(memoire, adresse) << 24);
	instruction += (lectureMemoire(memoire, adresse+1) << 16);
	instruction += (lectureMemoire(memoire, adresse+2) << 8);
	instruction += lectureMemoire(memoire, adresse+3);
	return instruction;
}
void decoderInstruction(uint32_t instruction)
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

void executer_add(uint32_t instruction) 
{
	printf("C'est un ADD\n");
	//Integer Overflow ??
	int32_t temp;
	temp = lectureRegistre((instruction & 0x03E00000) >> 21) + lectureRegistre((instruction & 0x001F0000) >> 16);
	ecritureRegistre((instruction & 0x0000F800) >> 11,temp);
}
void executer_addi(uint32_t instruction) 
{
	printf("C'est un ADDI\n");
	//Integer Overflow ??
	int32_t temp;
	temp = lectureRegistre((instruction & 0x03E00000) >> 21) + (instruction & 0x0000FFFF);
	ecritureRegistre((instruction & 0x001F0000) >> 16,temp);
}
void executer_and(uint32_t instruction) 
{
	printf("C'est un AND\n");
}
void executer_beq(uint32_t instruction) 
{
	printf("C'est un BEQ\n");
}
void executer_bgtz(uint32_t instruction) 
{
	printf("C'est un BGTZ\n");
}
void executer_blez(uint32_t instruction) 
{
	printf("C'est un BLEZ\n");
}
void executer_bne(uint32_t instruction) 
{
	printf("C'est un BNE\n");
}
void executer_div(uint32_t instruction) 
{
	printf("C'est un DIV\n");
}
void executer_j(uint32_t instruction) 
{
	printf("C'est un J\n");
}
void executer_jal(uint32_t instruction) 
{
	printf("C'est un JAL\n");
}
void executer_jr(uint32_t instruction) 
{
	printf("C'est un JR\n");
}
void executer_lui(uint32_t instruction) 
{
	printf("C'est un LUI\n");
}
void executer_lw(uint32_t instruction) 
{
	printf("C'est un LW\n");
}
void executer_mfhi(uint32_t instruction) 
{
	printf("C'est un MFHI\n");
}
void executer_mflo(uint32_t instruction) 
{
	printf("C'est un MFLO\n");
}
void executer_mult(uint32_t instruction) 
{
	printf("C'est un MULT\n");
}
void executer_nop(uint32_t instruction) 
{
	printf("C'est un NOP\n");
}
void executer_or(uint32_t instruction) 
{
	printf("C'est un OR\n");
}
void executer_rotr(uint32_t instruction) 
{
	printf("C'est un ROTR\n");
}
void executer_sll(uint32_t instruction) 
{
	printf("C'est un SLL\n");
}
void executer_slt(uint32_t instruction) 
{
	printf("C'est un SLT\n");
}
void executer_srl(uint32_t instruction) 
{
	printf("C'est un SRL\n");
}
void executer_sub(uint32_t instruction) 
{
	printf("C'est un SUB\n");
}
void executer_sw(uint32_t instruction) 
{
	printf("C'est un SW\n");
}
void executer_syscall(uint32_t instruction) 
{
	printf("C'est un SYSCALL\n");
}
void executer_xor(uint32_t instruction) 
{
	printf("C'est un XOR\n");
}