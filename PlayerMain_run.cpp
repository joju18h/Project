//PlayerMain.cpp - main program for the game

#include<iostream>

using namespace std;

#include "CardGame.h"

int main(void) {

	int choice;

	std::cout << "Press 0 for low definition mode and 1 for high definition mode : ";
	cin >> choice;

	if (choice == 0) {
		//int for low definition mode
		CardGame<int> cGame1(choice);
		cGame1.run();
	}

	else {
		//float for high definition mode
		CardGame<double> cGame2(choice);
		cGame2.run();
	}

	return 0;
}
