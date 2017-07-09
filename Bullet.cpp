#include <iostream>
#include <ncurses.h>
#include "Bullet.hpp"

/*
 *	type = 0 : star
 *	type = 1 : player
 *	type = 2 : enemy
 */

char Bullet::bullets[6] = ".^o+|";

Bullet::Bullet(int x, int y, float speed, int type)
{
	xpos = x;
	ypos = y;
	this->speed = speed;
	symbol = bullets[type];
}

void Bullet::move()
{
	Drawable::move();
	moveY(speed);
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	if (getY() == max_y - 1)
		delete this;
}
