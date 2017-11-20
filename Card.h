#ifndef Card_H
#define Card_H

#include <string>
#include <vector>


enum Face {
    DEUCE,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

enum Suit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

class Card {
public:
    explicit Card(Face, Suit);
    Face getFace() const;
    Suit getSuit() const;
    std::string toString() const;
    const static std::vector<std::string> faces;
    const static std::vector<std::string> suits;
private:
    Face face;
    Suit suit;
};

#endif
