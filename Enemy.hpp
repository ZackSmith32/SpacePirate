#ifndef ENEMY_H
# define ENEMY_H

#include <ncurses.h>
#include <iostream>

class Enemy : public Drawable {

	public:
		Enemy(void);
		~Enemy(void);
		Enemy & operator=(Enemy & src);
		void move();

	private:
}


#endif