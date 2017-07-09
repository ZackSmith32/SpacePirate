class Bullet : public Drawable{
public:
	Bullet(int x, int y, int speed);
	~Bullet();
	void move();
private:
	int speed;
};
