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
	final checklist:
	enemies, boss, enemies, boss, etc
	investigate better timing system
	key repeat issue (?)
	timer improvement
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
	new Boss(max_x / 2, 10);
	new Player();
	while(Drawable::getPlayerAlive())
	{
		Drawable::move_all();
		Drawable::collide_all();
		Drawable::draw_all();
		if (!DEBUG) {
			refresh();
			clear();			
		}
		usleep(16666);
	}
	endwin();
	return 0;
}












