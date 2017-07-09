#ifndef BULLET_HPP
# define BULLET_HPP

#include <iostream>
#include <ncurses.h>
#include "Drawable.hpp"

class Bullet : public Drawable{
public:
	Bullet(int x, int y, float x_speed, float y_speed, bool enemy);
	void move();
private:
	float x_speed;
	float y_speed;
	bool enemy;
};

#endif