#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "mem.h"

void test0()
{
	printf("Test numero 0\n");
	printf("Allocation d'un bloc de 42 octets\n");
	char *p = mem_alloc( 42 ); 
    if( p != NULL )
    	printf("TEST VALIDE\n");
    else
    	printf("TEST ECHOUE ///////////////\n"); // check whether the allocation was successful
    printf("\n\n\n");
    //mem_show_heap();
}

void testNalloc42(int n)
{
	printf("Test numero 1\n");
	printf("Allocation de 6 blocs de 42 octets\n");
	char * p_tab[n];
	int test = 0;

	for (int i = 0; i < n; ++i)
	{
		p_tab[i] = mem_alloc( 42 );
		if(p_tab[i] != NULL) test++;

	}

	
    if( test == n)
    	printf("TEST VALIDE\n");
    else
    	printf("TEST ECHOUE ///////////////\n"); // check whether the allocation was successful
    printf("\n\n\n");
    //mem_show_heap();
}

void test2()
{
	printf("Test numero 2\n");
	printf("Allocation d'un bloc de 200 octets\n");
	char *p = mem_alloc( 200 ); 
    if( p != NULL )
    	printf("TEST VALIDE\n");
    else
    	printf("TEST ECHOUE ///////////////\n"); // check whether the allocation was successful
    printf("\n\n\n");
    //mem_show_heap();
}

void test3(){
	printf("Test numero 3\n");
	printf("Allocation de 6 blocs de 42 octets\n");
	printf("Puis désallocation d'un bloc suivi d'une réallocation\n");
	char * p_tab[6];
	int test = 0;

	for (int i = 0; i < 6; ++i)
	{
		p_tab[i] = mem_alloc( 42 );
	}
	mem_release(p_tab[0]);
	p_tab[0] = mem_alloc( 42 );

	for (int i = 0; i < 6; ++i)
	{
		if(p_tab[i] != NULL) test++;
	}

	
    if( test == 6)
    	printf("TEST VALIDE\n");
    else
    	printf("TEST ECHOUE ///////////////\n"); // check whether the allocation was successful
    printf("\n\n\n");
}

void test4(){
	printf("Test numero 3\n");
	printf("Allocation de 6 blocs de 42 octets\n");
	printf("Puis désallocation de deux blocs \n");
	char * p_tab[6];
	int test = 0;

	for (int i = 0; i < 6; ++i)
	{
		p_tab[i] = mem_alloc( 42 );
	}
	mem_release(p_tab[0]);
	p_tab[0] = NULL;
	mem_release(p_tab[2]);
	p_tab[2] = NULL;

	for (int i = 0; i < 6; ++i)
	{
		if(p_tab[i] != NULL) test++;
	}

	
    if( test == 4)
    	printf("TEST VALIDE\n");
    else
    	printf("TEST ECHOUE ///////////////\n"); // check whether the allocation was successful
    printf("\n\n\n");
}

void test5()
{
	printf("Test numero 2\n");
	printf("Allocation d'un bloc de 200 octets Puis désallocation\n");
	char *p = mem_alloc( 200 );
	mem_release(p);
	p=NULL;
    if( p == NULL )
    	printf("TEST VALIDE\n");
    else
    	printf("TEST ECHOUE ///////////////\n"); // check whether the allocation was successful
    printf("\n\n\n");
    //mem_show_heap();
}

void test6()
{
	printf("Test numero 2\n");
	printf("Allocation d'un bloc de 200 octets Puis désallocation suivi d'une réallocation de 300\n");
	char *p = mem_alloc( 200 );
	mem_release(p);
	p=NULL;
	p = mem_alloc(300);
    if( p != NULL )
    	printf("TEST VALIDE\n");
    else
    	printf("TEST ECHOUE ///////////////\n"); // check whether the allocation was successful
    printf("\n\n\n");
    //mem_show_heap();
}

int main()
{
    // initialize the allocator
    mem_init();
    testNalloc42(5);
    mem_show_heap();
    
}