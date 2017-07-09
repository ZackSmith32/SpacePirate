#include <iostream>
#include "Drawable.hpp"

Drawable* Drawable::list = NULL;

Drawable::Drawable()
{
	next = Drawable::list;
	prev = NULL;
	collided = false;
	if (Drawable::list != NULL)
		Drawable::list->prev = this;
	Drawable::list = this;
}

Drawable::~Drawable()
{
	if (prev == NULL)
		Drawable::list = next;
	else
	{
		prev->next = this->next;
		if (this->next != NULL)
			this->next->prev = prev;
	}
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

void Drawable::move(){
	if (collided)
	{
		delete this;
		return ;
	}
}

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

void Drawable::collide(Drawable *list)
{
	if (collided)
		return ;
	for(; list; list = list->next)
	{
		if (this == list)
			continue ;
		if (getX() == list->getX() && getY() == list->getY())
		{
			collided = true;
			list->collided = true;
		}
	}
}

void Drawable::collide_all()
{
	Drawable *d = list;
	while (d)
	{
		d->collide(list);
		d = d->getNext();
	}
}