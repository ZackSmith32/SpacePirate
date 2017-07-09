#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Player.hpp"
#include "Drawable.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"


int main (void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);

	Player p;
	Bullet b(10, 0, 1);

	int max_x;
	int	max_y;
	getmaxyx(stdscr, max_y, max_x);
	Enemy	vader(max_x / 2, 0);
	while(1)
	{
		Drawable::move_all();
		Drawable::draw_all();
		refresh();
		clear();
		usleep(60000);
	}
	endwin();
	return 0;
}