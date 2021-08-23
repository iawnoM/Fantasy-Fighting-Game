//Riley Monwai
//Lydia Fritz 4/18/21

#ifndef GUARDIAN_H
#define GUARDIAN_H
#include "Character.h"
#include "Armor.h"
#include "Weapon.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Guardian : public Character {
private:
	string name;
	int money;
	int damage;
	int maxHealth;
	Weapon currWeapon;
	Armor currArmor;
	vector<Weapon> wepInventory;
	vector<Armor> armorInventory;
public:
	Guardian() {}
	Guardian(string n) {
		setName(n); setMoney(100); setHealth(100);
		Weapon a = Weapon("Sword", 5);
		Armor b = Armor("Destroyed Set", 1);
		setArmor(b);
		setWeapon(a);
		newGuardian();	
		maxHealth = 100;
	}
//---------------General Player Methods----------------
	void basicDisplay() {
		cout << name << "'s current Health: " << getHealth() << " | Gold:" << money << endl;
	}
	void displaySet() {
		cout << "-----------------------------------" << endl;
		cout << "Current Set for " << name << " is: " << endl;
		cout << "Health: " << getHealth() << " | Gold: " << money << endl;
		cout << "Weapon: " << currWeapon.displayWeapon() << endl;
		cout << "Armor: " << currArmor.displayArmor() << endl;
		cout << "-----------------------------------" << endl;
	}
	void newGuardian() {
		cout << "Greetings " << name << "! You start with 100 Health and 0 Gold" << endl;
	}
	void displayInventory() {
		int n;
		cout << "Enter 0 for weapons or 1 for armor";
		cin >> n;
		cout << "<";
		if (n == 0) {
			for (int i = 0; i < wepInventory.size(); i++) {
				cout<<wepInventory[i].displayWeapon()<<",";
			} 
		}
		else if (n == 1) {
			for (int i = 0; i < armorInventory.size(); i++) {
				cout << armorInventory[i].displayArmor() << ",";
			}
		}
		cout << ">";
	}
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void increaseMaxHealth() { maxHealth = 100+currArmor.getProtection(); }
	int getMaxHealth() { return maxHealth; }
	int attack() { return currWeapon.getDamage(); }
//---------------Money Methods--------------------------
	void setMoney(int money) { this->money = money; }
	void addMoney(int n) { money += n; }
	void subtractMoney(int n) { money -= n; }
	int getMoney() { return money; }
//---------------Item Methods---------------------------
	//---------------------Weapon-----------------------
	void setDamage() { damage = currWeapon.getDamage(); }
	int getDamage() { return damage; }
	void setWeapon(Weapon a) { currWeapon = a; damage = a.getDamage(); }
	void setWepFromInv(int n) { 
		addToWeaponInv(getWeapon()); //Add current equipped weapon to inventory
		setWeapon(wepInventory[n]); //Equip new weapon
		damage = currWeapon.getDamage(); //Set new damage
		wepInventory.erase(wepInventory.begin() + n); //Remove equpped weapon from inventory 
	}
	Weapon getWeapon() { return currWeapon; }
	//--------------------Armor-------------------------
	void setArmor(Armor a) { currArmor = a; }
	void setArmorFromInv(int n) { 
		addToArmorInv(getArmor());
		setArmor(armorInventory[n]); 
		increaseMaxHealth(); 
		setHealth(maxHealth); }
	Armor getArmor() { currArmor.displayArmor(); return currArmor; }
//-------------Methods to add to Inventory--------------
	void addToArmorInv(Armor a) { armorInventory.push_back(a); }
	void addToWeaponInv(Weapon w) { wepInventory.push_back(w); }
//------------------------------------------------------
};

#endif
