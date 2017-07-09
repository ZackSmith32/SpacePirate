#include <Enemy.hpp>

Enemy::Enemy(void) {

}

Enemy::~Enemy(void) {

}

Enemy & Enemy::operator=(Enemy & src) {
	if (*this == src)
		return (this);
	
	return (this);
}