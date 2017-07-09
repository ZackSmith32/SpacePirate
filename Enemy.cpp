#include <Enemy.hpp>

float i = 0.25;
float Enemy::_xMoveList[16] = {0,0,0,0, i,i,i,i, 0,0,0,0, -i,-i,-i,-i};
float Enemy::_yMoveList[16] = {i,i,i,i, 0,0,0,0, i,i,i,i,  0,0,0,0};

Enemy::Enemy(int x, int y) {
	xpos = x;
	ypos = y;
	symbol = '+';

	_moveIndex = 0;
	_moveIndexMax = 16;
	return ;
}

Enemy::~Enemy(void) {
	return ;
}

Enemy & Enemy::operator=(Enemy & src) {
	if (this == &src)
		return (*this);

	return (*this);
}

void	Enemy::move() {
	moveX(_xMoveList[_moveIndex]);
	moveY(_yMoveList[_moveIndex]);

	if (_moveIndex == _moveIndexMax - 1)
		_moveIndex = 0;
	else
		_moveIndex++;
	return ;
}