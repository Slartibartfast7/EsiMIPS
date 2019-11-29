#ifndef MEMOIRE
#define MEMOIRE

#include <stdint.h>
#define TAILLE_MEMOIRE 128

int8_t memoire[TAILLE_MEMOIRE];

void ecritureMemoire(int8_t* memoire, int32_t adresse, int32_t valeur, int taille);
int32_t lectureMemoire(int8_t* memoire, int32_t adresse);
void afficherMemoire(int8_t* memoire);

#endif