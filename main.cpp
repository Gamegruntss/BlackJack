#include <iostream>
#include "deck.h"
#include "blackjack.h"

#define SETUP Blackjack bj(3, 1)

void playGame();
void stateWinner(size_t, size_t);

int main(int argc, char const *argv[])
{
    std::string resp;
    while(resp.compare("STOP") != 0)
    {
        playGame();
        std::cout << std::endl << std::endl << std::endl << std::endl;
    }
    return 0;
}

void playGame()
{
    SETUP;
    std::string response;
    
    while(bj.totalPlayerHand() < 22 && response.compare("stand") != 0)
    {
        std::cout << bj << std::endl;
        std::cout << "What action would you like to take?" << std::endl;
        std::cin >> response;
        std::cout << std::endl;
        if(response.compare("hit") == 0) bj.hit();
    }

    if(bj.totalPlayerHand() > 21)
    {
        stateWinner(bj.totalPlayerHand(), bj.totalDealerHand());
        return;
    }

    while(bj.totalDealerHand() < 17)
        bj.dealerHit();
    
    std::cout << "Dealer hand: ";
    for(const Card& i: bj.getDealerHand())
        std::cout << i << ", ";
    std::cout << std::endl;

    stateWinner(bj.totalPlayerHand(), bj. totalDealerHand());
}

void stateWinner(size_t player, size_t house)
{
    std::cout << std::endl << std::endl;
    std::cout << "----------------------" << std::endl;

    if(player > 21 || (player < house && house < 22)) std::cout << "The house wins." << std::endl;
    else if(house > 21 || player > house) std::cout << "You win!" << std::endl;
    else std::cout << "Push." << std::endl;

    std::cout << "----------------------" << std::endl;
}
