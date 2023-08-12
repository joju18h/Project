#ifndef PLAYERYOUTH_H
#define PLAYERYUTH_H


#include "Player.h"

class YouthPlayer : public Player
{
private:
    int age;
    std::vector<double> attack_cards;

public:
    YouthPlayer();
    YouthPlayer(int age);
    YouthPlayer(const YouthPlayer& player);

    void set_age(int age);
    int get_age() const;

    void add_attack_card(double card);
    void add_attack_cards(const std::vector<double>& cards);
    double sum_attack_cards() const;
    double sum_all_cards() const;

    virtual ~YouthPlayer() override;
};

#endif // YOUTHPLAYER_H


