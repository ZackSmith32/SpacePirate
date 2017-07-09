#include <iostream>
#include <ncurses.h>
#include "Bullet.hpp"

Bullet::Bullet(int x, int y, float x_speed, float y_speed, bool enemy)
{
	xpos = x;
	ypos = y;
	this->x_speed = x_speed;
	this->y_speed = y_speed;
	this->enemy = enemy;
	symbol = '.';
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
