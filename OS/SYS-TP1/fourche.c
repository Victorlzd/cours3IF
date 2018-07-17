#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    /*
    printf("%d : hello world\n", getpid());
    
    if(fork())
    {
        printf("%d : Je suis le parent\n", getpid());
    }
    else
    {
        printf("%d : Je suis l'enfant\n", getpid());
    }*/
    
    fork();
    if(fork())
        fork();
    printf("A");
    return 0;
}
