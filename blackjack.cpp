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

void Blackjack::hit()
{
    playerHand.push_back(deck.draw());
}

size_t Blackjack::totalPlayerHand(const Blackjack& bj) const
{
    return bj.totalHand(playerHand);
}

size_t Blackjack::cardToValue(const Card& card) const
{
    if(card.cardValue == "J") return 10;
    if(card.cardValue == "Q") return 10;
    if(card.cardValue == "K") return 10;
    if(card.cardValue == "A") return 11;
    return stoi(card.cardValue);
}

size_t Blackjack::totalHand(const std::vector<Card>& hand) const
{
    size_t sum{0};
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
