#include <stdio.h>


int draw_box(int, int, char, char);
int draw_line(int, char);

int main() // assign a bunch of gay little variables
{
	int w, h;
	char fill, out;
	printf("w-width pweasee~ 🥺 ");
	scanf("%i", &w);
        printf("h-height?~ ");
	scanf("%i", &h);
	printf("f-filling,,?  ");
	scanf(" %c", &fill);
	printf("o-outline~? uwu ");
	scanf(" %c", &out);
	draw_box(w, h, fill, out);
}

int draw_box(int w, int h, char filling, char outline) // main box drawing function
{
        printf("width %i, height %i nyaahh~\n", w, h);
        draw_line(w, outline);
	for (int hc = 0; hc < h; hc++)
	{
		printf("%c", outline);
		for(int i = 0; i < w - 2; i++)
		{
		printf("%c", filling);
		}
		printf("%c", outline);
		printf("\n");
	}
	draw_line(w, outline);
	return 0;
}

int draw_line(int w, char fill) // line drawing function for top and bottom 
{
  for(int i = 0; i < w; i++)
  {
	printf("%c", fill);
  }
  printf("\n");
  return 0;
}
