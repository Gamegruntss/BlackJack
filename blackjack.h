#include "deck.h"

#ifndef BLACKJACK_H
#define BLACKJACK_H

class Blackjack
{

public:
Blackjack(size_t, size_t);
friend std::ostream& operator<<(std::ostream& out, const Blackjack& bj);

void hit();
size_t totalPlayerHand(const Blackjack&) const;
size_t totalDealerHand(const Blackjack&) const;


private:
Deck deck;
size_t totalHand(const std::vector<Card>&) const;
size_t cardToValue(const Card&) const;
std::vector<Card> playerHand;
std::vector<Card> dealerHand;

};

#endif /* BLACKJACK_H */
