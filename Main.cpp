#include <iomanip>
#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"

// Perhaps this is too abstract?
// This returns true if there are m sets of cards in the hand of length n
// satisfying the property that all of their elements are of the same face
// For three of a kind, n = 3, m = 1
// For two pairs, n = 2, m = 2 etc,
bool hasNOfMKinds(std::vector<Card> hand, int n, int m) {
    int numberOverN{0};
    std::vector<int> kindCounts{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // Count how many cards there are of each face
    for (int i{0}; i < hand.size(); i += 1) {
	Face thisFace{hand[i].getFace()};
	kindCounts[static_cast<int>(thisFace)] += 1;
    }
    // Count the number of faces for which there are more than n cards.
    for (int i{0}; i < kindCounts.size(); i += 1) {
	if (kindCounts[i] >= n) {
	    numberOverN += 1;
	}
    }
    return numberOverN >= m;
}

bool isFlush(std::vector<Card> hand) {
    bool result{true};
    Suit suit{hand[0].getSuit()};
    for (int i{1}; i < hand.size(); i += 1) {
	if (hand[i].getSuit() != suit) {
	    result = false;
	}
    }
    return result;
}

bool isStraight(std::vector<Card> hand) {
    bool result{true};
    Face face{hand[0].getFace()};
    int firstFaceValue{static_cast<int>(face)};
    for (int i{1}; i < hand.size(); i += 1) {
	Face thisFace{hand[i].getFace()};
	int thisFaceValue{static_cast<int>(thisFace)};
        if (firstFaceValue + i != thisFaceValue) {
	    return false;
        }
    }
    return result;
}

void evaluateHand(std::vector<Card> hand) {
    std::cout << "This hand looks like: ";
    for (int i{0}; i < hand.size(); i += 1) {
	std::cout << hand[i].toString();
	if (i < hand.size() - 1) { // not the last card?
	    std::cout << ", ";
	}
    }
    std::cout << std::endl;
    std::cout << "  2 of a kind? " << std::boolalpha << hasNOfMKinds(hand, 2, 1) 
	<< std::endl;
    std::cout << "  2 pairs? " << std::boolalpha << hasNOfMKinds(hand, 2, 2)
	<< std::endl;
    std::cout << "  3 of a kind? " << std::boolalpha << hasNOfMKinds(hand, 3, 1)
	<< std::endl;
    std::cout << "  4 of a kind? " << std::boolalpha << hasNOfMKinds(hand, 4, 1)
	<< std::endl;
    std::cout << "  Flush? " << std::boolalpha << isFlush(hand)
	<< std::endl;
    std::cout << "  Straight? " << std::boolalpha << isStraight(hand)
	<< std::endl;
}

void _9_23() {
    DeckOfCards d{};
    std::cout << "Shuffling deck:" << std::endl;
    d.shuffle();
    for (int i{0}; d.moreCards(); i += 1) { 
	Card curr{d.dealCard()};
 	std::cout << std::left << std::setw(18) << curr.toString();
	if (i % 4 == 3) {
	    std::cout << std::endl;
	}
    }
    std::cout << "Reached end of deck." << std::endl;
}

void _9_24() {
    DeckOfCards d2{};
    d2.shuffle();
    std::vector<Card> hand{};
    for (int i{0}; i < 5; i += 1) {
	Card c{d2.dealCard()};
	hand.push_back(c);
    }
    std::cout << std::endl;
    evaluateHand(hand);

    std::vector<Card> checkStraight{};
    checkStraight.push_back(Card{SIX, SPADES});
    checkStraight.push_back(Card{SEVEN, SPADES});
    checkStraight.push_back(Card{EIGHT, SPADES});
    checkStraight.push_back(Card{NINE, SPADES});
    checkStraight.push_back(Card{TEN, HEARTS});
    evaluateHand(checkStraight);
}

int rate(std::vector<Card> hand) {
    int rating{0};
    if (hasNOfMKinds(hand, 2, 1)) {
        rating = 1;
    }
    if (hasNOfMKinds(hand, 2, 2)) {
        rating = 2;
    }
    if (hasNOfMKinds(hand, 3, 1)) {
        rating = 3;
    }
    if (hasNOfMKinds(hand, 4, 1)) {
        rating = 4;
    }
    if (isFlush(hand)) {
	rating = 5;
    }
    if (isStraight(hand)) {
        rating = 6;
    }
    return rating;
}

void _9_25() {
    DeckOfCards d3{};
    d3.shuffle();
    std::vector<Card> hand1{d3.dealHand()};
    std::vector<Card> hand2{d3.dealHand()};
    evaluateHand(hand1);
    evaluateHand(hand2);
    if (rate(hand1) > rate(hand2)) {
	std::cout << "Hand 1 is better." << std::endl;
    } else if (rate(hand2) > rate(hand1)) {
	std::cout << "Hand 2 is better." << std::endl;
    } else {
	std::cout << "They're even." << std::endl;
    }
}


int main() {
    _9_25();
    return 0; 
}
