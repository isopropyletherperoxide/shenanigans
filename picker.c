/* program that picks things to do for me 
   doubles as a coin flip */
#define STR_LNGTH 5
#define STR_AMNT 1

#include <stdio.h>
#include <time.h>

int string_write(int);
int srand (int);
int rand();
char item[STR_AMNT][STR_LNGTH];


int main(void)
{
	int ch;
        int idx;
        srand(time(NULL));
	int r = rand() % STR_AMNT;
	for (idx = 0; idx <= STR_AMNT; idx++)
	{
	  string_write(idx);
	}
	idx = rand() % (STR_AMNT + 1);
	for (ch = 0; ch <= STR_LNGTH - 1; ch++)
	{
	printf("%c", item[idx][ch]);
	}
}

int string_write(int c)
{
	int i;
	for (i = 0; i <= STR_LNGTH; i++)
	{
		item[c][i] = getchar();
	}
	return 0;
}
