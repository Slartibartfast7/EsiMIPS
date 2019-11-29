#ifndef MEMOIRE
#define MEMOIRE

#include <stdint.h>
#define TAILLE_MEMOIRE 128

int32_t memoire[TAILLE_MEMOIRE];

void ecritureMemoire(int32_t* memoire, int32_t adresse, int32_t valeur);
int32_t lectureMemoire(int32_t* memoire, int32_t adresse);
void afficherMemoire(int32_t* memoire);

#endif