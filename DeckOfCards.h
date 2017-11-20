#ifndef DeckOfCards_H
#define DeckOfCards_H

#include "Card.h"

#include <vector>

class DeckOfCards {
public:
    explicit DeckOfCards();
    Card dealCard();
    std::vector<Card> dealHand();
    void shuffle();
    bool moreCards() const;
private:
    std::vector<Card> deck;
    int index{0};
};

#endif
