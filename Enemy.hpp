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
		int	_moveIndex;
		int	_moveIndexMax;
		static float _xMoveList[16];
		static float _yMoveList[16];

};


#endif