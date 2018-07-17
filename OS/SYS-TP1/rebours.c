#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistd.h>
#include <assert.h>


int main(int argc, char** argv)
{
	assert(argc == 2);
	int count = atoi(argv[argc-1]);
	
	assert(count>0);
	
	printf("%d : debut\n", getpid());
	while(count>0)
	{
		printf("%d : %d\n", getpid(), count);
		count--;
		sleep(1);
	}
	printf("%d : fin\n", getpid());
	
	return 0;
}
