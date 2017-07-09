#include <iostream>
#include <ncurses.h>
#include "Bullet.hpp"

Bullet::Bullet(int x, int y, int speed)
{
	xpos = x;
	ypos = y;
	this->speed = speed;
	symbol = '.';
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
