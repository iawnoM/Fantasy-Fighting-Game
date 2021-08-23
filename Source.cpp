//Riley Monwai
//Lydia Fritz 4/18/21

#include <iostream>
#include <fstream>
#include "Armor.h"
#include "Guardian.h"
#include "Weapon.h"
#include "Store.h"
#include "Arena.h"
#include <Windows.h>

using namespace std;

void savePlayer(Guardian);
void loadPlayer(Guardian&);
Guardian storeLoop(Store &s, Guardian g);

int main() {
	Guardian g;
	Store s = Store(g);
	string entry = "";
	cout << "Welcome to the Fantasy Fighting Game! Please enter a name for your character or enter \"F\" for file load: ";
	cin >> entry;
	if (entry == "F") {
		loadPlayer(g);
		g.displaySet();
	}
	else {
		g = Guardian(entry);
	}
	cout << "At any time during game, enter \"P\" to enter player management and show player data, \"Q\" to enter the shop,";
	cout<<"\n\"A\" to enter arena, \"S\" to save player data to file. Or \"E\" to exit game." << endl;
	cout << "Where would you like to start? ";
	string input;
	int sentinel = 1; 
	//Game loop
	do { 
		cin >> input;
//--------Save Player Data-----------
		if (input == "S") {
			savePlayer(g);
			cout<<"Player data saved to file!"<<endl;
		}
//-----------Player Data-------------
		else if (input == "P") {
			int n;
			g.displaySet();
			cout << "Do you want to equip new item from inventory? Yes(0), No(1): ";
			cin >> n;
			if (n == 0) {
				g.displayInventory();
				cout << "What do you want to equip? (Enter index number): ";
				cin >> n;
				g.setWepFromInv(n);
				cout << g.getWeapon().getName() << " equipped! ";
			}
		}
//--------------Shop-----------------
		else if (input == "Q") {
			g = storeLoop(s, g);
			//cout << g.getWeapon().displayWeapon()<< endl << g.getMoney();
		}
//---------------Arena---------------
		else if (input == "A") {
			cout << "Heading to the fighting arena"; Sleep(500); cout << "."; Sleep(500); cout << "."; Sleep(500); cout << "." << endl;
			cout << "Welcome! Your current health is: " << g.getHealth() << endl;//Display health and gold
			/*cout << "Press 0 to quick-fight or 1 to normal-fight: ";
			int fight; //NOT DEVELOPED YET
			cin >> fight;*/
			int level;
			cout << "What level enemy would you like to fight? (0,1, or 2): ";
			cin >> level;
			Arena a = Arena(level);
			sentinel = a.arenaFight(g);
			if (sentinel == 0) { //If player is dead, end loop 
				break;
			}
		}
		else if (input == "E") {
			cout << "Exiting game..."; Sleep(500);
			sentinel = 0;//End program 
			break;
		}
		else {
			cout << "Invalid entry, please enter a valid input. ";
		}
		cout << "Where would you like to go next? ";
	} while (sentinel != 0);//Ends program
	return 0;
}

void loadPlayer(Guardian& g) {
	cout << "Loading character progress"; Sleep(350); cout << "."; Sleep(350); cout << "."; Sleep(350); cout << "."; Sleep(350);
	int health; string name; int money;  string weapon; int damage;
	string armor; int prot; ifstream fin("player.dat");
	if (!fin) {
		cout << "File error";
		exit(1);
	} 
	fin >> name >> health >> money >> weapon >> damage >> armor >> prot;
	g.setName(name); g.setHealth(health); g.setMoney(money);
	g.setWeapon(Weapon(weapon, damage));
	g.setArmor(Armor(armor, prot));
}

void savePlayer(Guardian cPtr) {
	//write character to file 
	ofstream fout("player.dat");
	fout << cPtr.getName() << " " << cPtr.getHealth() << " " <<cPtr.getMoney() << " ";
	fout << cPtr.getWeapon().getName() << " " << cPtr.getWeapon().getDamage() << " ";
	fout << cPtr.getArmor().getName() << " " << cPtr.getArmor().getProtection() << endl;
	fout.close();
}

Guardian storeLoop(Store &s, Guardian g) {
	int indexNum;
	string type = "";
	cout << "Welcome to the Item Shop!\nYour current balance is : " << g.getMoney() << " Gold.";
	cout << "Press \"A\" to shop armor, \"W\" for weapons, or H for health: ";
	cin >> type;
	cout << "To buy item, enter index of item as it appears on screen..." << endl;
	s.displayOptions(type);//Shows available items to buy 
	cin >> indexNum;	
	if (type == "W") {
		s.buyWeapon(indexNum, g);
	}
	else if (type == "A") {
		s.buyArmor(indexNum, g);
	}
	/*else if (type == "H") { //For player healing
		cout << "Options: <+25 Health, Price 25 | Full Heal, Price: 50> ";
	}*/
	//g.displaySet();
	return g; 
} 