#include "AbstractCardGame.h"
#include <QDebug>

using namespace std;

AbstractCardGame::AbstractCardGame(SupportedGameTypes sgt,
                                   DeckSize deckSize,
                                   DrawingWidget* in_widget) {
    widget = in_widget;
    type = sgt;
    deck = new Deck(deckSize); //TODO - vaata et pärast hävitatud ka saaks!!!
    //deck = new Deck(deckSize);
    playerHand = new Hand();
    dealerHand = new Hand();
}

void AbstractCardGame::pickUpCard(Hand* hand) {
    unsigned short index = 0;
    qDebug() << "Picking up card:";
    qDebug() << deck->at(index)->rank;
    qDebug() << deck->at(index)->suit;
    Card* card = deck->at(index);
    qDebug() << "Card after being referenced:";
    qDebug() << card->rank;
    qDebug() << card->suit;
    deck->removeSingleCardAt(index);
    qDebug() << "Card after it has been deleted from the deck:";
    qDebug() << card->rank;
    qDebug() << card->suit;
    hand->addCard(card);
}

State AbstractCardGame::getState() {
    return state;
}
