#include <iostream>
#include "Drawable.hpp"


Drawable* Drawable::list = NULL;
int Drawable::xmax = 0;
int Drawable::ymax = 0;

Drawable::Drawable()
{
	next = Drawable::list;
	prev = NULL;
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
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	xpos += delta;
	if (xpos + xwid >= max_x)
		xpos = max_x - xwid;
	if (xpos < 0)
		xpos = 0;
}

void Drawable::moveY(float delta)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	ypos += delta;
	if (ypos >= max_y)
		ypos = max_y - 1;
	if (ypos < 0)
		ypos = 0;
}

void Drawable::draw_sprite()
{
	for (int i = 0; i < ywid; i++)
		mvprintw(getY() + i, getX(), sprite.substr(xwid * i, xwid).c_str());
}

void Drawable::draw_bar(int lives, int score) {
	int maxx, maxy;
	getmaxyx(stdscr, maxy, maxx);
	std::stringstream bar_text;
	std::stringstream lives_str;

	lives_str << "lives: ";
	for (int i = 0; i < lives; i++) {
		// std::cout << "in lives loog" << std::endl;
		lives_str << ("(O_O)  ");
	}
	// std::cout << lives << std::endl;
	// bar_text[maxx] = {" "}
	bar_text << std::setw(maxx / 2) << lives_str.str() << "  ||    score: " << score;
	mvprintw(LINES - 2, 0, bar_text.str().c_str());
	return ;
}

void Drawable::draw()
{
	mvaddch(getY(), getX(), symbol);
}

void Drawable::move(){}

Drawable* Drawable::getNext()
{
	return next;
}

void Drawable::draw_all()
{
	int lives = 3;
	int score = 42000;
	Drawable *d = list;
	draw_bar(lives, score);
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

void Drawable::collide(){}

void Drawable::collide_check(Drawable *list)
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
		d->collide_check(list);
		d = d->getNext();
	}
	d = list;
	while (d)
	{
		d->collide();
		d = d->getNext();
	}
}