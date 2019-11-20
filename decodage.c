#include "decodage.h"

void lectureFichier(const char* fichierEntree)
{
	int lecture;
	size_t taille = 20;
	char* ligne = (char *)malloc(taille * sizeof(char));
	FILE* fichier = fopen(fichierEntree, "r");
	if(fichier == NULL) perror("Problème lors de l'ouverture du fichier");
	while((lecture = getline(&ligne, &taille, fichier)) != -1) 
	{
        printf("Ligne : %s", ligne);
        //ON LECRIT EN HEXA
    }	
}