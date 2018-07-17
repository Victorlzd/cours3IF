#include <stdio.h>
#include "pile.h"
#include "file.h"

void testPile1()
{
	printf("------------Test Pile 1------------\n");
	Pile* pile;
	pile = initPile();
	destroyPile(pile);
	printf("------------Fin Test Pile 1------------\n");
}

void testPile2()
{
	printf("------------Test Pile 2------------\n");
	
	
	Pile* pile;
	int x=0;
	
	pile = initPile();
	
	if(depiler(pile,&x))
		printf("%d\n", x);
	else
		printf("pile vide\n");
	
	empiler(pile,1);
	empiler(pile,2);
	empiler(pile,3);
	
	if(depiler(pile,&x))
		printf("%d\n", x);
	else
		printf("pile vide\n");
	
	if(depiler(pile,&x))
		printf("%d\n", x);
	else
		printf("pile vide\n");
	
	destroyPile(pile);
	
	
	printf("------------Fin Test Pile 2------------\n");
}

void testFile1()
{
	printf("------------Test File 1------------\n");
	File* file;
	file = initFile();
	destroyFile(file);
	printf("------------Fin Test File 1------------\n");
}

void testFile2()
{
	printf("------------Test File 2------------\n");
	
	
	File* file;
	int x=0;
	
	file = initFile();
	
	if(defiler(file,&x))
		printf("%d\n", x);
	else
		printf("file vide\n");
	
	enfiler(file,1);
	enfiler(file,2);
	enfiler(file,3);
	
	if(defiler(file,&x))
		printf("%d\n", x);
	else
		printf("file vide\n");
	
	if(defiler(file,&x))
		printf("%d\n", x);
	else
		printf("file vide\n");
	
	destroyFile(file);
	
	
	printf("------------Fin Test File 2------------\n");
}



int main()
{
	testFile1();
	testFile2();
	return 0;
}