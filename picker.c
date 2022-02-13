// coinflip or wheel of names program its pretty nice
#include <stdio.h>
#include <time.h>

void srand(int);
int rand();


int main(int argc, char *argv[]){
	if (argc < 2){
		printf("add arguments, stupid\n"); // degradation kink
		return 1;
	}
	srand(time(0));
	printf("%s \n", argv[(rand() % (argc - 1)) + 1 ]);
}
