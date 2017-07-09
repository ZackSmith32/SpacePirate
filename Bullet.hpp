#ifndef BULLET_HPP
# define BULLET_HPP

#include <iostream>
#include "Drawable.hpp"

class Bullet : public Drawable{
public:
	Bullet(int x, int y, int speed);
	~Bullet();
	void move();
private:
	int speed;
};

#endif