#include <cstdlib>
#include <iostream>

#include "DeckOfCards.h"

DeckOfCards::DeckOfCards() : deck{}, index{0} {
    for (int f{0}; f < 13; f += 1) {
	for (int s{0}; s < 4; s += 1) {
	    Card c{static_cast<Face>(f), static_cast<Suit>(s)};
	    deck.push_back(c);
	}
    }
}

Card DeckOfCards::dealCard() {
    Card out{deck[index]};
    index += 1;
    return out;
}

std::vector<Card> DeckOfCards::dealHand() {
    std::vector<Card> hand{};
    for (int i{0}; i < 5; i += 1) {
      hand.push_back(dealCard());
    }
    return hand;
}

void DeckOfCards::shuffle() {
    srand(static_cast<unsigned int>(time(0)));
    for (int i{0}; i < 52; i += 1) {
	int randomIndex{rand() % 52};
	Card thisCard{deck[i]};
	Card otherCard{deck[randomIndex]};
	deck[i] = otherCard;
	deck[randomIndex] = thisCard;
    }
}

bool DeckOfCards::moreCards() const {
    return index < 52;
}
