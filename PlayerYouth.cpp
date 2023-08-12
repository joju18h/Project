#include "PlayerYouth.h"

YouthPlayer::YouthPlayer() : Player("Noah"), age(4)
{
}

YouthPlayer::YouthPlayer(int age) : Player("Noah"), age(age)
{
    if (age < 4)
        this->age = 4;
    else if (age > 18)
        this->age = 19;
}

YouthPlayer::YouthPlayer(const YouthPlayer& player) : Player(player), age(player.age), attack_cards(player.attack_cards)
{
}

void YouthPlayer::set_age(int age)
{
    if (age < 4)
        this->age = 4;
    else if (age > 18)
        this->age = 19;
    else
        this->age = age;
}

int YouthPlayer::get_age() const
{
    return age;
}

void YouthPlayer::add_attack_card(double card)
{
    attack_cards.push_back(card);
}

void YouthPlayer::add_attack_cards(const std::vector<double>& cards)
{
    attack_cards.insert(attack_cards.end(), cards.begin(), cards.end());
}

double YouthPlayer::sum_attack_cards() const
{
    double sum = 0.0;
    for (double card : attack_cards)
    {
        sum += card;
    }
    return sum;
}

double YouthPlayer::sum_all_cards() const
{
    return sum_attack_cards() - sumDependentCards();
}

YouthPlayer::~YouthPlayer()
{
}
