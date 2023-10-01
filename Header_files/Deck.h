#ifndef DECK_H
#define DECK_H

#include "Card.h" // Include the Card class header

class Deck {
public:
    Deck(); // Constructor to initialize the deck with cards
    void shuffle();
    Card sealCard(); 
    Card cards[52]; // An array to store the cards in the deck
    int topCard; // Index of the top card in the deck
    void DrawDeck();
};

#endif  // DECK_H
