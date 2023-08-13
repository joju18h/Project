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

public :
	CardGame(int choice) {
		if (choice == 0) {
			mode = "Low";
		}

		else mode = "High";
	}

	void run() {
		int age = 0;

		Player<T>* player[NUM];
		std::cout << "Enter the youth's age : ";
		std::cin >> age;
		player[0] = new YouthPlayer<T>("Noah", age);
		player[1] = new AdultPlayer<T>("Kenneth");
		std::cout << std::fixed << std::setprecision(3);

		bool gameOver = false;
		do {
			float amount = 0;

			std::cout << "How much do you both want to bet ? (min$10, max $300) : ";
			std::cin >> amount;

			if (amount < 10) {
				std::cout << "Amount has been set to min i.e. $10. \n";
				amount = 10;
			}

			else if (amount > 300) {
				std::cout << "Amount has been set to max i.e. $300. \n";
				amount = 300;
			}

			std::cout << std::endl;

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
				std::cout << player[i]->getName() << ", the sum of your cards is "
					<< player[i]->sumAllCards() << std::endl;

				// Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards
				std::cout << "Do you want to add a dependent card? [Y,N] : ";
				std::cin >> choice;

				if (choice == 'y' || choice == 'Y') {
					player[i]->addDependentCard();
					// Report the player's name and the sum of the player's cards
					std::cout << player[i]->getName() << ", the sum of your cards is "
						<< player[i]->sumAllCards() << std::endl;
				}

				while (getchar() != '\n');

				// Ask the player if (s)he wishes to add an attack card to the existing list of attack cards
				std::cout << "Do you want to add an attack card? [Y,N] : ";
				std::cin >> choice;

				if (choice == 'y' || choice == 'Y') {
					player[i]->addAttackCard();
					// Report the player's name and the sum of the player's cards
					std::cout << player[i]->getName() << ", the sum of your cards is "
						<< player[i]->sumAllCards() << std::endl;
				}

				while (getchar() != '\n');

				std::cout << std::endl;
			}

			//Report the name and points for each player
			for (int i = 0; i < NUM; i++) {
				std::cout << player[i]->getName() << " has "
					<< player[i]->sumAllCards() << " points." << std::endl;
			}

			std::cout << std::endl;

			//Determine a winner

			// If both players are disqualified, print that both players are over the limit and have been disqualified.
			if (player[0]->sumAllCards() > 21 && player[1]->sumAllCards() > 21) {
				std::cout << "Both players are over the limit and have been disqualified.\n";
			}

			else if (player[0]->sumAllCards() > 21) {
				std::cout << player[0]->getName() << " has a sum of " << player[0]->sumAllCards()
					<< " which is over the limit.\n";
				std::cout << player[0]->getName() << " has been disqualified. " << player[1]->getName() << " has won.";
				*player[0] >> amount;
				*player[1] << amount;

				std::cout << player[0]->getName() << " has " << player[0]->getCash() << std::endl;
				std::cout << player[1]->getName() << " has " << player[1]->getCash() << std::endl;
			}

			else if (player[1]->sumAllCards() > 21) {
				std::cout << player[1]->getName() << " has a sum of " << player[1]->sumAllCards()
					<< " which is over the limit.\n";
				std::cout << player[1]->getName() << " has been disqualified. " << player[0]->getName() << " has won.";

				*player[0] << amount;
				*player[1] >> amount;


			}

			else if (player[0] == player[1]) {
				std::cout << "Both players have tied with equal number of points. \n";
			}

			else {
				for (int i = 0; i < NUM; i++) {
				std:cout << player[i]->getName() << " has " << player[0]->sumAllCards();
				}

				if (player[0] > player[1]) {
					std::cout << player[0]->getName() << " has won! " << std::endl;
					*player[0] << amount;
					*player[1] >> amount;
				}

				else {
					std::cout << player[1]->getName() << " has won! " << std::endl;
					*player[0] >> amount;
					*player[1] << amount;
				}
			}


			std::cout << std::endl;
			for (int i = 0; i < NUM; i++) {
				std::cout << player[i]->getName() << " has " << player[i]->getCash() << std::endl;
				if (player[i]->getCash() < 0) {
					gameOver = true;
				}
			}

			std::cout << endl;

		} while (!gameOver);

		std::cout << "The game is over." << std::endl;
	}
};

#endif // !_CARDGAME_H_
