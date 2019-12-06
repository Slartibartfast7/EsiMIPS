#include "instructions.h"
#include "memoire.h"
#include <stdio.h>


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
void decoderInstruction(uint32_t instruction) {}
uint8_t trouverOperande(uint32_t instruction, int rangOperande) {return 0;}

void executer_add(uint32_t instruction) {}
void executer_addi(uint32_t instruction) {}
void executer_and(uint32_t instruction) {}
void executer_beq(uint32_t instruction) {}
void executer_bgtz(uint32_t instruction) {}
void executer_blez(uint32_t instruction) {}
void executer_bne(uint32_t instruction) {}
void executer_div(uint32_t instruction) {}
void executer_j(uint32_t instruction) {}
void executer_jal(uint32_t instruction) {}
void executer_jr(uint32_t instruction) {}
void executer_lui(uint32_t instruction) {}
void executer_lw(uint32_t instruction) {}
void executer_mfhi(uint32_t instruction) {}
void executer_mflo(uint32_t instruction) {}
void executer_mult(uint32_t instruction) {}
void executer_nop(uint32_t instruction) {}
void executer_or(uint32_t instruction) {}
void executer_rotr(uint32_t instruction) {}
void executer_sll(uint32_t instruction) {}
void executer_slt(uint32_t instruction) {}
void executer_srl(uint32_t instruction) {}
void executer_sub(uint32_t instruction) {}
void executer_sw(uint32_t instruction) {}
void executer_syscall(uint32_t instruction) {}
void executer_xor(uint32_t instruction) {}