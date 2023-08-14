//CardGame.h -  header file for running the game
#pragma once

#ifndef _CARDGAME_H_
#define _CARDGAME_H_

#include <iomanip>
#include "Player.h"
#include "AdultPlayer.h"
#include "YouthPlayer.h"

using namespace std;

const int MAX = 21;
const int NUM = 2;

template <class T>
class CardGame  {
	std::string mode;
	float betAmount;
	bool gameOver = false;
	Player<T>* player[NUM];

public :
	CardGame(int choice);
	void run();
	void takeInput();
	void determineWinner();
	void generateCashReport();
	void generatePlayerReport(Player<T>* player);
	~CardGame();
};

//function definitions
template <class T>
CardGame<T>::CardGame(int choice) {
	if (choice == 0) {
		mode = "Low";
	}

	else mode = "High";

	betAmount = 0;
	for (int i = 0; i < NUM; i++) {
		player[i] = nullptr;
	}
}

template <class T>
void CardGame<T>::run() {
	int age = 0;
	std::cout << "Enter the youth's age : ";
	std::cin >> age;
	//names have been harcoded
	player[0] = new YouthPlayer<T>("Noah", age); 
	player[1] = new AdultPlayer<T>("Kenneth");

	do {
		//set betting amount
		std::cout << "How much do you both want to bet ? (min$10, max $300) : ";
		std::cin >> betAmount;

		if (betAmount < 10) {
			std::cout << "Amount has been set to min i.e. $10. \n";
			betAmount = 10;
		}

		else if (betAmount > 300) {
			std::cout << "Amount has been set to max i.e. $300. \n";
			betAmount = 300;
		}
		std::cout << std::endl;

		//take input from players
		takeInput();

		//Report the nameand points for each player for card selection
		for (int i = 0; i < NUM; i++) {
			generatePlayerReport(player[i]);
		}

		//Determine a winner
		determineWinner();
		std::cout << endl;

	} while (!gameOver);

	std::cout << "The game is over." << std::endl;
}

template <class T>
void CardGame<T>::takeInput() {
	for (int i = 0; i < NUM; ++i) {
		int num = 0;
		char choice;

		// Prompt the player for the number of dependent cards
		std::cout << player[i]->getName() << ", how many dependent cards to you want? ";
		std::cin >> num;
		player[i]->addDependentCards(num);

		// Prompt the player for the number of attack cards
		std::cout << player[i]->getName() << ", how many attack cards do you want? ";
		std::cin >> num;
		player[i]->addAttackCard(num);

		// Report the player's name and the sum of the player's cards
		generatePlayerReport(player[i]);

		// Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards
		std::cout << "Do you want to add a dependent card? [Y,N] : ";
		std::cin >> choice;

		if (choice == 'y' || choice == 'Y') {
			player[i]->addDependentCard();
			// Report the player's name and the sum of the player's cards
			generatePlayerReport(player[i]);
		}

		while (getchar() != '\n');

		// Ask the player if (s)he wishes to add an attack card to the existing list of attack cards
		std::cout << "Do you want to add an attack card? [Y,N] : ";
		std::cin >> choice;

		if (choice == 'y' || choice == 'Y') {
			player[i]->addAttackCard();
			// Report the player's name and the sum of the player's cards
			generatePlayerReport(player[i]);
		}

		while (getchar() != '\n');

		std::cout << std::endl;
	}
}

template <class T>
void CardGame<T>::determineWinner() {
	//if both player over 21 disqualify both
	if (player[0]->sumAllCards() > 21 && player[1]->sumAllCards() > 21) {
		std::cout << "Both players are over the limit and have been disqualified.\n";
	}

	// disqualify the one player over 21 and the other one wins
	//deduct and add cash respectively 
	else if (player[0]->sumAllCards() > 21) {
		std::cout << player[0]->getName() << " has a sum of " << player[0]->sumAllCards()
			<< " which is over the limit.\n";
		std::cout << player[0]->getName() << " has been disqualified. " << player[1]->getName() << " has won." << std::endl;
		*player[0] >> betAmount;
		*player[1] << betAmount;
	}

	else if (player[1]->sumAllCards() > 21) {
		std::cout << player[1]->getName() << " has a sum of " << player[1]->sumAllCards()
			<< " which is over the limit.\n";
		std::cout << player[1]->getName() << " has been disqualified. " << player[0]->getName() << " has won." << std::endl;

		*player[0] << betAmount;
		*player[1] >> betAmount;
	}

	//if both players have equal point match is a draw
	else if (*player[0] == *player[1]) {
		std::cout << "Both players have tied with equal number of points. \n";
	}

	//compare the points of both players
	//decide the winner and add/deduct cash respectively
	else {

		if (*player[0] > *player[1]) {
			std::cout << player[0]->getName() << " has won! " << std::endl;
			*player[0] << betAmount;
			*player[1] >> betAmount;
		}

		else {
			std::cout << player[1]->getName() << " has won! " << std::endl;
			*player[0] >> betAmount;
			*player[1] << betAmount;
		}
	}
	std::cout << std::endl;

	//generate cash left report
	generateCashReport();
}

template <class T>
void CardGame<T>::generateCashReport() {
	for (int i = 0; i < NUM; i++) {
		std::cout << player[i]->getName() << " has " << setprecision(2) << player[i]->getCash() << std::endl;
		if (player[i]->getCash() < 0) {
			gameOver = true;
		}
	}
}

template <class T>
void CardGame<T>::generatePlayerReport(Player<T>* player) {
	std::cout << player->getName() << " has "
		<< player->sumAllCards() << " points." << std::endl;
}

template <class T>
CardGame<T>::~CardGame() {
	mode = "";
	betAmount = 0;
	gameOver = false;
	delete[] player;
}
#endif // !_CARDGAME_H_
