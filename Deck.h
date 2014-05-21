#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include "AbstractCardContainer.h"

using namespace std;

enum DeckSize {
	Small, Large
};

//arvatavasti vaja Card includeda, et enumid kätte saada

class Deck : public AbstractCardContainer {

    private:
        static const Suit SUITLAST = Diamonds;
        static const Suit SUITFIRST = Spades;

        static const Rank RANKFIRST = Two;
        static const Rank RANKLAST = Ace;

    public:

        //Deck(DeckSize size);
       // void init(); //paneb paki algseisu
        //void shuffle(); //automaatselt kutsutakse välja konstruktoris ka..

};

#endif 







