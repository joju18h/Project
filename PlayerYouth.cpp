#include "PlayerYouth.h"

template<typename T>
YouthPlayer<T>::YouthPlayer() : Player<T>("Noah"), age(4)
{
}

template<typename T>
YouthPlayer<T>::YouthPlayer(int age) : Player<T>("Noah"), age(age)
{
    if (age < 4)
        this->age = 4;
    else if (age > 18)
        this->age = 19;
}

template<typename T>
YouthPlayer<T>::YouthPlayer(const YouthPlayer& player) : Player<T>(player), age(player.age), attack_cards(player.attack_cards)
{
}

template<typename T>
void YouthPlayer<T>::set_age(int age)
{
    if (age < 4)
        this->age = 4;
    else if (age > 18)
        this->age = 19;
    else
        this->age = age;
}

template<typename T>
int YouthPlayer<T>::get_age() const
{
    return age;
}

template<typename T>
void YouthPlayer<T>::add_attack_card(T card)
{
    attack_cards.push_back(card);
}

template<typename T>
void YouthPlayer<T>::add_attack_cards(const std::vector<T>& cards)
{
    attack_cards.insert(attack_cards.end(), cards.begin(), cards.end());
}

template<typename T>
T YouthPlayer<T>::sum_attack_cards() const
{
    T sum = 0;
    for (T card : attack_cards)
    {
        sum += card;
    }
    return sum;
}

template<typename T>
T YouthPlayer<T>::sum_all_cards() const
{
    return sum_attack_cards() - sumDependentCards();
}

template<typename T>
YouthPlayer<T>::~YouthPlayer()
{
}

// Explicit template instantiation for commonly used types
template class YouthPlayer<int>;
template class YouthPlayer<double>;
// Add more instantiations for other types as needed
