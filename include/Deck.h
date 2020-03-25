#ifndef DECK_H
#define DECK_H
#include "Suit.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

template<class T>
class Deck
{
    public:
        Deck();

        void setCards(std::vector<T> cards);
        void shuffle();
        T dealCard();
        std::vector<T> dealHand(int numCards);
        void print();
    protected:

    private:
        std::vector<T> m_cards;
        int dealthIdx;
};

#endif // DECK_H
