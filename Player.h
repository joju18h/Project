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
        std::vector<T> attackCards;
        std::vector<int> dependentCards;

    public:
        Player(); //default constructor
        Player(const std::string player); //hardcoded names to be passed

        //virtual functions
        virtual Player<T> operator=(const Player<T> &otherPlayer) { return *this;};
        virtual void addAttackCard(){};
        virtual void addAttackCard(int){};

        // BaseClass Functions
        void setName(const std::string);
        std::string getName() const;
        void addDependentCard(int numCards);
        void addDependentCard();
        int sumDependentCards() const;
        T sumAttackCards() const;
        double getCash() const;
        void addCash(double);
        bool operator==(const Player &p2);
        bool operator>(const Player &p2);
        bool operator<(const Player &p2);
        void operator<<(double amt);
        void operator>>(double amt);
        T sumAllCards() const;

        virtual ~Player(){};
};

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
void Player<T>::addDependentCard(int numCards)
{
    //generate random number with srand based on time
    this->dependentCards.clear();
    srand(time(0));
    for(int i = 0; i < numCards; i++){
        this->dependentCards.push_back(rand() % DEPMAX) + DEPMIN);
    }
};

template <typename T>
void Player<T>::addDependentCard()
{
    srand(time(0));
    this->dependentCards.push_back(rand() % DEPMAX) + DEPMIN);
};

template <typename T>
int Player<T>::sumDependentCards() const
{
    int sum = 0;
    for (int card : this->dependent_cards) {
        sum += card;
    }
    return sum;
};

template <typename T>
T Player<T>::sumAttackCards() const
{
    T sum = 0;
    for (T card : this->attackCards) {
        sum += (T)card;
    }
    return sum;
};

template <typename T>
double Player<T>::getCash() const
{
    return this->cash;
};

template <typename T>
void Player<T>::addCash(double amt)
{
    this->cash += amt;
};

template <typename T>
bool Player<T>::operator==(const Player &p2)
{
    return (this->sumAllCards() == p2.sumAllCards());
};

template <typename T>
bool Player<T>::operator>(const Player &p2)
{
    return (this->sumAllCards() > p2.sumAllCards());
};

template <typename T>
bool Player<T>::operator<(const Player &p2)
{
    return (this->sumAllCards() < p2.sumAllCards());
};

template <typename T>
void Player<T>::operator<<(double amt)
{
    addCash(amt);
};

template <typename T>
void Player<T>::operator>>(double amt)
{
    addCash(-amt);
};

template <typename T>
T Player<T>::sumAllCards() const
{
    return ((T)(this->sumAttackCards() - this->sumDependentCards()));
};

#endif // PLAYER_H