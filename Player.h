#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


//Range constants for generating dependent cards
#define DEPMIN 1
#define DEPMAX 5

//base Player class definition
template <typename T>
class Player
{
    protected:
        std::string name;
        double cash;
        std::vector<int> dependentCards; //always int

    public:
        Player(); //default constructor
        Player(const std::string player); //hardcoded names to be passed

        // BaseClass Functions
        void setName(const std::string);
        std::string getName() const;

        void addDependentCards(int numCards);
        void addDependentCard();
        int sumDependentCards() const;

        double getCash() const;
        void addCash(double);

        //overloaded operator function
        Player& operator=(const Player& otherPlayer);

        //virtual overridden functions
        virtual void addAttackCard() =0;
        virtual void addAttackCard(int) =0;
        virtual  T sumAttackCards() const =0;
        virtual T sumAllCards() const =0;
        virtual bool operator==(const Player<T>& p2) = 0;
        virtual bool operator>(const Player<T> &p2) =0;
        virtual bool operator<(const Player<T> &p2) =0;
        virtual void operator<<(double amt) =0;
        virtual void operator>>(double amt) =0;

        ~Player(){};
};


//function definitions

//constructor functions
template <typename T>
Player<T>::Player()
{
    this->name = "";
    this->cash = 1000.00;
};

template <typename T>
Player<T>::Player(const std::string player)
{
    this->name = player;
    this->cash = 1000.00;
};


//setter getter functions
template <typename T>
void Player<T>::setName(const std::string name)
{
    this->name = name;
};

template <typename T>
std::string Player<T>::getName() const
{
    return this->name;
};

template <typename T>
double Player<T>::getCash() const
{
    return this->cash;
};

//dependent card generator functions
//these functions generate random number 
//between 1 (DEPMIN) to 5 (DEPMIN)
template <typename T>
void Player<T>::addDependentCards(int numCards)
{
    
    this->dependentCards.clear();
    srand(time(0));
    for(int i = 0; i < numCards; i++){
        this->dependentCards.push_back((rand() % DEPMAX) + DEPMIN);
    }
};

template <typename T>
void Player<T>::addDependentCard()
{
    srand(time(0));
    this->dependentCards.push_back((rand() % DEPMAX) + DEPMIN);
};

//sums all the dependent cards
template <typename T>
int Player<T>::sumDependentCards() const
{
    int sum = 0;
    for (int card : this->dependentCards) {
        sum += card;
    }
    return sum;
};

//Adds amount to player's cash
template <typename T>
void Player<T>::addCash(double amt)
{
    this->cash += amt;
};

//overloaded operator function
template <class T>
Player<T>& Player<T>::operator=(const Player<T> & otherPlayer) {
    this->name = otherPlayer.getName();
    this->cash = otherPlayer.getCash();
    this->dependentCards = otherPlayer.dependentCards;
    this->attackCards = otherPlayer.attackCards;
    return *this;
}

#endif // PLAYER_H
