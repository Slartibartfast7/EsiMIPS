#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *BIN_OPCODES[] = {"ADD", "ADDI", "AND", "BEQ", "BGTZ", "BLEZ", "BNE", "DIV", "J", "JAL", "JR", "LUI", "LW", "MFHI", "MFLO", "MULT", "NOP", "OR", "ROTR", "SLL", "SLT", "SRL", "SUB", "SW", "SYSCALL", "XOR"};
void (*FCT_OPCODES[])(const *char) = {decode_add, decode_addi, decode_and, decode_beq, decode_bgtz, decode_blez, decode_bne, decode_div, decode_j, decode_jal, decode_jr, decode_lui, decode_lw, decode_mfhi, decode_mflo, decode_mult, decode_nop, decode_or, decode_rotr, decode_sll, decode_slt, decode_srl, decode_sub, decode_sw, decode_syscall, decode_xor};
