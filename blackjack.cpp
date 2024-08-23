#include "blackjack.h"

Blackjack::Blackjack(size_t deckCount, size_t shuffles)
{
    size_t i;
    for(i = 0; i < deckCount - 1; ++i)
        deck.combineDecks(Deck());
    for(i = 0; i < shuffles; ++i)
        deck.shuffle();
    deal();
}

Blackjack::~Blackjack()
{
    playerHand.clear();
    dealerHand.clear();
}

std::ostream &operator<<(std::ostream &out, const Blackjack &bj)
{
    out << "Dealer hand: " << bj.dealerHand.at(0) << " X" << std::endl;
    out << "Player hand: ";
    for(size_t i = 0; i < bj.playerHand.size(); ++i)
       out << bj.playerHand.at(i) << ", ";
    out << std::endl;

    return out;
}

void Blackjack::hit() { playerHand.push_back(deck.draw()); }

void Blackjack::dealerHit() { dealerHand.push_back(deck.draw()); }

size_t Blackjack::totalPlayerHand() const{ return totalHand(playerHand); }

size_t Blackjack::totalDealerHand() const{ return totalHand(dealerHand); }

int Blackjack::handContains(const std::vector<Card>& hand, const std::string& cardVal) const
{
    for(size_t i = 0; i < hand.size(); ++i)
        if(hand.at(i).cardValue == cardVal) return i;
    
    return -1;
}

const std::vector<Card> Blackjack::getPlayerHand() const { return playerHand; }

const std::vector<Card> Blackjack::getDealerHand() const { return dealerHand; }

void Blackjack::playGame()
{
    std::string response;
    while(deck.currentDeckSize() > (deck.deckSize() * 0.25))
    {
        playHand();
        std::cout << "Would you like to play another hand? (y/n)" << std::endl;
        std::cin >> response;
        if(response.compare("y") != 0 && response.compare("Y") != 0 ) return;
        std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl
            << std::endl << std::endl << std::endl << std::endl;
        resetHands();
    }
}

void Blackjack::playHand()
{
    std::string response;
    
    while(totalPlayerHand() < 22 && response.compare("stand") != 0)
    {
        std::cout << *(this) << std::endl;
        std::cout << "What action would you like to take?" << std::endl;
        std::cin >> response;
        std::cout << std::endl;
        if(response.compare("hit") == 0) hit();
    }

    if(totalPlayerHand() > 21)
    {
        stateWinner(totalPlayerHand(), totalDealerHand());
        return;
    }

    while(totalDealerHand() < 17)
        dealerHit();
    
    std::cout << "Dealer hand: ";
    for(const Card& i: getDealerHand())
        std::cout << i << ", ";
    std::cout << std::endl;

    stateWinner(totalPlayerHand(), totalDealerHand());
}

size_t Blackjack::cardToValue(const Card& card) const
{
    if(card.cardValue == "J") return 10;
    if(card.cardValue == "Q") return 10;
    if(card.cardValue == "K") return 10;
    return stoi(card.cardValue);
}

size_t Blackjack::totalHand(const std::vector<Card>& hand) const
{
    size_t sum{0};
    int idx{handContains(hand, "A")};
    std::vector<Card> copy{hand};
    int subtotal;

    if(idx != -1)
    {
        copy.erase(copy.begin() + idx);
        subtotal = totalHand(copy);
        if(subtotal > 10) return subtotal + 1;
        else return subtotal + 11;
    } 

    for(int i = 0; i < hand.size(); ++i)
        sum += cardToValue(hand.at(i));

    return sum;
}

bool Blackjack::stateWinner(size_t player, size_t house)
{
    bool winner;
    std::cout << std::endl << std::endl;
    std::cout << "----------------------" << std::endl;

    if(player > 21 || (player < house && house < 22)) 
    {
        std::cout << "The house wins. (" << score[0] << "-" << ++score[1] << ")" << std::endl;
        winner = 0;
    }
    else if(house > 21 || player > house) 
    {
        std::cout << "You win! (" << ++score[0] << "-" << score[1] << ")" << std::endl;
        winner = 1;    
    } else std::cout << "Push." << std::endl;
    
    std::cout << "----------------------" << std::endl;

    return winner;
}

void Blackjack::deal()
{
    playerHand.push_back(deck.draw());
    dealerHand.push_back(deck.draw());
    playerHand.push_back(deck.draw());
    dealerHand.push_back(deck.draw());
}

void Blackjack::resetHands()
{
    playerHand.clear();
    dealerHand.clear();
    deal();
}
