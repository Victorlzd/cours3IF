#ifndef PILE_FILE_H
#define PILE_FILE_H

typedef struct EltFile{
	int valeur;
	struct EltFile* suivant;
}EltFile;

typedef struct File{
	EltFile* premier;
	EltFile* dernier;
}File;

File* initFile();
void enfiler(File* file, int valeur);
int defiler(File* file, int* valeurRetour);
void destroyFile(File *file);

#endif //PILE_FILE_H
