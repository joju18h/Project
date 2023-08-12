#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <vector>

class Player
{
    protected:
        std::vector <int> dependent_cards;
        std::string name;
        double cash;


    public:

        Player();
        Player(const std::string &name);
        Player(const Player &player);

        void set_name(const std::string& name);
        std::string get_name() const;
        void addDependentCard(int card);
        void addDependentCard(const std::vector<int>& cards);
        int sumDependentCards() const;
        void add_cash(double cash);
        double get_cash() const;

        bool operator==(const Player& player) const;
        bool operator<(const Player& player) const;
        bool operator>(const Player& player) const;
        friend std::istream& operator>>(std::istream& input, Player& player);
        friend std::ostream &operator<<(std::ostream &output,Player &player);
        Player& operator=(const Player &player);

        virtual ~Player() {};

};

#endif // PLAYER_H