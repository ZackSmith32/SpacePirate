#include <Enemy.hpp>

int Enemy::_xMoveList[4] = {0, 4, 0, -4};
int Enemy::_yMoveList[4] = {4, 0, 4, 0};

Enemy::Enemy(int x, int y) {
	xpos = x;
	ypos = y;
	symbol = '+';

	_moveIndex = 0;
	_moveIndexMax = 3;
	std::cout << "innitiated" << std::endl;
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

	std::cout << "x move = " << _xMoveList[_moveIndex] << std::endl;
	std::cout << "y move = " << _yMoveList[_moveIndex] << std::endl;
	if (_moveIndex == _moveIndexMax)
		_moveIndex = 0;
	else
		_moveIndex++;
	return ;
}