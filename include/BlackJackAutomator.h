#ifndef BLACKJACKAUTOMATOR_H
#define BLACKJACKAUTOMATOR_H
#include "Deck.h"
#include "BlackJackCard.h"
#include "BlackJackHand.h"
#include "../src/Deck.cpp"
#include "../src/Hand.cpp"
#include "../src/BlackJackHand.cpp"
#include <vector>

class BlackJackAutomator
{
    public:
        BlackJackAutomator(int numPlayers);
        void initDeck();
        void printHandsAndScores();
        bool dealInit();
        std::vector<int> getBlackJacks();
        bool playHand(int i);
        bool playHand(BlackJackHand<BlackJackCard>& h);
        bool playAllHands();
        std::vector<int> getWinners();

    protected:

    private:
        Deck<BlackJackCard> m_deck;
        int const HIT_UNTIL = 16;
        std::vector<BlackJackHand<BlackJackCard>> m_hands;
};

#endif // BLACKJACKAUTOMATOR_H
