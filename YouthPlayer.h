#ifndef YOUTHPLAYER_H
#define YOUTHPLAYER_H

#include "Player.h"

//Range constants for generating attack cards
#define ATTACKMIN 0

template <typename T>
class YouthPlayer : public Player<T>
{
    int age;
    T attackMax;
    std::vector<T> attackCards;

public:
    //constructor
    YouthPlayer(const std::string player, int age);

    //overriding and overloading functions from base class
    void addAttackCard();
    void addAttackCard(int);
    T sumAttackCards() const;
    T sumAllCards() const;
    YouthPlayer<T>& operator=(const YouthPlayer& otherPlayer);
    bool operator==(const Player<T>& p2);
    bool operator>(const Player<T>& p2);
    bool operator<(const Player<T>& p2);
    void operator<<(double amt);
    void operator>>(double amt);

    ~YouthPlayer() {};
};

//constructor definition 
//passes player name to Player base class
template <typename T>
YouthPlayer<T>::YouthPlayer(const std::string player, int age) : Player<T>(player) {
    if (age < 4) {
        this->age = 4;
        std::cout << "Age has been set to the minimum age of 4.\n";
    }

    else if (age > 18) {
        this->age = 19;
        std::cout << "Age has been set to the maximum age of 19.\n";
    }

    else this->age = age;

    //set attack max to half the player's age
    attackMax = this->age / 2;
}

//adding attack cards functions
template <typename T>
void YouthPlayer<T>::addAttackCard(int numCards)
{
    this->attackCards.clear();
    srand(time(0));
    for (int i = 0; i < numCards; i++) {
        if (std::is_integral<T>::value) {
            //generates a random integer value between 
            //1 to attackMax (inclusive)
            this->attackCards.push_back(rand() % (int)attackMax+1);
        }
        else {
            //generates a random floating point number
            //between 0 and attackMax (inclusive)
            this->attackCards.push_back(rand() / (double)RAND_MAX * attackMax);
        }
    }
}

template <typename T>
void YouthPlayer<T>::addAttackCard()
{
    srand(time(0));
    if (std::is_integral<T>::value) {
        this->attackCards.push_back(rand() % (int)attackMax+1);
    }
    else {
        this->attackCards.push_back((rand()) / (double)RAND_MAX * attackMax);
    }
}

//summing cards functions
template <typename T>
T YouthPlayer<T>::sumAttackCards() const
{
    T sum = 0;
    for (T card : this->attackCards) {
        sum += (T)card;
    }
    return sum;
};

template <typename T>
T YouthPlayer<T>::sumAllCards() const
{
    return ((T)(this->sumAttackCards() - this->Player<T>::sumDependentCards()));
};

template <typename T>
bool YouthPlayer<T>::operator==(const Player<T>& p2)
{
    return (this->sumAllCards() == p2.sumAllCards());
};

//overridden comparison operators
template <typename T>
bool YouthPlayer<T>::operator>(const Player<T>& p2)
{
    return (this->sumAllCards() > p2.sumAllCards());
};

template <typename T>
bool YouthPlayer<T>::operator<(const Player<T>& p2)
{
    return (this->sumAllCards() < p2.sumAllCards());
};

template <typename T>
void YouthPlayer<T>::operator<<(double amt)
{
    this->Player<T>::addCash(amt);
};

template <typename T>
void YouthPlayer<T>::operator>>(double amt)
{
    this->Player<T>::addCash(-amt);
};

//overloaded operator function
template <typename T>
YouthPlayer<T>& YouthPlayer<T>::operator=(const YouthPlayer& otherPlayer)
{
    *this = otherPlayer;
}

#endif
