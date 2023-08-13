//PlayerMain.cpp - main program for the card player

#include "CardGame.h"

int main(void) {
    CardGame<int> cGame1(GameMode::LowDefinition);
    cGame1.run();

    CardGame<double> cGame2(GameMode::HighDefinition);
    cGame2.run();

    return 0;
}