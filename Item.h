//Riley Monwai
//Lydia Fritz 4/18/21

#pragma once
#ifndef ITEM_H
#define ITEM_H
#include <iostream>

using namespace std;

class Item {
private:
	string name;
	int price;
public:
	virtual void findPrice() = 0;
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void setPrice(int price) { this->price = price; }
	int getPrice() { return price; }
};

#endif // !ITEM_H
