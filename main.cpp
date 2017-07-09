#include <iostream>
#include <ncurses.h>
#include <menu.h>
#include <unistd.h>
#include "Player.hpp"
#include "Drawable.hpp"
#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Boss.hpp"
#include "header.hpp"

/*
	TODO:
	- menu
		- high scores file
		- text input name
	-collision where only players and enemies check themselves
	-powerups
	-color
	-head seeking bullets
	-move, draw, collide all pure virtual functions
*/

int main (void)
{
	if (!DEBUG) {
		initscr();
		noecho();
		keypad(stdscr, TRUE);
		curs_set(0);
		nodelay(stdscr, TRUE);
		init_pair(1, COLOR_RED, COLOR_BLACK);
		menu();
	}
	int max_x;
	int max_y;
	getmaxyx(stdscr, max_y, max_x);
	//new Enemy(max_x / 2 , 0, max_y - 20, 1);
	new Boss(max_x / 2, 10);
	new Player();
	while(1)
	{
		//new Bullet(rand() % max_x, 0, 0, 1, 0);
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












