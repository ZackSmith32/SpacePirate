#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Player.hpp"
#include "Drawable.hpp"
#include "Bullet.hpp"


int main (void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
	new Player();
	new Bullet(10, 0, 1);
	int counter = 0;
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	while(1)
	{
		if (counter == 5)
		{
			new Bullet(rand()% max_x, 0, 1);
			counter = 0;
		}
		Drawable::move_all();
		Drawable::collide_all();
		Drawable::draw_all();
		refresh();
		clear();
		counter++;
		usleep(60000);
	}
	endwin();
	return 0;
}