// calculator for electronics components.
#include <stdio.h>

int main ()
{
	int code[3];
	printf("Capacitor Code:");
        for(int i = 0; i < 3; i++)
	{
                scanf("%d", &code[i]);	
	}
	for(int i = 0; i < 3; i++)
	{
		printf("%d", code[i]);
	}
}
