#include <stdio.h>
#include <time.h>
int main(void)
{
	printf("Print the max number: ");
	int lim;
        scanf("%i", &lim);
        //printf("%i\n", lim); // debug thing, print the limit
        srand(time(NULL));
	int r = rand() % lim;
	printf("%d", r);
}
