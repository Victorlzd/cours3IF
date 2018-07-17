#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, char** argv)
{
    int numeroChild = 3, j;
    int nChildMax = atoi(argv[2])+3;
    int pidFather = getpid();
    
    while (fork() && numeroChild<argc-1)
    {
        numeroChild++;
        if(numeroChild >= nChildMax)
        {
            wait(NULL);
            nChildMax++;
        }
    }
    if(pidFather != getpid())
    {
        execl(argv[1],argv[1],argv[numeroChild],NULL);
    }
    else
    {
        for (j = 2; j <= numeroChild; ++j)
        {
            wait(NULL);
        }
    }
    
    
    return 0;
}
