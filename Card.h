#ifndef CARD_H
#define CARD_H

//seda annab ka paremini..
enum Rank {
    Two = 0,
    Three = 1,
    Four = 2,
    Five = 3,
    Six = 4,
    Seven = 5,
    Eight = 6,
    Nine = 7,
    Ten = 8,
    Jack = 9,
    Queen = 10,
    King = 11,
    Ace = 12
};

enum Suit {
    Diamonds = 0,
    Clubs = 1,
    Hearts = 2,
    Spades = 3
};



class Card {

public:

    Card(Rank in_rank, Suit in_suit);

    Rank rank;
    Suit suit;


    //~Card();   --- TODO    

};

#endif 






