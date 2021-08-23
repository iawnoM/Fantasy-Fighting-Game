//Riley Monwai
//Lydia Fritz 4/18/21

#pragma once
#ifndef ARENA_H
#define ARENA_H
#include "Guardian.h"
#include "Enemy.h"
#include <istream>
#include <Windows.h>

using namespace std;

class Arena {
private:
	Enemy dreg; 
public:
	Arena(int input) {
		if (input == 0) { dreg = Enemy(25);	}
		else if(input == 1) { dreg = Enemy(40); }
		else if (input == 2) { dreg = Enemy(50); }
	}
	//No user input fight
	int arenaFight(Guardian &g) {
		int reward = (dreg.getHealth() / 5) * 3;
		int end = 1;
		int a = 0; //use for more options later
		if (a == 0) { //Quick fight, no user interaction
			while (g.getHealth() > 0 && dreg.getHealth() > 0) {//Wile both characters have health
				dreg.takeDamage(g.attack());//Player attacks
				if (dreg.getHealth() > 0) { //In case the player One-shots the enemy 
					g.takeDamage(dreg.attack());//Enemy attacks
				}
				//cout << dreg.getHealth() << endl;
			}
			end = postFight(g, reward);
			return end;			
		}
		//else { //slow fight, user input to allow use of potions incase of low health 
		//	while (g.getHealth() > 0 && dreg.getHealth() > 0) {
		//		cout << "Guardian Health:" << g.getHealth() << " | Enemy Health: " << dreg.getHealth() << endl;
		//		int response = 0;
		//		cout << "Press \"0\" to attack again or \"1\" to use potion: ";
		//		cin >> response;
		//		if (response == 1) { //Use potion
		//			cout << "Using potion...New health:" << g.getHealth() << endl;
		//			cout << "Continuing fight!! ";
		//		}
		//		dreg.takeDamage(g.attack());//Player Attacks
		//		g.takeDamage(dreg.attack());//Enemy attacks
		//	}
		//	end = postFight(g, reward);
		//	return end;
		//}
	}
//-----------------Post Fight Method-------------------
	int postFight(Guardian& g, int reward) {
		if (g.getHealth() == 0) {
			cout << g.getName() << " has died, Game Over! " << endl;
			return 0; //Sentinel value 
		}
		else {
			g.addMoney(reward);
			g.setHealth(g.getMaxHealth()); //Regen health after fight
			cout << "Enemy defeated; You earned 15 gold!!" << endl;
			cout << "New character status -> Health:" << g.getHealth() << " | Gold: " << g.getMoney() << endl;
		}
		return 1;
	}
};

#endif // !ARENA_H
