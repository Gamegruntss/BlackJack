#include <string>
#include <fstream>
#include <vector>
#include <cstddef>
#include <stdexcept>

#ifndef DECK_H
#define DECK_H

struct Card
{
    std::string cardValue;
    std::string suit;

    friend std::ostream& operator<<(std::ostream& out, const Card& c);
};

class Deck
{

public:

//index 0 represents the bottom of the deck
Deck();

const Card& at(const size_t) const;

const Card& draw();
void shuffle();

void combineDecks(const Deck&);

const size_t deckSize();
const size_t currentDeckSize();

private:
std::vector<Card> deck;
size_t top;
std::string suits[4]{"C", "D", "H", "S"};
std::string cardValues[13]{"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

};


#endif /* DECK_H */
