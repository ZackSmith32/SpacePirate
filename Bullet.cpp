#include <iostream>
#include <ncurses.h>
#include <menu.h>
#include "Bullet.hpp"

/*
 *	type = 0 : star
 *	type = 1 : player
 *	type = 2 : enemy
 */

char Bullet::bullets[6] = ".^o+|";

Bullet::Bullet(int x, int y, float x_speed, float y_speed, int type)
{
	xpos = x;
	ypos = y;
	this->x_speed = x_speed;
	this->y_speed = y_speed;
	_type = type;
	symbol = bullets[type];
}

void Bullet::move()
{
	Drawable::move();
	moveX(x_speed);
	moveY(y_speed);
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	if (getY() == max_y - 1)
		delete this;
	if (getY() == 0)
		delete this;
}
