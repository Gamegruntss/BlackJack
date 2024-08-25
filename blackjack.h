#include <iostream>
#include <cstdlib>
#include "deck.h"

#ifndef BLACKJACK_H
#define BLACKJACK_H

class Blackjack
{

public:
Blackjack(size_t, size_t, uint32_t);
~Blackjack();
friend std::ostream& operator<<(std::ostream& out, const Blackjack& bj);

void playGame();

private:

Deck deck;
size_t score[2]{0,0};
std::vector<Card> playerHand;
std::vector<Card> dealerHand;
uint32_t playerBalance;
uint32_t currentBet;

void hit();
void dealerHit();

size_t totalPlayerHand() const;
size_t totalDealerHand() const;

int handContains(const std::vector<Card>&, const std::string& cardVal) const;
size_t cardToValue(const Card&) const;
size_t totalHand(const std::vector<Card>&) const;

const std::vector<Card> getPlayerHand() const;
const std::vector<Card> getDealerHand() const;

void playHand();
void stateWinner(size_t, size_t);
void payout(bool);
void deal();
void resetHands();

};

#endif /* BLACKJACK_H */
