#include <iostream>
#include "deck.h"
#include "blackjack.h"

#define SETUP Blackjack bj(3, 3)

int main(int argc, char const *argv[])
{
    SETUP;
    bj.playGame();
    return 0;
}