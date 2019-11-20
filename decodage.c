#include "decodage.h"

void lectureFichier(const char* fichierEntree)
{
	//Ouvre le fichier d'entrée, traduit chacune des lignes en hexadécimale
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
    fclose(fichier);	
}

char* conversionBinaire(const int aConvertir, char* binaire)
{
	//Convertit une valeur < à 256 en binaire
	int i;
    for(i = 7; i >= 0; --i)
    {
        sprintf(binaire+(7-i),"%c",(aConvertir & (1 << i)) ? '1' : '0');
    }
	binaire[(7-i)] = '\0';
	return binaire;
}

char* operande(const char* instruction, int rangOperande)
//A partir d'une instruction, donne l'opérande indiquée
{
	char* operande[20];
	int fin = 0;
	int i = 0;
	int nombreOperande = 0;
	operande = strchr(instruction, ' ');
	//PAS FINI
}
