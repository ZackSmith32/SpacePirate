#include <iostream>
#include "Drawable.hpp"

Drawable* Drawable::list = NULL;
int Drawable::xmax = 0;
int Drawable::ymax = 0;

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

int Drawable::getX() {return xpos;}
int Drawable::getY() {return ypos;}

int Drawable::getWidX() {return xwid;}
int Drawable::getWidY() {return ywid;}

void Drawable::moveX(float delta)
{
	// int max_x, max_y;
	// getmaxyx(stdscr, max_y, max_x);
	xpos += delta;
	if (xpos >= xmax)
		xpos = xmax - 1;
	if (xpos < 0)
		xpos = 0;
}

void Drawable::moveY(float delta)
{
	// int max_x, max_y;
	// getmaxyx(stdscr, max_y, max_x);
	ypos += delta;
	if (ypos >= ymax)
		ypos = ymax - 1;
	if (ypos < 0)
		ypos = 0;
}

void Drawable::draw_sprite()
{
	for (int i = 0; i < ywid; i++)
		mvprintw(getY() + i, getX(), sprite.substr(xwid * i, xwid).c_str());
}

void Drawable::draw_bar(void) {
	int maxx, maxy;
	getmaxyx(stdscr, maxy, maxx);
	std::string bar_text;

	bar_text[maxx] = {" "}
	bar_text = "blah foo bar blah lorem ipsum";
	mvprintw(maxy - 21, 0, bar_text.c_str());
	return ;
}

void Drawable::draw()
{
	mvaddch(getY(), getX(), symbol);
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
	draw_bar();
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

bool overlap(Drawable& a, Drawable &b)
{
	if (a.getX() + a.getWidX() < b.getX() || \
		b.getX() + b.getWidX() < a.getX() || \
		a.getY() + a.getWidY() < b.getY() || \
		b.getY() + b.getWidY() < a.getY())
		return false;
	return true;
}

void Drawable::collide(Drawable *list)
{
	if (collided)
		return ;
	for(; list; list = list->next)
	{
		if (this == list)
			continue ;
		if (overlap(*this, *list))
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