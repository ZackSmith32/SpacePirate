#ifndef DRAWABLE_HPP
# define DRAWABLE_HPP

#include <iostream>

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

#endif