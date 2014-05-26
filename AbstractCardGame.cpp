#include "AbstractCardGame.h"

using namespace std;

AbstractCardGame::AbstractCardGame(SupportedGameTypes sgt,
                                   DeckSize deckSize) {
    type = sgt;
    deck = new Deck(deckSize); //TODO - vaata et pärast hävitatud ka saaks!!!
    //deck = new Deck(deckSize);
}

void AbstractCardGame::transferCard(Card* card) {

}

State AbstractCardGame::getState() {
    return state;
}
