#include "AbstractCardContainer.h"
#include <functional>
#include <algorithm>

using namespace std;

//virtuaalne
void AbstractCardContainer::addCard(Card* card) {
    cards.push_back(card);
}

void AbstractCardContainer::removeCardsAt(vector<unsigned short> indexes) {

    if (indexes.size() == 0) return;

    sort(indexes.begin(), indexes.end(), greater<unsigned short>());

    if (indexes[0] >= size()) return; //TODO - või peaks errori viskama?

    //TODO - pane seda alumist meetodit kasutama
    unsigned short i;
    for (i = 0; i < indexes.size(); i++) {
        delete cards.at(indexes[i]);
        cards.erase(cards.begin() + indexes[i]); //TODO - testi et ikka õige asja deleteb
    }
}

void AbstractCardContainer::removeSingleCardAt(unsigned short index) {
    if (index >= cards.size()) return;
    cards.erase(cards.begin() + index);
}

unsigned short AbstractCardContainer::size() {
    return cards.size();
}

Card* AbstractCardContainer::at(unsigned short index) {
    if (size() <= index) return 0; //mõelda veel kas see on hea lahendus
    else return cards.at(index);
}

void AbstractCardContainer::reset() {
    cards.clear();
    //TODO - decki puhul tuleb see subclassida ja lisada kaartide setup
}
