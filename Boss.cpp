#include "Boss.hpp"
#include "Bullet.hpp"
#include <cmath>

Boss::Boss(int xpos, int ypos)
{
	this->xpos = xpos;
	this->ypos = ypos;
}

void Boss::draw(){}
void Boss::move()
{
	shoot_bloom();
}
void Boss::collide(){}

void Boss::shoot_bloom()
{
	for (int i = 0; i < 20; i++)
	{
		float vel = 2;
		new Bullet(getX(), getY(), vel * sin((float)i /20 * M_2_PI), vel * cos((float)i / 20 * M_2_PI), 1);
	}
}

void Boss::shoot_line()
{}