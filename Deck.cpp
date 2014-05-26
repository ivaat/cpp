#include "Deck.h"
#include "QDebug"

#include <algorithm>    // std::random_shuffle

Deck::Deck(DeckSize size) {
    //TODO - suuruselt sõltuvalt on kas alguskaart two või six

    Card* tmp;

    for (int r = Two; r <= Ace; r++) {
        for (int s = Diamonds; s <= Spades; s++) {
            //TODO - hävitada ka kaartid pärast
            tmp = new Card((Rank)r, (Suit)s);
            //qDebug() << tmp->suit;
            //qDebug() << tmp->rank;
            AbstractCardContainer::addCard(tmp);
        }
    }

    shuffle();
}


void Deck::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());
}


