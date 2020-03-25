#include "Deck.h"

template<class T>
Deck<T>::Deck() : dealthIdx(0)
{
    srand((unsigned)time(NULL));
}

template<class T>
void Deck<T>::setCards(std::vector<T> cards){
    m_cards = cards;
}

template<class T>
void Deck<T>::shuffle(){
    for(int i = 0; i < m_cards.size() - 1; i++){
        int idx = (rand() % (m_cards.size() - 1 - i)) + i;
        T c = m_cards[idx];
        m_cards[idx] = m_cards[i];
        m_cards[i] = c;
    }

}

template<class T>
T Deck<T>::dealCard(){
    if(dealthIdx >= m_cards.size()){
        return T(-1,Suit::Invalid);
    }
    m_cards[dealthIdx].setUnavailable();
    return m_cards[dealthIdx++];
}

template<class T>
std::vector<T> Deck<T>::dealHand(int numCards){
    std::vector<T> res;
    while(numCards > 0){
        T c = dealCard();
        if(c.isValid())
            res.push_back(c);
        numCards--;
    }
    return res;
}

template<class T>
void Deck<T>::print(){
    for(int i = 0; i < (int) m_cards.size(); i++){
        m_cards[i].print();
    }
}
