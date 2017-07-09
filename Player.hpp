#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "Drawable.hpp"

class Player : public Drawable{
public:
	Player();
	void move();
	void draw();
	void collide();
};

#endif