#include "BlackJackAutomator.h"

BlackJackAutomator::BlackJackAutomator(int numPlayers)
{
    for(int i = 0; i < numPlayers; i++){
        m_hands.push_back(BlackJackHand<BlackJackCard>());
    }
}

bool BlackJackAutomator::dealInit(){
    for(int i = 0; i < m_hands.size(); i++){
        BlackJackCard c1 = m_deck.dealCard();
        BlackJackCard c2 = m_deck.dealCard();
        if(!c1.isValid() && !c2.isValid()){
            return false;
        }
        m_hands[i].addCard(c1);
        m_hands[i].addCard(c2);
    }
    return true;
}

bool BlackJackAutomator::playHand(int i){
    return playHand(m_hands[i]);
}

bool BlackJackAutomator::playHand(BlackJackHand<BlackJackCard>& h){
    while(h.score() < HIT_UNTIL){
        BlackJackCard c = m_deck.dealCard();
        if(!c.isValid()){
            return false;
        }
        h.addCard(c);
    }
    return true;
}

bool BlackJackAutomator::playAllHands(){
    for(int i = 0; i < m_hands.size();i++){
        if(!playHand(i)){
            return false;
        }
    }
    return true;
}

std::vector<int> BlackJackAutomator::getWinners(){
    std::vector<int> res;
    int winningScore = 0;
    for(int i = 0; i < m_hands.size(); i++){
        if(!m_hands[i].isBusted()){
//            std::cout << "Non busted " << std::endl;
            if(m_hands[i].score() > winningScore){
//                std::cout << i << std::endl;
                res.clear();
                res.push_back(i);
                winningScore = m_hands[i].score();
            }else if (m_hands[i].score() == winningScore){
                res.push_back(i);
            }
        }
    }
    return res;
}

std::vector<int> BlackJackAutomator::getBlackJacks(){
    std::vector<int> win;
    for(int i = 0; i < m_hands.size();i++){
        if(m_hands[i].isBlackJack()){
            win.push_back(i);
        }
    }
    return win;
}



void BlackJackAutomator::initDeck(){
    std::vector<Suit> suits{Suit::Club, Suit::Diamond, Suit::Heart, Suit::Spades};
    std::vector<BlackJackCard> cards;
    for(int i = 1; i < 14; i++){
        for(int j = 0; j < (int) suits.size(); j++){
            cards.push_back(BlackJackCard(i,suits[j]));
        }
    }
    m_deck.setCards(cards);
    m_deck.shuffle();
}


void BlackJackAutomator::printHandsAndScores(){
    for(int i = 0; i < m_hands.size(); i++){
        std::cout << "Hand " << i << " (" << m_hands[i].score() << "): " << std::endl;
        m_hands[i].print();
    }
}
