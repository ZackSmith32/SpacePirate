#ifndef DRAWABLE_HPP
# define DRAWABLE_HPP

#include <iostream>
#include <ncurses.h>

class Drawable{
public:
	Drawable();
	virtual ~Drawable();
	int getX();
	int getY();
	void moveX(int delta);
	void moveY(int delta);
	virtual void move();
	virtual void draw();
	void collide(Drawable *list);
	Drawable* getNext();
	static void draw_all();
	static void move_all();
	static void collide_all();
protected:
	int xpos;
	int ypos;
	char symbol;
	bool collided;
	static Drawable* list;
	Drawable* next;
	Drawable* prev;
};

#endif