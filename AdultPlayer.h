#ifndef ADULTPLAYER_H
#define ADULTPLAYER_H

#include "Player.h"


//Range constants for generating attack cards
#define ATTACKMIN 1
#define ATTACKMAX 15

template <typename T>
class AdultPlayer : public Player<T>
{   
    public:
        //hardcoded to kenneth
        AdultPlayer<T>(const std::string player = "Kenneth") : Player<T>(player){};

       // Player<T> operator=(const Player<T>& otherPlayer);
        void addAttackCard();
        void addAttackCard(int);

        ~AdultPlayer(){};
};
/*
template <typename T>
Player<T> AdultPlayer<T>::operator=(const Player<T> &otherPlayer)
{
    this->name = otherPlayer.name;
    this->cash = otherPlayer.cash;
    this->attackCards = otherPlayer.attackCards;
    this->dependentCards = otherPlayer.dependentCards;

    return *this;
}
*/
template <typename T>
void AdultPlayer<T>::addAttackCard(int numCards)
{
    this->attackCards.clear();
    srand(time(NULL));
    for (int i = 0; i < numCards; i++)
    {
        this->attackCards.push_back((T)(((double)rand() / RAND_MAX) * ATTACKMIN + ATTACKMAX));
    }
}

template <typename T>
void AdultPlayer<T>::addAttackCard()
{
    srand(time(NULL));
    this->attackCards.push_back((T)(((double)rand() / RAND_MAX) * ATTACKMIN + ATTACKMAX));
}



#endif // ADULTPLAYER_H
