#include "Drawable.hpp"
#include "header.hpp"
#include "Enemy.hpp"

class Boss : public Drawable {
public:
	Boss();
	~Boss();
	Boss& operator=(Boss & src);
	Boss(Boss& rhs);
	Boss(int xpos, int ypos);

	void move();
	void draw();
	void collide();
private:
	void shoot_bloom();
	void shoot_line();
	int counter;
	int centerx;
	int centery;
};

