#ifndef REGISTRE
#define REGISTRE

#include <stdint.h>

uint32_t registreProc[32];
uint32_t HI;
uint32_t LO;
uint32_t PC;

void ecritureRegistre(uint32_t registre, uint32_t valeur);
uint32_t lectureRegistre(uint32_t registre);
void afficherRegistres(void);

#endif