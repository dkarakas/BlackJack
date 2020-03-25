#include "BlackJackHand.h"

template<class T>
BlackJackHand<T>::BlackJackHand() : Hand<T>(){}

template<class T>
int BlackJackHand<T>::score(){
    std::vector<int> scores = possibleScores();
    int maxUnder = INT_MIN;
    int minOver = INT_MAX;
    for(int i = 0; i < scores.size(); i++){
        if(scores[i] > 21 && scores[i] < minOver){
            minOver = scores[i];
        }else if(scores[i] <= 21 && scores[i] > maxUnder){
            maxUnder = scores[i];
        }
    }

    return maxUnder == INT_MAX ? minOver : maxUnder;
}

template<class T>
std::vector<int> BlackJackHand<T>::possibleScores(){
    std::vector<int> scores;
    for(int i = 0; i < (int) Hand<T>::m_cards.size(); i++){
        addCardToScoreList(Hand<T>::m_cards[i], scores);
    }
    return scores;
}

template<class T>
void BlackJackHand<T>::addCardToScoreList(T card, std::vector<int>& scores){
    if(scores.size() == 0){
        scores.push_back(0);
    }
    int length =  scores.size();
    for(int i = 0; i < length; i++){
        scores.push_back(scores[i] + card.minValue());
        if(card.minValue() != card.maxValue()){
            scores.push_back(scores[i] + card.maxValue());
        }
    }
}


template<class T>
bool BlackJackHand<T>::isBusted(){
    return score() > 21;
}


template<class T>
bool BlackJackHand<T>::is21(){
    return score() == 21;
}

template<class T>
bool BlackJackHand<T>::isBlackJack(){
    if(Hand<T>::m_cards.size() != 2){
        return false;
    }
    return (Hand<T>::m_cards[0].isAce() && Hand<T>::m_cards[1].isFace()) || (Hand<T>::m_cards[1].isAce() && Hand<T>::m_cards[0].isFace());
}
