#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



int main(int argc, char** argv)
{
    int nChild = 0, j;
    int pidFather = getpid();
    
    while (fork() && nChild<argc-3)
    {
        nChild++;
    }
    if(pidFather != getpid())
    {
        execl(argv[1],argv[1],argv[nChild+2],NULL);
    }
    else
    {
        for (j = 0; j <= nChild; ++j)
        {
            wait(NULL);
        }
    }
    
    
    return 0;
}
