#include "Boss.hpp"
#include "Bullet.hpp"
#include <cmath>

#define BLOOM_COUNT 25

Boss::Boss(int xpos, int ypos)
{
	this->xpos = xpos;
	this->ypos = ypos;
	counter = 0;
	sprite = "/   \\|0 0|| ^ |\\   /|+++|";
	xwid = 5;
	ywid = 5;
	centerx = 2;
	centery = 2;
}

void Boss::draw(){
	draw_sprite();
}
void Boss::move()
{
	if (counter < 8)
		moveX(-1);
	else
		moveX(1);
	if (counter % 4 == 0)
		shoot_line();
	if (counter == 15)
	{
		shoot_bloom();
		counter = -1;
	}
	counter++;
}
void Boss::collide()
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

void Boss::shoot_bloom()
{
	for (int i = 0; i < BLOOM_COUNT; i++)
	{
		float vel = 2;
		float rad = 7;
		float theta = (float)i * 2 * M_PI / BLOOM_COUNT;
		float px = rad * sin(theta);
		float py = rad * cos(theta);

		new Bullet(getX() + centerx + px, getY() + centery + py, vel * sin(theta), vel * cos(theta), 1);
	}
}

void Boss::shoot_line()
{
	for (int i = 0; i < getWidX(); i++)
		new Bullet(getX() + i, getY() + getWidY() + 1, 0, 2, 1);
}