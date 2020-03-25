#ifndef HAND_H
#define HAND_H
#include "BlackJackCard.h"
#include <vector>

template <class T>
class Hand
{
    public:
        Hand(){};
        int score();
        void addCard(BlackJackCard c);
        void print();

    protected:
        std::vector<T> m_cards;

    private:

};

#endif // HAND_H
