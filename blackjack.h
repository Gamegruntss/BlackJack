#include "deck.h"

#ifndef BLACKJACK_H
#define BLACKJACK_H

class Blackjack
{

public:
Blackjack(size_t, size_t);
~Blackjack();
friend std::ostream& operator<<(std::ostream& out, const Blackjack& bj);

void hit();
void dealerHit();
size_t totalPlayerHand() const;
size_t totalDealerHand() const;
int handContains(const std::vector<Card>&, const std::string& cardVal) const;
const std::vector<Card> getPlayerHand() const;
const std::vector<Card> getDealerHand() const;


private:
Deck deck;
size_t totalHand(const std::vector<Card>&) const;
size_t cardToValue(const Card&) const;
std::vector<Card> playerHand;
std::vector<Card> dealerHand;

};

#endif /* BLACKJACK_H */
