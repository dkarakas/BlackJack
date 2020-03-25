#ifndef BLACKJACKCARD_H
#define BLACKJACKCARD_H
#include "Card.h"
#include "Suit.h"

class BlackJackCard : public Card
{
    public:
        BlackJackCard(int value, Suit s);

        int value() override {
            if(isAce()){
                return 1;
            }else if(isFace()){
                return 10;
            }else{
                return Card::m_value;
            }
        }
        int maxValue();
        int minValue();
        int isFace();
        int isAce();

    protected:

    private:
};

#endif // BLACKJACKCARD_H
