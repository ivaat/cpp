#include "AbstractCardGame.h"

using namespace std;

AbstractCardGame::AbstractCardGame(SupportedGameTypes sgt) {
    type = sgt;
}

void AbstractCardGame::transferCard(Card* card) {

}

State AbstractCardGame::getState() {
    return state;
}
