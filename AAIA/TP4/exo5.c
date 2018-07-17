#include <stdio.h>
#include <stdlib.h>

int** cout;

int creeCout(int nbSommets){
    int coutMin = 10;
    int coutMax = 40;
    int dmin = coutMax;
    int i, j, iseed, it;
    iseed = 1;
    cout = (int**) malloc(nbSommets*sizeof(int*));
    for (i=0; i<nbSommets; i++){
        cout[i] = (int*) malloc(nbSommets*sizeof(int));
        for (j=0; j<nbSommets; j++){
            if (i == j) cout[i][j] = coutMax+1;
            else {
                it = 16807 * (iseed % 127773) - 2836 * (iseed / 127773);
                if (it > 0)    iseed = it;
                else iseed = 2147483647 + it;
                cout[i][j] = coutMin + iseed % (coutMax-coutMin+1);
                if(cout[i][j]<dmin)
                	dmin=cout[i][j];
            }
        }
    }
    return dmin;
}

int calcul_l(int depart, int nonVus[], int nbNonVus)
{
	int min = cout[depart][nonVus[0]];

	for (int i = 1; i < nbNonVus; ++i)
	{
		if(min > cout[depart][nonVus[i]])
			min = cout[depart][nonVus[i]];
	}
	return min;
}


int estim(int depart, int nonVus[], int nbNonVus)
{
	int estim = calcul_l(depart, nonVus, nbNonVus);
	for (int i = 0; i < nbNonVus; ++i)
	{
		int pca = calcul_l(nonVus[i], nonVus, nbNonVus);
		if(pca <= cout[nonVus[i]][0])
			estim += pca;
		else
			estim += cout[nonVus[i]][0];
	}

	return estim;
}





int permut(int vus[], int nbVus, int nonVus[], int nbNonVus, int longueur, int pcc, int dmin){
    /*
    Variable globale :
     - pour tout couple de sommets (i,j), cout[i][j] = cout pour aller de i vers j
    Entree :
     - nonVus[0..nbNonVus-1] = sommets non visites
     - vus[0..nbVus-1] = sommets visites
    Precondition :
     - nbVus > 0 et Vus[0] = 0 (on commence toujours par le sommet 0)
     - longueur = somme des couts des arcs du chemin <vus[0], vus[1], ..., vus[nbVus-1]>
    Postcondition : affiche les longueurs de tous les circuits commençant par vus[0..nbVus-1] et se terminant par les sommets de nonVus[0..nbNonVus-1] (dans tous les ordres possibles), suivis de 0
     */
	

	int current;
	if(nbNonVus == 0)
    {
    	longueur += cout[vus[nbVus-1]][0];
    	return longueur>=pcc ? pcc : longueur;
    }
    else if(longueur+estim(vus[nbVus-1], nonVus, nbNonVus) < pcc)
    	{
    		
	    	for (int i = 0; i < nbNonVus; ++i)
	    	{
	    		vus[nbVus] = nonVus[i];
	    		nonVus[i] = nonVus[nbNonVus-1];
	    		
	    		pcc = permut(vus, nbVus+1, nonVus, nbNonVus-1, longueur+cout[vus[nbVus-1]][vus[nbVus]], pcc, dmin);
	    		
	    		
	    		nonVus[i] = vus[nbVus];
	    	}
    	}

    	return pcc;
    
}



int main(){
    int nbSommets, res;
    scanf("%d",&nbSommets);
    int dmin = creeCout(nbSommets);
    int vus[nbSommets];
    int nonVus[nbSommets-1];
    for (int i=0; i<nbSommets-1; i++) nonVus[i] = i+1;
    vus[0] = 0;
    res = permut(vus,1,nonVus,nbSommets-1,0, 100000, dmin);
    printf("res = %d\n", res);
}