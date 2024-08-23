#include <cstdlib>
#include <time.h>

#include "deck.h"

Deck::Deck()
{
    int i;
    int j;
    std::string cardVal;
    top = 51;

    for(i = 0; i < 4; ++i)
    {
        for(j = 0; j < 13; ++j)
        {
            deck.push_back(Card{cardValues[j], suits[i]});
        }
    }
}

//pos represents cards from the top
const Card& Deck::at(const size_t pos) const
{
    if(pos == 0 || pos > (top + 1)) throw std::out_of_range("The position you entered is not a valid position in the deck.");
    return deck[top - pos + 1];
}

const Card& Deck::draw()
{
    const Card& value{Deck::at(1)};
    --top;

    return value;
}

void Deck::shuffle()
{
    srand(time(NULL));
    
    for(size_t i = top; i > 0; --i)
    {
        size_t random = std::rand() % (i + 1);
        std::swap(deck[i], deck[random]);
    }
}

void Deck::combineDecks(const Deck& deck2)
{
    size_t i;

    for(i = 1; i <= 52; ++i)
        deck.push_back(deck2.at(i));

    top += (i - 1);
}

const size_t Deck::deckSize() { return deck.size(); }

const size_t Deck::currentDeckSize() { return top + 1; }

std::ostream &operator<<(std::ostream& out, const Card& c)
{
    return out << c.suit << ": " << c.cardValue;
}
