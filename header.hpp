#ifndef HEADER_H
# define HEADER_H

// 1 = yes; 0 = no
#define DEBUG 1

void print_in_middle(WINDOW *win, int starty, int startx,
		int width, char *string, chtype color);
void	menu(void);
#endif