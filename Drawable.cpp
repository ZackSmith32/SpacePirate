#include <iostream>
#include "Drawable.hpp"

Drawable* Drawable::list = NULL;

Drawable::Drawable()
{
	next = Drawable::list;
	Drawable::list = this;
}

int Drawable::getX()
{
	return xpos;
}

int Drawable::getY()
{
	return ypos;
}

void Drawable::moveX(int delta)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	xpos += delta;
	if (xpos >= max_x)
		xpos = max_x - 1;
	if (xpos < 0)
		xpos = 0;
}

void Drawable::moveY(int delta)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	ypos += delta;
	if (ypos >= max_y)
		ypos = max_y - 1;
	if (ypos < 0)
		ypos = 0;
}

void Drawable::draw()
{
	int x, y;
	x = getX();
	y = getY();
	mvaddch(y, x, symbol);
}

void Drawable::move(){}

Drawable* Drawable::getNext()
{
	return next;
}

void Drawable::draw_all()
{
	Drawable *d = list;
	while (d)
	{
		d->draw();
		d = d->getNext();
	}
}

void Drawable::move_all()
{
	Drawable *d = list;
	while (d)
	{
		d->move();
		d = d->getNext();
	}
}