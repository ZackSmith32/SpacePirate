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
	score
	try to fix flicker?
	moving background
*/

#define waves_per_boss 3
#define enemies_per_wave 3

int main (void)
{
	int difficulty;
	if (!DEBUG) {
		initscr();
		noecho();
		keypad(stdscr, TRUE);
		curs_set(0);
		nodelay(stdscr, TRUE);
		init_pair(1, COLOR_RED, COLOR_BLACK);
		difficulty = menu();
	}
	int max_x;
	int max_y;
	getmaxyx(stdscr, max_y, max_x);
	new Player();
	int wavecount = waves_per_boss;
	while(Drawable::getPlayerAlive())
	{
		if (Enemy::getEnemiesAlive() == 0)
		{
			if (wavecount && !Boss::getBossesAlive()){
				for (int i = 0; i < enemies_per_wave + difficulty; i++)
					new Enemy(i * max_x / (enemies_per_wave + difficulty), 0, max_y / 2, difficulty * 0.1);
				wavecount--;
			}
			else if (!wavecount)
			{
				if (difficulty < 3)
					new Boss(max_x / 2, 0, 15 + difficulty);
				else
				{
					new Boss(max_x / 4, 0, 15 + 3 * difficulty);
					new Boss(max_x / 2, 0, 15 + 3 * difficulty);
					new Boss(max_x * 3 / 4, 0, 15 + 3 * difficulty);
				}
				wavecount = waves_per_boss;
				difficulty += 1;
			}
		}
		Drawable::erase_all();
		Drawable::move_all();
		Drawable::collide_all();
		Drawable::draw_all();
		if (!DEBUG) {
			refresh();
			//clear();			
		}
		usleep(16666);
	}
	clear();
	mvprintw(max_y / 2, max_x / 2, "GAME OVER, MAN");
	refresh();
	sleep(2);
	endwin();
	return 0;
}












