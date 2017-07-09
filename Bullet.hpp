#ifndef BULLET_HPP
# define BULLET_HPP

#include <iostream>
#include <ncurses.h>
#include "Drawable.hpp"

class Bullet : public Drawable{
public:
	Bullet(int x, int y, float speed, int type);
	void move();
private:
	float speed;
	static char bullets[6];
};

#endif