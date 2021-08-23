//Riley Monwai
//Lydia Fritz 4/18/21

#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
#include <string>
#include <iostream>

class Armor : public Item {
private:
	int protection;
public:
	Armor() {}
	Armor(string a, int n) { setName(a); protection = n; findPrice(); }
	void setProtection(int protection) { this->protection = protection; }
	int getProtection() { return protection; }
	void findPrice() { setPrice(protection * 2); }
	string displayArmor() { return getName() + ", Prot: " + to_string(getProtection()); }
	void storeArmorDisplay() {
		std: cout << getName() << "(" << protection << "), Price:" << getPrice();
	}
};

#endif // !ARMOR_H
