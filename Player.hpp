#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "Drawable.hpp"

class Player : public Drawable{
public:
	Player();
	~Player();
	void move();
};

#endif