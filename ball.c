#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <stdlib.h>

#define UP_RIGHT 1
#define UP_LEFT 2
#define DOWN_RIGHT 3
#define DOWN_LEFT 4

int x, y, lasty, lastx;
char ball;
void ball_move(WINDOW *window, int dir);

int main (int argc, char *argv[]){
	ball = 'o';
	int balldir;
	int speed;
	if(argc > 1){
		speed = atoi(argv[1]);
	}
	else {
		speed = 50000;
	}
	initscr();
	cbreak();
	curs_set(0);
	WINDOW *playarea;
	playarea = newwin(20, 90, 5, 5);
	box(playarea, 0, 0);
	y = 10;
	x = 20;
	lasty = y;
	lastx = x;
	wmove(playarea, y, x);
	balldir = DOWN_RIGHT;
	while (1){
		refresh();
		wrefresh(playarea);
                ball_move(playarea, balldir);
		usleep(speed);
		lasty = y;
		lastx = x;
		if (x < 3 & y > 17){
			balldir = UP_RIGHT;
		}
		if (x > 87 & y > 17){
			balldir = UP_LEFT;
		}
		if (x < 3 & y < 2){
			balldir = DOWN_RIGHT;
		}
		if (x > 87 & y < 2){
			balldir = DOWN_LEFT;
		}
		if(y > 17)
		{
			if(balldir == DOWN_RIGHT){
			balldir = UP_RIGHT;
			}
			else {
			balldir = UP_LEFT;
			}
		}
		else if(y < 2)
		{
			if(balldir == UP_RIGHT){
				balldir = DOWN_RIGHT;
			}
			else {
				balldir = DOWN_LEFT;
			}
		}
		else if(x > 87)
		{
			if(balldir == DOWN_RIGHT){
				balldir = DOWN_LEFT;
			}
			else { 
				balldir = UP_LEFT;
			}
		}
		else if(x <= 2)
		{
			if(balldir == DOWN_LEFT){
				balldir = DOWN_RIGHT;
			}
			else
			{
				balldir = UP_RIGHT;
			}
		}


}
	getch();
	endwin();
}

void ball_move(WINDOW *win, int dir)
{
	switch(dir){
		case UP_RIGHT:
		y--;
		x++;
		break;
		case UP_LEFT:
		x--;
		y--;
		break;
		case DOWN_RIGHT:
		y++;
		x++;
		break;
		case DOWN_LEFT:
		y++;
		x--;
		break;
	}
	mvwaddch(win, y, x, ball);
	mvwaddch(win, lasty, lastx, ' ');
}
