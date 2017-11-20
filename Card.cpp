#include "Card.h"

#include <iostream>
#include <string>

Card::Card(Face face, Suit suit) : face{face}, suit{suit} { }

Face Card::getFace() const {
    return face;
}

Suit Card::getSuit() const {
    return suit;
}

std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}

const std::vector<std::string> Card::faces { 
    "deuce", 
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "jack",
    "queen",
    "king",
    "ace"
};

const std::vector<std::string> Card::suits {
    "clubs",
    "diamonds",
    "hearts",
    "spades"
};
