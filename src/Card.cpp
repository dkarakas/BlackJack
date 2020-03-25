#include "Card.h"

Card::Card(int value, Suit s) : m_value(value), m_suit(s), m_available(true){}

bool Card::isAvailable(){
    return m_available;
}
void Card::setAvailable(){
    m_available = true;
}
void Card::setUnavailable(){
    m_available = false;
}

bool Card::isValid(){
    return m_suit != Suit::Invalid;
}

void Card::print(){
    std::vector<std::string> vals{"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    std::cout << vals[m_value - 1] << " ";
    switch(m_suit){
        case Suit::Club:
                std::cout << "C" << std::endl;
                break;
        case Suit::Diamond:
                std::cout << "D" << std::endl;
                break;
        case Suit::Heart:
                std::cout << "H" << std::endl;
                break;
        case Suit::Spades:
                std::cout << "S" << std::endl;
                break;
    }
}
