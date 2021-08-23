//Riley Monwai
//Lydia Fritz 4/18/21

#pragma once
#ifndef STORE_H
#define STORE_H
#include "Armor.h"
#include "Weapon.h"
#include <random>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Store {
private:
	vector<Weapon> wepInv;
	vector<Armor> armorInv;
	/*Weapon weaponInv[12];
	Armor armorInv[12];*/
public:
	Store() {}
	Store(Guardian g) {
		srand(time(NULL));
		string weaponNames[11] = { "Falling-Guillotine","Black-Talon","Throne-Cleaver","Quickfang","Lament",
			"Xenophage","Anarchy","Hammerhead","Gjallarhorn","Truth","Dark-Drinker" };
		string armorNames[11] = { "Exile-Set", "Extinction-Set", "Wild-Hunt-Set","Iron-Will-Set","Soverign-Set","Solstice-Set",
			"Pyrric-Set","Judgement-Set","Righteous-Set","Seraph-Set","Truage Set" };
		for (int i = 0; i < 11; i++) {
			Armor a = Armor(armorNames[i], (rand() % 4 + 2) * 5); //Assigns random protection value to armor
			Weapon n = Weapon(weaponNames[i], (rand() % 4 + 2) * 5);//Assigns random damage value to weapons
			wepInv.push_back(n);//Add weapon to store vector inventory 
			armorInv.push_back(a);//Add armor to store vector inventory 
			/*cout << weaponInv[i].displayWeapon() << endl;
			cout << armorInv[i].displayArmor() << endl;*/
		}
	}
	void displayOptions(string n){
		cout << "Options: <";
		for (int i = 0; i < 3; i++) {
			if (n == "W") {
				wepInv[i].storeWeaponDisplay(); 
				//weaponInv[i].storeWeaponDisplay();
				if (i != 2) {
					cout << " | ";
				}
			}
			else if (n == "A") {
				armorInv[i].storeArmorDisplay();
				//cout << armorInv[i].displayArmor();
				if (i != 2) {
					cout << " | ";
				}
			}
		}
		cout << "> ";
	}
	//-------------------Buy Weapon------------------------
	void buyWeapon(int n, Guardian& g) {
		Weapon newWep = wepInv[n];
		if (g.getMoney() > newWep.getPrice()) {
			wepInv.erase(wepInv.begin() + n);//Erase item from store inventory 
			g.subtractMoney(newWep.getPrice());//Take money from player
			g.addToWeaponInv(newWep);//Add item to player inventory 
			//g.setWepFromInv(0);//Equips weapon and changes guardian damage value
			//g.setWeapon(newWep);
			cout << "New weapon aquired! " << newWep.displayWeapon() << endl;
			cout << "To equip weapon, enter P to go to player options. " << endl;
		}
		else {
			cout << "You do not have enough money to purchase that item!";
			cout << "Exiting shop...";
		}
	}
//------------------Buy Armor------------------------------
	void buyArmor(int n, Guardian& g) {
		Armor newArmor = armorInv[n];
		if (g.getMoney() > newArmor.getPrice()) {
			armorInv.erase(armorInv.begin() + n);//Erase item from store inventory 
			g.subtractMoney(newArmor.getPrice());//Take money from player
			g.addToArmorInv(newArmor);//Add item to player inventory 
			//g.setArmorFromInv(0);//Equips armor and changes guardian protection value 
			//g.setArmor(newArmor);
			cout << "New armor aquired! " << newArmor.displayArmor() << endl;
			cout << "To equip armor, enter P to go to player options. " << endl;
		}
		else {
			cout << "You do not have enough money to purchase that item!";
			cout << "Exiting shop...";
		}
	}
};

#endif // !STORE_H
