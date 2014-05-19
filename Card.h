#ifndef CARD_H
#define CARD_H

//seda annab ka paremini..
enum Rank {
    Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace
};

enum Suit {
    Clubs, Diamonds, Hearts, Spades
};



class Card {

public:

    //Card(Rank rank, Suit suit);

    Rank rank;
    Suit suit;


    //~Card();   --- TODO


};

#endif 






