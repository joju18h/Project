//Adultplayer.h
#ifndef ADULTPLAYER_H
#define ADULTPLAYER_H

#include "Player.h"

//Range constants for generating attack cards
#define ATTACKMIN 1
#define ATTACKMAX 15

template <typename T>
class AdultPlayer : public Player<T>
{   
    std::vector<T> attackCards;

    public:
        //hardcoded to kenneth
        AdultPlayer<T>(const std::string player = "Kenneth") : Player<T>(player){};

        
        void addAttackCard();
        void addAttackCard(int);

        T sumAttackCards() const;
        T sumAllCards() const;

        Player<T>& operator=(const Player<T>& otherPlayer);
        bool operator==(const Player<T>& p2);
        bool operator>(const Player<T>& p2);
        bool operator<(const Player<T>& p2);
        void operator<<(double amt);
        void operator>>(double amt);

        ~AdultPlayer(){};
};

template <typename T>
Player<T>& AdultPlayer<T>::operator=(const Player<T> &otherPlayer)
{
    this->name = otherPlayer.getName();
    this->cash = otherPlayer.getCash();
    return *this;
}

template <typename T>
void AdultPlayer<T>::addAttackCard(int numCards)
{
    this->attackCards.clear();
    srand(time(0));
    for (int i = 0; i < numCards; i++)
    {
        this->attackCards.push_back((T)((rand() / (T)RAND_MAX) + (rand() % ATTACKMAX)));
    }
}

template <typename T>
void AdultPlayer<T>::addAttackCard()
{
    srand(time(0));
    this->attackCards.push_back((T)((rand() / (T)RAND_MAX) + (rand() % ATTACKMAX)));
}

template <typename T>
T AdultPlayer<T>::sumAttackCards() const
{
    T sum = 0;
    for (T card : this->attackCards) {
        sum += (T)card;
    }
    return sum;
};

template <typename T>
T AdultPlayer<T>::sumAllCards() const
{
    return ((T)(this->sumAttackCards() - this->Player<T>::sumDependentCards()));
};

template <typename T>
bool AdultPlayer<T>::operator==(const Player<T>& p2)
{
    return (this->sumAllCards() == p2.sumAllCards());
};

template <typename T>
bool AdultPlayer<T>::operator>(const Player<T>& p2)
{
    return (this->sumAllCards() > p2.sumAllCards());
};

template <typename T>
bool AdultPlayer<T>::operator<(const Player<T>& p2)
{
    return (this->sumAllCards() < p2.sumAllCards());
};

template <typename T>
void AdultPlayer<T>::operator<<(double amt)
{
    this->Player<T>::addCash(amt);
};

template <typename T>
void AdultPlayer<T>::operator>>(double amt)
{
    this->Player<T>::addCash(-amt);
};
#endif // ADULTPLAYER_H
