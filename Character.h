//Riley Monwai
//Lydia Fritz 4/18/21

#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>

using namespace std;

class Character {
private:
	int health;
public:
	void takeDamage(int n) { health -= n; }
	void setHealth(int health) { this->health = health; }
	int getHealth() { return health; }
	virtual int attack() = 0;
};

#endif 