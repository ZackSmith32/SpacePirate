#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Bullet.hpp"
#include "Player.hpp"

Player::Player()
{
	getmaxyx(stdscr, ypos, xpos);
	xpos /= 2;
	ypos -= 5;
	symbol = '*';
	sprite = "x";
	xwid = 1;
	ywid = 1;
	lives = 4;
	Drawable::setPlayerLives(3);
}

Player::~Player() {
	Drawable::setPlayerAlive();
}

Player& Player::operator=(Player& src)
{
	xpos = src.xpos;
	ypos = src.ypos;
	symbol = src.symbol;
	sprite = src.sprite;
	xwid = src.xwid;
	ywid = src.ywid;
	return *this;
}
Player::Player(Player& rhs)
{
	*this = rhs;
}

void Player::move()
{
	Drawable::move();
	int c = wgetch(stdscr);
	if (c == KEY_LEFT)
		moveX(-2);
	else if (c == KEY_RIGHT)
		moveX(2);
	else if (c == KEY_UP)
		moveY(-1);
	else if (c == KEY_DOWN)
		moveY(1);
	new Bullet(getX() + 1, getY() - 2, 0.25 * (rand()%3 - 1), -0.75, false);
}

void Player::collide()
{
	Drawable* d = Drawable::list;

	for (; d != NULL; d = d->getNext())
	{
		if (d == this)
			continue;
		if (overlap(*this, *d))
		{
			Drawable::setPlayerLives(Drawable::getPlayerLives() - 1);
			this->decrementLives();
			getmaxyx(stdscr, ypos, xpos);
			xpos /= 2;
			ypos -= 5;
			delete d;
			if (this->Drawable::getPlayerLives() == 0)
				delete this;
			return;
		}
	}
}

void Player::draw()
{
	draw_sprite();
	mvaddch(getY() - 1, getX(), '^');
	mvaddch(getY(), getX() - 1, '/');
	mvaddch(getY(), getX() + 1, '\\');
}

void Player::erase()
{
	erase_sprite();
	mvaddch(getY() - 1, getX(), ' ');
	mvaddch(getY(), getX() - 1, ' ');
	mvaddch(getY(), getX() + 1, ' ');
}