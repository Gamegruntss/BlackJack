#include <iostream>
#include "deck.h"
#include "blackjack.h"

int main(int argc, char const *argv[])
{
    Blackjack bj(3, 1);
    std::cout << bj;
    std::cout << bj.totalPlayerHand(bj);
    return 0;
}
