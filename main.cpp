#include <iostream>
#include <ncurses.h>
#include <menu.h>
#include <unistd.h>
#include "Player.hpp"
#include "Drawable.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "header.hpp"

/*
	TODO:
	- enemies shoot
	- menu
		- high scores file
		- text input name
	- multi-character drawables
		-done, needs collision
	-collision optimization (maybe)
	-powerups
	-color
	-head seeking bullets
*/

int main (void)
{
	int max_x;
	int max_y;
	getmaxyx(stdscr, max_y, max_x);
	if (!DEBUG) {
		initscr();
		noecho();
		keypad(stdscr, TRUE);
		curs_set(0);
		nodelay(stdscr, TRUE);
		init_pair(1, COLOR_RED, COLOR_BLACK);
		// menu();
	}

	new Enemy(max_x / 2 , 0, max_y - 20, 1);
	new Player();
	while(1)
	{
		std::cout << "yo" << std::endl;
		new Bullet(rand() % max_x, 0, 0, 1, true);
		Drawable::move_all();
		Drawable::collide_all();
		Drawable::draw_all();
		if (!DEBUG) {
			refresh();
			clear();			
		}
		usleep(60000);
	}
	endwin();
	return 0;
}












