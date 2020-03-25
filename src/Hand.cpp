#include "Hand.h"

template<class T>
int Hand<T>::score(){
    int res = 0;
    for(int i = 0; i < m_cards.size(); i++){
        res += m_cards[i].value();
    }
    return res;
}

template<class T>
void Hand<T>::addCard(BlackJackCard c){
    m_cards.push_back(c);
}

template<class T>
void Hand<T>::print(){
    for(int i = 0; i < m_cards.size(); i++){
        m_cards[i].print();
    }
}
