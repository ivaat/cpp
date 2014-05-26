#ifndef ABSTRACTCARDGAME_H
#define ABSTRACTCARDGAME_H

#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "SupportedGameTypes.h"
#include <QString>


enum State {
    STARTING,                   //alguse setup - kaartipaki tekitamine jne
    WAITING_FOR_PLAYER,         //ootab mängija valikut
    PROCESSING_PLAYER_ACTION,   //eemaldab-lisab mängijale kaarte
    WAITING_FOR_DEALER,         //diiler mõtleb - las kestab natuke..
    PROCESSING_DEALER_ACTION,   //lisab diilerile kaarti
    FINISHING,                  //mõtleb välja võitja, lisab punkte, jmt
    FINISHED                    //mäng läbi
};

class AbstractCardGame {

    protected:
        AbstractCardGame(SupportedGameTypes sgt, DeckSize deckSize);
        State state;
        SupportedGameTypes type;

    public:

        Deck* deck;
        Hand* playerHand;
        Hand* dealerHand;

        void pickUpCard(Hand* hand);  //deck top card > hand
        State getState();
        SupportedGameTypes getType();
        virtual QString getHandStrength(Hand* hand);
};

#endif
