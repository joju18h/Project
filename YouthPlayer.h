#ifndef YOUTHPLAYER_H
#define YOUTHPLAYER_H

#include "Player.h"
//#include "AdultPlayer.h"

//Range constants for generating attack cards
#define ATTACKMIN 0

template <typename T>
class YouthPlayer : public Player<T>
{
    int age;
    int attackMax;
    std::vector<T> attackCards;

public:

   YouthPlayer<T>(const std::string player, int age) : Player<T>(player) {
        if (age < 4) {
            this->age = 4;
        }

        else if (age > 18) {
            this->age = 19;
        }

        else this->age = age;

        attackMax= this->age / 2;
    }

    Player<T>& operator=(const Player<T>& otherPlayer);
    void addAttackCard();
    void addAttackCard(int);

    T sumAttackCards() const;
    T sumAllCards() const;

    bool operator==(const Player<T>& p2);
    bool operator>(const Player<T>& p2);
    bool operator<(const Player<T>& p2);
    void operator<<(double amt);
    void operator>>(double amt);

    ~YouthPlayer() {};
};


template <typename T>
Player<T>& YouthPlayer<T>::operator=(const Player<T>& otherPlayer)
{
    this->name = otherPlayer.getName();
    this->cash = otherPlayer.getCash();
    return *this;
}

template <typename T>
void YouthPlayer<T>::addAttackCard(int numCards)
{
    this->attackCards.clear();
    srand(time(0));
    for (int i = 0; i < numCards; i++)
    {
        this->attackCards.push_back((T) ((rand() / (T)RAND_MAX) + (rand() % attackMax)));
    }
}

template <typename T>
void YouthPlayer<T>::addAttackCard()
{
    srand(time(0));
    this->attackCards.push_back((T) ((rand()/(T)RAND_MAX) + (rand() % attackMax)));
}

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
#endif
