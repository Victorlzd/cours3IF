#include <stdio.h>

int main()
{
	int tab[1000];
	int taille = 0;
	int courant;
	int palindrome = 1;
	int i;
	
	scanf("%d", &courant);
	
	while (courant != -1)
	{
		tab[taille] = courant;
		taille++;
		scanf("%d", &courant);
	}
	
	for (i = 0; i < taille/2; ++i)
	{
		if(tab[i] != tab[taille-i-1])
		{
			palindrome = 0;
			break;
		}
	}
	
	printf("%d\r\n", palindrome);
	return 0;
}