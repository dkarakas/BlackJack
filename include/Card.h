#ifndef CARD_H
#define CARD_H
#include "Suit.h"
#include <vector>
#include <string>
#include <iostream>

class Card
{
    public:
        Card(int value, Suit s);
        virtual int value() = 0;
        bool isValid();
        bool isAvailable();
        void setUnavailable();
        void setAvailable();
        void print();
    protected:
        bool m_available;
        int m_value;
        Suit m_suit;

    private:

};

#endif // CARD_H
