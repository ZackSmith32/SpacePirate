#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Player.hpp"
#include "Drawable.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"

/*
	TODO:
	- enemies shoot
	- multi-character drawables
		-done, needs collision
	-collision optimization (maybe)
	-powerups
	-color
*/

int main (void)
{
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	nodelay(stdscr, TRUE);
	new Player();
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	Enemy	vader(max_x / 2 , 0, 0.25);
	while(1)
	{
		new Bullet(rand()% max_x, 0, 0, 2, true);
		Drawable::move_all();
		Drawable::collide_all();
		Drawable::draw_all();
		refresh();
		clear();
		usleep(60000);
	}
	endwin();
	return 0;
}