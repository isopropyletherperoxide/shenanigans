/* 2 Player Tic-Tac-Toe
Copyright © 2022 Aryl Halide

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <curses.h>

char grid[3][3]; // tictactoe grid, first index is row, second is column
int x, y;

/* this function checks for 3 of the same characters that aren't underscores
returns a bool if you win or no */

bool drawCheck() {
  bool draw = TRUE;
  for (int v = 0; v < 3; v++) {
    for (int h = 0; h < 3; h++) {
      if (grid[v][h] == '_') {
        draw = FALSE;
      }
    }
  }
  return draw;
}
bool winCheck() {
  bool Won;
  for (int v = 0; v < 3; v++) {
    if (grid[v][0] == grid[v][1] && grid[v][0] == grid[v][2] &&
        grid[v][1] == grid[v][2] && grid[v][0] != '_') {
      mvprintw(6, 6, "%c Win!", grid[v][0]);
      Won = TRUE;
      refresh();
    }
  }
  for (int h = 0; h < 3; h++) {
    if (grid[0][h] == grid[1][h] && grid[0][h] == grid[2][h] &&
        grid[1][h] == grid[2][h] && grid[0][h] != '_') {
      mvprintw(6, 6, "%c Win!", grid[0][h]);
      Won = TRUE;
      refresh();
    }
  }
  if (grid[0][0] == grid[2][2] && grid[1][1] == grid[0][0] &&
      grid[0][0] != '_') { // Diagonal Checks
    mvprintw(6, 6, "%c Win!", grid[0][0]);
    Won = TRUE;
    refresh();
  }
  if (grid[0][2] == grid[2][0] && grid[1][1] == grid[0][2] &&
      grid[0][2] != '_') {
    mvprintw(6, 6, "%c Win!", grid[0][2]);
    Won = TRUE;
    refresh();
  }
  return Won;
}

void resetGrid() { // makes all of the grid blank
  for (int v = 0; v < 3; v++) {
    for (int h = 0; h < 3; h++) {
      grid[v][h] = '_';
    }
  }
}

void drawGrid() { // draws the grid and all the characters
  for (int v = 0; v < 3; v++) {
    for (int h = 0; h < 3; h++) {
      mvprintw(v, h, "%c", grid[v][h]);
    }
  }
  move(0, 0);
}

void controlLoop() { // control loop called on player's turn
  while (1) {
    switch (getch()) {
    case KEY_UP:
      y--;
      break;
    case KEY_DOWN:
      y++;
      break;
    case KEY_LEFT:
      x--;
      break;
    case KEY_RIGHT:
      x++;
      break;
    case ('x'):
      if (grid[y][x] == '_') { // if the tile is blank, place X
        grid[y][x] = 'X';
        drawGrid();
        x++;
        refresh();
      }
      break;
    case ('o'):
      if (grid[y][x] == '_') {
        grid[y][x] = 'O';
        drawGrid();
        x++;
        refresh();
      }
      break;
    }
    if (x > 2) {
      x = 0;
    }
    if (x < 0) {
      x = 2;
    }
    if (y < 0) {
      y = 2;
    }
    if (y > 2) {
      y = 0;
    }
    move(y, x);
    if (winCheck() == TRUE) {
      break;
    }
    if (drawCheck() == TRUE) {
      mvprintw(6, 6, "Draw!");
      break;
    }
  }
}
// a bunch of ncurses setup code and stuff
int main(void) {
  initscr();
  noecho();
  resetGrid();
  drawGrid();
  keypad(stdscr, TRUE);
  controlLoop();
  getch();
  endwin();
}
