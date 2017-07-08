#include <iostream>
#include <ncurses.h>
#include <unistd.h>

class Drawable{
public:
	Drawable();
	int getX();
	int getY();
	void moveX(int delta);
	void moveY(int delta);
	void move();
	void draw();
	Drawable* getNext();
	static void draw_all();
	static void move_all();
protected:
	int xpos;
	int ypos;
	char symbol;
	static Drawable* list;
	Drawable* next;
};

Drawable* Drawable::list = NULL;

Drawable::Drawable()
{
	next = Drawable::list;
	Drawable::list = this;
}

int Drawable::getX()
{
	return xpos;
}

int Drawable::getY()
{
	return ypos;
}

void Drawable::moveX(int delta)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	xpos += delta;
	if (xpos >= max_x)
		xpos = max_x - 1;
	if (xpos < 0)
		xpos = 0;
}

void Drawable::moveY(int delta)
{
	int max_x, max_y;
	getmaxyx(stdscr, max_y, max_x);
	ypos += delta;
	if (ypos >= max_y)
		ypos = max_y - 1;
	if (ypos < 0)
		ypos = 0;
}

void Drawable::draw()
{
	int x, y;
	x = getX();
	y = getY();
	mvaddch(y, x, symbol);
}

void Drawable::move(){}

Drawable* Drawable::getNext()
{
	return next;
}

void Drawable::draw_all()
{
	Drawable *d = list;
	while (d)
	{
		d->draw();
		d = d->getNext();
	}
}

void Drawable::move_all()
{
	Drawable *d = list;
	while (d)
	{
		d->move();
		d = d->getNext();
	}
}

class Player : public Drawable{
public:
	Player();
	~Player();
	void move();
};

Player::Player()
{
	xpos = 15;
	ypos = 15;
	symbol = '*';
}

Player::~Player(){}

void Player::move()
{
	int c = wgetch(stdscr);
	if (c == KEY_LEFT)
		moveX(-2);
	else if (c == KEY_RIGHT)
		moveX(2);
	else if (c == KEY_UP)
		moveY(-1);
	else if (c == KEY_DOWN)
		moveY(1);
}

class Bullet : public Drawable{
public:
	Bullet(int x, int y, int speed);
	~Bullet();
	void move();
private:
	int speed;
};

Bullet::Bullet(int x, int y, int speed)
{
	xpos = x;
	ypos = y;
	this->speed = speed;
	symbol = '.';
}

Bullet::~Bullet(){}

void Bullet::move()
{
	moveY(speed);
}

int main (void)
{
	initscr();
	noecho();
	raw();
	keypad(stdscr, TRUE);
	curs_set(0);
	//nodelay(stdscr, TRUE);
	Player p;
	Bullet b(0, 15, 3);
	while(1)
	{
		clear();
		p.move();
		p.draw();
		b.move();
		b.draw();
		refresh();
	}
	endwin();
	return 0;
}