#include <stdio.h>

int testChevauche(int a1, int b1, int a2, int b2)
{
	if(a1 > b1 || a2 > b1 || b1<a2 || b2<a1)
	{
		return  0;
	}
	return 1;
}

void nouvIntervalle(int* a, int* b, int a1, int b1, int a2, int b2)
{
	if(a1 < a2)
	{
		*a = a1;
	}
	else
	{
		*a = a2;
	}
	
	if(b1 < b2)
	{
		*b = b1;
	}
	else
	{
		*b = b2;
	}
}

void retirer(int a[], int b[], int *taille, int index )
{
	int i;
	(*taille)--;
	for (i = 0; i < *taille; ++i)
	{
		a[i] = a[i+1];
		b[i] = b[i+1];
	}
}


int main()
{
	int n, i, j;
	int a[10];
	int b[10];
	
	
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d", a+i, b+i);
	}
	
	
	for (i = 0; i < 1; ++i)
	{
		for (j = i+1; j < n; ++j)
		{
			if (testChevauche(a[i], b[i], a[j], b[j]))
			{
				nouvIntervalle(a+i, b+i, a[i], b[i], a[j], b[j]);
				retirer(a, b, &n, j);
				i--;
				break;
			}
		}
	}
	
	printf("%d\r\n", n);
	for (i = 0; i < n; ++i)
	{
		printf("%d %d\r\n", a[i], b[i]);
	}
	
	
	return 0;
}