#ifndef ABSTRACTCARDGAME_H
#define ABSTRACTCARDGAME_H

#include "Deck.h"
#include "Card.h"
#include "Hand.h"
#include "SupportedGameTypes.h"
#include <QString>
#include "DrawingWidget.h"


enum State {
    STARTING = 0,                   //alguse setup - kaartipaki tekitamine jne
    WAITING_FOR_PLAYER = 1,         //ootab mängija valikut
    PROCESSING_PLAYER_ACTION = 2,   //eemaldab-lisab mängijale kaarte
    WAITING_FOR_DEALER = 3,         //diiler mõtleb - las kestab natuke..
    PROCESSING_DEALER_ACTION = 4,   //lisab diilerile kaarti
    FINISHING = 5,                  //mõtleb välja võitja, lisab punkte, jmt
    FINISHED = 6                   //mäng läbi
};

class AbstractCardGame {

    protected:
        AbstractCardGame(SupportedGameTypes sgt,
                         DeckSize deckSize,
                         DrawingWidget* in_widget);

        DrawingWidget* widget;



    public:

        State state;
        SupportedGameTypes type;
        Deck* deck;
        Hand* playerHand;
        Hand* dealerHand;

        void pickUpCard(Hand* hand);  //deck top card > hand
        State getState();
        SupportedGameTypes getType();
};

#endif
