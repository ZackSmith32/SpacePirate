#ifndef BULLET_HPP
# define BULLET_HPP

#include <iostream>
#include <ncurses.h>
#include "Drawable.hpp"

class Bullet : public Drawable{
public:
	Bullet(int x, int y, float x_speed, float y_speed, int type);
	void move();
	void collide();
private:
	float x_speed;
	float y_speed;
	int _type;
	static char bullets[6];
};

#endif