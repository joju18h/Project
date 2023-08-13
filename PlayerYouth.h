#ifndef YOUTHPLAYER_H
#define YOUTHPLAYER_H

#include "Player.h"


//Range constants for generating attack cards
#define ATTACKMIN 0

template <typename T>
class YouthPlayer : public Player<T>
{
    int age;
    float attackMax;

public:
    //hardcoded to kenneth

    YouthPlayer<T>(const std::string player, int age) : Player<T>(player) {
        if (age < 4) {
            this->age = 4;
        }

        else if (age > 18) {
            this->age = 19;
        }

        else this->age = age;

        attackMax= age / 2;
    }

    Player<T> operator=(const Player<T>& otherPlayer);
    void addAttackCard();
    void addAttackCard(int);

    ~YouthPlayer() {};
};

template <typename T>
Player<T> YouthPlayer<T>::operator=(const Player<T>& otherPlayer)
{
    this->name = otherPlayer.name;
    this->cash = otherPlayer.cash;
    this->attackCards = otherPlayer.attackCards;
    this->dependentCards = otherPlayer.dependentCards;

    return *this;
}

template <typename T>
void YouthPlayer<T>::addAttackCard(int numCards)
{
    this->attackCards.clear();
    srand(time(NULL));
    for (int i = 0; i < numCards; i++)
    {
        this->attackCards.push_back((T)(((double)rand() / RAND_MAX) * ATTACKMIN + attackMax));
    }
}

template <typename T>
void YouthPlayer<T>::addAttackCard()
{
    srand(time(NULL));
    this->attackCards.push_back((T)(((double)rand() / RAND_MAX) * ATTACKMIN + attackMax));
}



#endif
