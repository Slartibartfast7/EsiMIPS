#ifndef DECODAGE
#define DECODAGE


void lectureFichier(const char* fichierEntree);
char* conversionBinaire(const int aConvertir, char* binaire);
char* operande(const char* instruction, int rangOperande);


void decode_add(const char* instruction);
void decode_addi(const char* instruction);
void decode_and(const char* instruction);
void decode_beq(const char* instruction);
void decode_bgtz(const char* instruction);
void decode_blez(const char* instruction);
void decode_bne(const char* instruction);
void decode_div(const char* instruction);
void decode_j(const char* instruction);
void decode_jal(const char* instruction);
void decode_jr(const char* instruction);
void decode_lui(const char* instruction);
void decode_lw(const char* instruction);
void decode_mfhi(const char* instruction);
void decode_mflo(const char* instruction);
void decode_mult(const char* instruction);
void decode_nop(const char* instruction);
void decode_or(const char* instruction);
void decode_rotr(const char* instruction);
void decode_sll(const char* instruction);
void decode_slt(const char* instruction);
void decode_srl(const char* instruction);
void decode_sub(const char* instruction);
void decode_sw(const char* instruction);
void decode_syscall(const char* instruction);
void decode_xor(const char* instruction);

#endif