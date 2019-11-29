typedef struct memoire
{
	struct memoire* suivant;
	int adresseM;
	int valeurM;
} memoire;

memoire* initMemoire(void);
void ecritureMemoire(memoire* memoireProc, int adresse, int valeur);
int lectureMemoire(memoire* memoireProc, int adresse);