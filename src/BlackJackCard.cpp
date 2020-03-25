#include "BlackJackCard.h"

BlackJackCard::BlackJackCard(int value, Suit s) : Card(value, s)
{
}

int BlackJackCard::isAce(){
    return Card::m_value == 1;
}

int BlackJackCard::isFace(){
    return Card::m_value >= 11 && Card::m_value <= 13;
}

int BlackJackCard::maxValue(){
    if(isAce()){
        return 11;
    }else{
        return value();
    }
}

int BlackJackCard::minValue(){
    if(isAce()){
        return 1;
    }else{
        return value();
    }
}
