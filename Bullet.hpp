#ifndef BULLET_HPP
# define BULLET_HPP

#include <iostream>
#include <ncurses.h>
#include "Drawable.hpp"

class Bullet : public Drawable{
public:
	Bullet(int x, int y, float speed, bool enemy);
	void move();
private:
	float speed;
	bool enemy;
};

#endif