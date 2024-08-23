#include "blackjack.h"

Blackjack::Blackjack(size_t deckCount, size_t shuffles)
{
    for(size_t i = 0; i < shuffles; ++i)
        deck.shuffle();
    playerHand.push_back(deck.draw());
    dealerHand.push_back(deck.draw());
    playerHand.push_back(deck.draw());
    dealerHand.push_back(deck.draw());
}

Blackjack::~Blackjack()
{
    playerHand.clear();
    dealerHand.clear();
}

void Blackjack::hit() { playerHand.push_back(deck.draw()); }
void Blackjack::dealerHit() { dealerHand.push_back(deck.draw()); }
size_t Blackjack::totalPlayerHand() const{ return totalHand(playerHand); }
size_t Blackjack::totalDealerHand() const{ return totalHand(dealerHand); }
const std::vector<Card> Blackjack::getPlayerHand() const { return playerHand; }
const std::vector<Card> Blackjack::getDealerHand() const { return dealerHand; }
int Blackjack::handContains(const std::vector<Card>& hand, const std::string& cardVal) const
{
    for(size_t i = 0; i < hand.size(); ++i)
        if(hand.at(i).cardValue == cardVal) return i;
    
    return -1;
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

std::ostream &operator<<(std::ostream &out, const Blackjack &bj)
{
    out << "Dealer hand: " << bj.dealerHand.at(0) << " X" << std::endl;
    out << "Player hand: ";
    for(size_t i = 0; i < bj.playerHand.size(); ++i)
       out << bj.playerHand.at(i) << ", ";
    out << std::endl;

    return out;
}
