#include "Player.h"

/*
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
*/

Player::Player()
{
    this->name = "";
    this->cash = 1000.00;
};

Player::Player(const std::string &name)
{
    this->name = name;
    this->cash = 1000.00;
};

Player::Player(const Player &player)
{
    this->name = player.name;
    this->cash = player.cash;
    this->dependent_cards = player.dependent_cards;
};

void Player::set_name(const std::string& name)
{
    this->name = name;
};

std::string Player::get_name() const
{
    return this->name;
};

void Player::addDependentCard(int card)
{
    this->dependent_cards.push_back(card);
};

void Player::addDependentCard(const std::vector<int>& cards)
{
    for (int i = 0; i < cards.size(); i++)
    {
        this->dependent_cards.push_back(cards[i]);
    }
};

int Player::sumDependentCards() const {
    int sum = 0;
    for (int card : this->dependent_cards) {
        sum += card;
    }
    return sum;
}

void Player::add_cash(double cash)
{
    this->cash += cash;
};

double Player::get_cash() const
{
    return this->cash;
};

bool Player::operator==(const Player& player) const
{
    return this->sumDependentCards() == player.sumDependentCards();
};

bool Player::operator<(const Player& player) const
{
    return this->sumDependentCards() < player.sumDependentCards();
};

bool Player::operator>(const Player& player) const
{
    return this->sumDependentCards() > player.sumDependentCards();
};

std::istream& operator>>(std::istream& input, Player& player)
{
    double amount;
    input >> amount;
    player.cash -= amount;

    return input;
};

std::ostream &operator<<(std::ostream &output,Player &player)
{   
    double amount;
    output << amount;
    player.cash += amount;

    return output;

};

Player& Player::operator=(const Player &player)
{
    this->name = player.name;
    this->cash = player.cash;
    this->dependent_cards = player.dependent_cards;

    return *this;
};

