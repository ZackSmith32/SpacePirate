#ifndef PLAYER_HPP
# define PLAYER_HPP
#include "Drawable.hpp"

class Player : public Drawable{
public:
	Player();
	~Player();
	Player& operator=(Player& src);
	Player(Player& rhs);
	void move();
	void draw();
	void collide();
};

#endif