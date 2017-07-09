#include <iostream>
// #include <ncurses.h>
// #include <unistd.h>
#include "Player.hpp"


Player::Player()
{
	xpos = 15;
	ypos = 15;
	symbol = '*';
}

Player::~Player(){}

void Player::move()
{
	int c = wgetch(stdscr);
	if (c == KEY_LEFT)
		moveX(-2);
	else if (c == KEY_RIGHT)
		moveX(2);
	else if (c == KEY_UP)
		moveY(-1);
	else if (c == KEY_DOWN)
		moveY(1);
}



