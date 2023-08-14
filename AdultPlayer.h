//AdultPlayer.h - header file for adult player
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
        //name is hardcoded to kenneth
        AdultPlayer(const std::string player = "Kenneth") : Player<T>(player){};
        void addAttackCard();
        void addAttackCard(int);
        T sumAttackCards() const;
        T sumAllCards() const;
        AdultPlayer<T>& operator=(const AdultPlayer<T>& otherPlayer);
        bool operator==(const Player<T>& p2);
        bool operator>(const Player<T>& p2);
        bool operator<(const Player<T>& p2);
        void operator<<(double amt);
        void operator>>(double amt);

        ~AdultPlayer(){};
};

//overloaded operator function
template <typename T>
AdultPlayer<T>& AdultPlayer<T>::operator=(const AdultPlayer& otherPlayer)
{
    *this = otherPlayer;
}

//adds attacks cards for a player
template <typename T>
void AdultPlayer<T>::addAttackCard(int numCards)
{
    this->attackCards.clear();
    srand(time(0));
    for (int i = 0; i < numCards; i++)
    {
        if (std::is_integral<T>::value) {
            //generates a random integer number between 1 and 15
            this->attackCards.push_back((int)(rand() % ATTACKMAX) + ATTACKMIN);
        }
        else {
            //generates a random number between 0 and 14
            //add ATTACKMIN = 1 to change the value so
            //it falls between 0 to 15
            this->attackCards.push_back((rand() / (double)RAND_MAX * (ATTACKMAX - 1)) + ATTACKMIN);
        }
    }
}

template <typename T>
void AdultPlayer<T>::addAttackCard()
{
    if (std::is_integral<T>::value) {
        this->attackCards.push_back((int)(rand() % ATTACKMAX)+ATTACKMIN);
    }
    else {
        this->attackCards.push_back((rand() / (double)RAND_MAX * (ATTACKMAX - 1)) + ATTACKMIN);
    }
}

//sum cards functions
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

//overridden comparison operator functions 

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

//functions to remove or add cash from a player
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
