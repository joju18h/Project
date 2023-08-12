#ifndef YOUTHPLAYER_H
#define YOUTHPLAYER_H

#include "Player.h"
#include <iomanip>

template<typename T>
class YouthPlayer : public Player<T>
{
private:
    int age;
    std::vector<T> attack_cards;

public:
    YouthPlayer();
    YouthPlayer(int age);
    YouthPlayer(const YouthPlayer &player);

    void set_age(int age);
    int get_age() const;

    void add_attack_card(T card);
    void add_attack_cards(const std::vector<T> &cards);
    T sum_attack_cards() const;
    T sum_all_cards() const;

    // Additional requirements for each player
    void addDependentCard(int card);
    void addDependentCard(const std::vector<int> &cards);

    // Override functions
    int sumDependentCards() const override;

    virtual ~YouthPlayer() override;
};

#endif // YOUTHPLAYER_H
