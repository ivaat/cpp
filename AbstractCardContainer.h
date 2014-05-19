#ifndef ABSTRACTCARDCONTAINER_H
#define ABSTRACTCARDCONTAINER_H

#include <vector>
#include "Card.h"

using namespace std;


//seda extendivad nii deck kui hand
//konstruktorit ei ole - seega objekti luua ei saa
class AbstractCardContainer {

protected:
    vector<Card*> cards; //kaartid

public:
    virtual void addCard(Card* card); //siin default, hand alamklass kirjutab üle
    void removeCardsAt(vector<unsigned short> indexes); //eemaldab kaarti mingitel indeksitel
    unsigned short size(); //tagastab kaartite arvu käes
    Card* at(unsigned short index); //tagastab kaarti mingil indeksil või 0
};

#endif
