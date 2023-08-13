//PlayerMain.cpp - main program for the card player

#include<iostream>

using namespace std;

//PlayerMain.cpp - main program for the card player

#include "CardGame.h"

int main(void) {
	
	int choice;

	std::cout << "Press 0 for high definition mode and 1 for low definition mode : ";
	cin >> choice;

	if (!choice) {
		CardGame<int> cGame1(choice);
		cGame1.run();
	}
	
	else {
		CardGame<double> cGame2(choice);
		cGame2.run();
	}

	return 0;
}