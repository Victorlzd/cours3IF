#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>


int main(int argc, char** argv)
{
    
    if(fork())
    {
        execl("./rebours","rebours","5",NULL);
    }
    else
    {
        execl("./rebours","rebours","8",NULL);
    }
    
    return 0;
}
