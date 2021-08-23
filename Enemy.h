//Riley Monwai
//Lydia Fritz 4/18/21

#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"

class Enemy : public Character {
private:
	int damage;
	//int tier;
public:
	Enemy() {};
	Enemy(int a) { setHealth(a); damage = a / 5; }
	/*void setTier(int tier) { this->tier = tier; }
	int getTier() { return tier; }*/
	//void setDamage(int damage) { this->damage = damage; }
	int getDamge() { return damage; }
	int attack() { return damage; }
};

#endif // !ENEMY_H
