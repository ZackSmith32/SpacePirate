#ifndef ENEMY_H
# define ENEMY_H

#include <cmath>
#include <iomanip>	// setw (set width)
#include <iostream>
#include "Drawable.hpp"
#include "header.hpp"

class Enemy : public Drawable {

	public:
		Enemy(int xpos, int ypos, int yLimit, float speed);
		//~Enemy(void);
		Enemy & operator=(Enemy & src);
		void move();
		void draw();
		void collide();

	private:
		float _speed;
		int _yLimit;

		int _routI;
		int _routIMax;
		int	_routineIndexMoves;
		int	_routineIndexMovesMax;
		static float _xRoutine[2][4];
		static float _yRoutine[2][4];

		float _xCurr;
		float _yCurr;

		float _calcMove(int max);
		void _incrementRoutine(void);
};


#endif