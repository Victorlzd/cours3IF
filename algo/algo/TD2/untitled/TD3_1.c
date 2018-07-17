#include <stdio.h>

float sommeSequence(float tab[], int taille)
{
	float sommeGen=0, sommeAct=0, sommeMax= tab[0];
	int i;
	for (i = 0; i < taille; ++i)
	{
		if(tab[i] < 0)
		{
			sommeAct = 0;
		}
		else
		{
			sommeAct += tab[i];
		}
		sommeGen += tab[i];
		
		if(sommeAct>sommeGen)
		{
			sommeGen = sommeAct;
		}
		
		if (sommeGen>sommeMax)
		{
			sommeMax = sommeGen;
		}
	}
	return sommeMax;
}

/*
int main()
{
	int n;
	float tab[5000];
	int i;
	fscanf(stdin, "%d", &n);
	
	for (i = 0; i < n; ++i)
	{
		fscanf(stdin, "%f", tab+i);
	}
	
	printf("%f\r\n", sommeSequence(tab, n));
	return 0;
}*/
