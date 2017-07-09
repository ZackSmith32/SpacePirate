#include <Enemy.hpp>

float Enemy::_xRoutine[4] = {0, 4, 0, -4};
float Enemy::_yRoutine[4] = {4, 0, 4, 0};

Enemy::Enemy(int x, int y, float speed) {
	xpos = x;
	ypos = y;
	xwid = 3;
	ywid = 3;
	_xCurr = 0;
	_yCurr = 0;
	sprite = " ^ < > v ";
	symbol = '+';

	_speed = speed;
	_routineIndex = 0;
	_routineIndexMax = 3;
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

void Enemy::draw()
{
	draw_sprite();
}

void	Enemy::move() {
	incrementRoutine();
	moveX(_xRoutine[_routineIndex]);
	moveY(_yRoutine[_routineIndex]);

	if (_routineIndex == _routineIndexMax - 1)
		_routineIndex = 0;
	else
		_routineIndex++;
	return ;
}

void	Enemy::incrementRoutine(void) {
	int		xNeg;
	int		yNeg;
	float	tXCurr = _xCurr;
	float	tXMax = _xRoutine[_routineIndex];
	float	tYCurr = _yCurr;
	float	tYMax = _yRoutine[_routineIndex];

	// change to positive
	if (tXMax < 0) {
		xNeg = 1;
		tXCurr *= -1;
		tXMax *= -1;
	}
	if (tYMax < 0) {
		yNeg = 1;
		tYCurr *= -1;
		tYMax *= -1;
	}
	// see if curr has reached script val
	if (tXCurr >= tXMax || tYCurr >= tYMax) {
		if (_routineIndex == _routineIndexMax)
			_routineIndex++;
		else
			_routineIndex = 0;
	}
}
































