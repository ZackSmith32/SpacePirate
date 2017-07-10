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
	unsigned int lives;
	static int	xmax;
	static int	ymax;
	void moveX(float delta);
	void moveY(float delta);
	static int difficulty;
	static bool playerAlive;
	static int playerLives;

	static void setPlayerLives(int lives);
	static int getPlayerLives();
	static bool getPlayerAlive();
	static void setPlayerAlive();
	void draw_sprite();
	void decrementLives();
	virtual void move();
	virtual void draw();
	virtual void collide();
	Drawable* getNext();
	static void draw_all();
	static void move_all();
	static void collide_all();
	static bool overlap(Drawable& a, Drawable &b);
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
	static void draw_bar(void);
	// static void togglePlayerAlive(void);
};



#endif