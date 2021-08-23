//Riley Monwai
//Lydia Fritz 4/18/21

#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

class Weapon : public Item {
private:
	int damage;
public:
	Weapon() {}
	Weapon(string a, int n) { setName(a); damage = n; findPrice(); }
	void findPrice() { setPrice(damage * 2); }
	void setDamage(int damage) { this->damage = damage; }
	int getDamage() { return damage; }
	string displayWeapon() { return getName() + ", Attack:" + to_string(damage); } 
	void storeWeaponDisplay() {
		cout << getName() << "(" << damage << "), Price:" << getPrice();
	}

};
#endif // !WEAPON_H