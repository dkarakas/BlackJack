#ifndef BLACKJACKHAND_H
#define BLACKJACKHAND_H
#include "BlackJackCard.h"
#include "Hand.h"
#include<bits/stdc++.h>
#include <vector>

template<class T>
class BlackJackHand : public Hand<T>
{
    public:
        BlackJackHand();
        bool is21();
        bool isBlackJack();
        bool isBusted();
        int score();

    protected:

    private:
        void addCardToScoreList(T card, std::vector<int>& scores);
        std::vector<int> possibleScores();
};

#endif // BLACKJACKHAND_H
