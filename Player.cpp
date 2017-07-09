#include <iostream>
#include <ncurses.h>
#include <unistd.h>
#include "Bullet.hpp"
#include "Player.hpp"

Player::Player()
{
	xpos = 15;
	ypos = 15;
	symbol = '*';
	sprite = " ^ / \\";
	xwid = 3;
	ywid = 2;
}

Player::~Player(){}

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
	else if (c == ' ')
		new Bullet(getX(), getY() - 1, -1, false); //needs to be centered
}

void Player::draw()
{
	draw_sprite();
}