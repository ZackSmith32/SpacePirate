#ifndef DRAWABLE_HPP
# define DRAWABLE_HPP

#include <iostream>
#include <ncurses.h>
#include <sstream>	// std::stringstream
#include <iomanip>	// setw (set width)


class Drawable{
public:
	Drawable();
	virtual ~Drawable();
	int getX();
	int getY();
	int getWidX();
	int getWidY();
	static int	xmax;
	static int	ymax;
	void moveX(float delta);
	void moveY(float delta);

	void draw_sprite();

	virtual void move();
	virtual void draw();
	virtual void collide();
	Drawable* getNext();
	static void draw_all();
	static void move_all();
	static void collide_all();
	static bool overlap(Drawable& a, Drawable &b);
	static int difficulty;
protected:
	float xpos;
	float ypos;

	int xwid;
	int ywid;
	std::string sprite;
	
	char symbol;
	bool collided;
	static Drawable* list;
	Drawable* next;
	Drawable* prev;
	static void draw_bar(int lives, int score);
};



#endif