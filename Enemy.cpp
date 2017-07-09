#include <Enemy.hpp>

float Enemy::_xRoutine[4] = {0, 10, 0, -10};
float Enemy::_yRoutine[4] = {10, 0, 10, 0};

Enemy::Enemy(int x, int y, int yLimit, float speed) {
	xpos = x;
	ypos = y;
	xwid = 3;
	ywid = 3;
	_xCurr = 0;
	_yCurr = 0;
	sprite = " ^ < > v ";
	symbol = '+';
	_yLimit = yLimit;

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
	_incrementRoutine();

	float	xMove = _calcMove(_xRoutine[_routineIndex]);
	float	yMove = _calcMove(_yRoutine[_routineIndex]);
	if (!DEBUG) {
		std::cout << "x =" << std::setw(6) << xMove;
		std::cout << ";  y =" << std::setw(6) << yMove;
		std::cout << std::endl << std::endl;
		
	}
	moveX(xMove);
	moveY(yMove);

	_xCurr += xMove;
	_yCurr += yMove;
	return ;
}

float	Enemy::_calcMove(int max) {
	float	delta = _speed;

	if (max < 0)
		delta *= -1;
	if (max == 0)
		delta = 0;
	return (delta);
}

void	Enemy::_incrementRoutine(void) {
	float	tXCurr = _xCurr;
	float	tXMax = _xRoutine[_routineIndex];
	float	tYCurr = _yCurr;
	float	tYMax = _yRoutine[_routineIndex];

	// change to positive
	if (tXMax < 0) {
		tXCurr *= -1;
		tXMax *= -1;
	}
	if (tYMax < 0) {
		tYCurr *= -1;
		tYMax *= -1;
	}
	// see if curr has reached script val
	if (tXCurr >= tXMax && tYCurr >= tYMax) {
		_xCurr = 0;
		_yCurr = 0;
		if (_routineIndex == _routineIndexMax)
			_routineIndex = 0;
		else
			_routineIndex++;
	}
}
































