#include <Enemy.hpp>
#include <header.hpp>
#include <Bullet.hpp>

float Enemy::_xRoutine[2][4] = { {0, 10, 0, -10}, {0, 10, 0, -10} };
float Enemy::_yRoutine[2][4] = { {10, 0, 10, 0}, {10, 0, -10, 0} };
int Enemy::enemies_alive = 0;

Enemy::Enemy(int x, int y, int yLimit, float speed) {
	if (DEBUG)
		std::cout << "DEBUG" << DEBUG << std::endl;
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
	lives = 1;

	// sub routine index/max
	_routI = 0;
	_routIMax = 1;
	// index within a routine
	_routineIndexMoves = 0;
	_routineIndexMovesMax = 3;
	setEnemiesAlive(getEnemiesAlive() + 1);
	return ;
}

Enemy::~Enemy() 
{
	setEnemiesAlive(getEnemiesAlive() - 1);
}

Enemy & Enemy::operator=(Enemy & src) {
	xpos = src.xpos;
	ypos = src.ypos;
	xwid = src.xwid;
	ywid = src.ywid;
	_xCurr = src._xCurr;
	_yCurr = src._yCurr;
	sprite = src.sprite;
	symbol = src.symbol;
	_yLimit = src. _yLimit;
	_speed = src._speed;
	_routI = src._routI;
	_routIMax = src._routIMax;
	_routineIndexMoves = src._routineIndexMoves;
	_routineIndexMovesMax = src._routineIndexMovesMax;
	return (*this);
}

Enemy::Enemy(Enemy& rhs)
{
	*this = rhs;
}

void Enemy::draw()
{
	draw_sprite();
}

void Enemy::erase()
{
	erase_sprite();
}

void	Enemy::move() {
	_incrementRoutine();

	float	xMove = _calcMove(_xRoutine[_routI][_routineIndexMoves]);
	float	yMove = _calcMove(_yRoutine[_routI][_routineIndexMoves]);
	if (DEBUG) {
		std::cout << "x =" << std::setw(6) << xMove;
		std::cout << ";  y =" << std::setw(6) << yMove;
		std::cout << std::endl << std::endl;
		
		std::cout << "y = " << _yCurr << std::endl;
	}
	moveX(xMove);
	moveY(yMove);
	if (rand() % 10 == 0)
	{
		// std::cout << "bullet made" << std::endl;
		new  Bullet(getX() + xwid / 2, getY() + ywid + 2, 0, 0.5, 1);
	}

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
	float	tXMax = _xRoutine[_routI][_routineIndexMoves];
	float	tYCurr = _yCurr;
	float	tYMax = _yRoutine[_routI][_routineIndexMoves];

	// change to positive
	if (tXMax < 0) {
		tXCurr *= -1;
		tXMax *= -1;
	}
	if (tYMax < 0) {
		tYCurr *= -1;
		tYMax *= -1;
	}

	// if enemy reaches bottome of screen
	if (ypos >= _yLimit && _routI != _routIMax) {
		_routI++;
		if (_routineIndexMoves == _routineIndexMovesMax)
			_routineIndexMoves = 0;
		else
			_routineIndexMoves++;
	}
	// see if curr has reached script val
	else if (tXCurr >= tXMax && tYCurr >= tYMax) {
		_xCurr = 0;
		_yCurr = 0;
		if (_routineIndexMoves == _routineIndexMovesMax)
			_routineIndexMoves = 0;
		else
			_routineIndexMoves++;
	}
}

void Enemy::collide()
{
	Drawable* d = Drawable::list;

	for (; d != NULL; d = d->getNext())
	{
		if (d == this)
			continue;
		if (overlap(*this, *d))
		{
			delete this;
			return;
		}
	}
}

int Enemy::getEnemiesAlive()
{
	return enemies_alive;
}

void Enemy::setEnemiesAlive(int count)
{
	enemies_alive = count;
}