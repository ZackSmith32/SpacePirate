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

Bullet::~Bullet(){}

void Bullet::move()
{
	moveY(speed);
}
