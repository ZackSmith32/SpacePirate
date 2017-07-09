#ifndef ENEMY_H
# define ENEMY_H

#include <iostream>
#include "Drawable.hpp"
#include <cmath>

class Enemy : public Drawable {

	public:
		Enemy(int xpos, int ypos, float speed);
		~Enemy(void);
		Enemy & operator=(Enemy & src);
		void incrementRoutine(void);
		void move();
		void draw();

	private:
		float _speed;
		int	_routineIndex;
		int	_routineIndexMax;
		static float _xRoutine[4];
		static float _yRoutine[4];

		float _xCurr;
		float _yCurr;

};


#endif