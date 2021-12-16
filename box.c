#include <stdio.h>


int draw_box(int, int);
int draw_line(int, char);

int main()
{
	int w, h;
	printf("Width: ");
	scanf("%i", &w);
        printf("Height: ");
	scanf("%i", &h);
	draw_box(w, h);
}

int draw_box(int w, int h) // main box drawing function
{
	char outline = '#';
	char filling = ' ';
        printf("width %i, height %i\n", w, h);
	for (int hc = 0; hc < h; hc++)
	{
		draw_line(w, outline);
	}
	return 0;
}

int draw_line(int w, char fill) // line drawing function for filled lines
{
  for(int i = 0; i < w; i++)
  {
	printf("%c", fill);
  }
  printf("\n");
  return 0;
}
