#include "file.h"
#include "malloc.h"

File* initFile()
{
	File* file = malloc(sizeof(File));
	file->premier = NULL;
	file->dernier = NULL;
	printf("======>CREATION FILE\n");
	return file;
}

void enfiler(File* file, int valeur)
{
	EltFile* nouveau = malloc(sizeof(EltFile));
	nouveau->valeur = valeur;
	nouveau->suivant = NULL;
	printf("======>CREATION ELT FILE\n");
	
	if(file->dernier == NULL)
	{
		file->dernier = nouveau;
		file->premier = nouveau;
		
	}
	else
	{
		file->dernier->suivant = nouveau;
		file->dernier = nouveau;
	}
}


int defiler(File* file, int* valeur)
{
	if(file->premier == NULL)
	{
		return 0;
	}
	else
	{
		*valeur = file->premier->valeur;
		EltFile* temp = file->premier;
		
		if(file->premier->suivant == NULL)
		{
			file->premier = NULL;
			file->dernier = NULL;
		}
		else
		{
			file->premier = file->premier->suivant;
		}
		free(temp);
		printf("======>DESTRUCTION ELT FILE\n");
	}
}


void destroyFile(File *file)
{
	int x;
	while (defiler(file, &x)){}
	free(file);
	printf("======>DESTRUCTION FILE\n");
}