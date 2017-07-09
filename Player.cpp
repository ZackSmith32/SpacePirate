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
	sprite = " ^ /x\\";
	xwid = 3;
	ywid = 2;
}

void Player::move()
{
	//Drawable::move();
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
		new Bullet(getX() + 1, getY() - 2, 0.25 * (rand()%3 - 1), -1, false);
}

void Player::draw()
{
	draw_sprite();
}