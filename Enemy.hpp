#ifndef ENEMY_H
# define ENEMY_H

#include <iostream>
#include "Drawable.hpp"

class Enemy : public Drawable {

	public:
		Enemy(int xpos, int ypos);
		~Enemy(void);
		Enemy & operator=(Enemy & src);
		void move();

	private:
		float _speed;
		int	_moveIndex;
		int	_moveIndexMax;
		static float _xMoveList[64];
		static float _yMoveList[64];

};


#endif