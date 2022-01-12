// calculator for electronics components.
#include <stdio.h>


void read_code(int*);
void print_code(int*);

int main ()
{
	int code[3], cap;
	float capf;
	read_code(code);
	printf("Capacitor Code: ");
	print_code(code);
   	cap = (code[0] - '0') * 10;
	cap = cap + (code[1] - '0');
	for (int i = code[2] - '0'; i > 0; i--){
		cap = cap * 10;
	}
	capf = cap;
	printf("%.4f pF\n", capf);
	printf("%.4f nF\n", capf/10); 
	printf("%.4f uF\n", capf/100); 
	printf("%.4f mF\n", capf/1000);
}




void read_code(int *code){ 
	for(int i = 0; i < 3; i++)
	{

		code[i] = getchar();
	}
}

void print_code(int *code){
	for(int i = 0; i < 3; i++)
	{
		putchar(code[i]);
	}
	putchar('\n');
}
