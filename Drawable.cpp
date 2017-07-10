#include <iostream>
#include "Drawable.hpp"


Drawable* Drawable::list = NULL;
int Drawable::xmax = 0;
int Drawable::ymax = 0;
bool Drawable::playerAlive = true;
int Drawable::playerLives = 0;

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
	{
		Drawable::list = next;
		if (Drawable::list)
			Drawable::list->prev = NULL;
	}
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

void Drawable::draw_bar(void) {
	int maxx, maxy;
	// int score = 42000;
	int lives = Drawable::getPlayerLives();
	getmaxyx(stdscr, maxy, maxx);
	std::stringstream bar_text;
	std::stringstream lives_str;

	lives_str << "lives: " << lives;
	// for (int i = 0; i < lives; i++) {
	// 	lives_str << ("(O_O)  ");
	// }
	bar_text << std::setw(maxx / 2) << lives_str.str();
	// << "  ||    score: " << score;
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
	
	Drawable *d = list;
	draw_bar();
	while (d != NULL)
	{
		d->draw();
		d = d->getNext();
	}
}

void Drawable::move_all()
{
	Drawable *d = list;
	while (d != NULL)
	{
		d->move();
		d = d->getNext();
	}
}

bool Drawable::overlap(Drawable& a, Drawable &b)
{
	if (a.getX() + a.getWidX() < b.getX() || \
		b.getX() + b.getWidX() < a.getX() || \
		a.getY() + a.getWidY() < b.getY() || \
		b.getY() + b.getWidY() < a.getY())
		return false;
	return true;
}

void Drawable::collide(){}

void Drawable::collide_all()
{
	Drawable *d = list;
	while (d != NULL)
	{
		d->collide();
		d = d->getNext();
	}
}

void Drawable::decrementLives() {
	lives--;
}

bool Drawable::getPlayerAlive(void) {
	return (playerAlive);
}

void Drawable::setPlayerAlive(void) {
	playerAlive = false;
}

int Drawable::getPlayerLives(void) {
	return (playerLives);
}

void Drawable::setPlayerLives(int lives) {
	playerLives = lives;
}





























