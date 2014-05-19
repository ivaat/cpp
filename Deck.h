#ifndef DECK_H
#define DECK_H

#include "Card.h"

using namespace std;

enum DeckSize {
	Small, Large
};

//arvatavasti vaja Card includeda, et enumid kätte saada

class Deck {

    private:
        static const Suit SUITLAST = Spades;
        static const Suit SUITFIRST = Clubs;

        static const Rank RANKFIRST = Two;
        static const Rank RANKLAST = Ace;

    public:

        //Deck(DeckSize size);
       // void init(); //paneb paki algseisu
        //void shuffle(); //automaatselt kutsutakse välja konstruktoris ka..

};

#endif 







