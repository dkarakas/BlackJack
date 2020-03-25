#include "Question.h"

Question::Question()
{
    //ctor
}

int main()
{
//    BlackJackAutomator au(5);
//    au.initDeck();
//    au.dealInit();
//    au.printHandsAndScores();
//    std::cout << "Playing Cards" << std::endl;
//    au.playAllHands();
//    au.printHandsAndScores();
//    std::cout << "Finished playing cards" << std::endl;
//    std::vector<int> winners = au.getWinners();
//    for(int i = 0; i < winners.size();i++){
//        std::cout << i << " ";
//    }
    int numPlayers = 6;
    BlackJackAutomator au(numPlayers);
    au.initDeck();
    bool suc = au.dealInit();
    if(!suc){
        std::cout << "Failed dealing cards" << std::endl;
        return 1;
    }
    std::cout << "-- Initial Cards --" << std::endl;
    au.printHandsAndScores();
    std::vector<int> getBlackJack = au.getBlackJacks();
    std::cout << "Blackjacks: " << std::endl;
    for(int i = 0; i < getBlackJack.size(); i++){
        std::cout << getBlackJack[i] << " ";
    }
    std::cout << std::endl;
    suc = au.playAllHands();
    if(!suc){
        std::cout << "Playing all hands error" << std::endl;
    }
    std::cout << "-- Complete Game --" << std::endl;
    au.printHandsAndScores();
    std::vector<int> winners = au.getWinners();
    std::cout << "Winners: " << std::endl;
    for(int i = 0; i < winners.size(); i++){
        std::cout << winners[i] << " ";
    }
    std::cout << std::endl;

    std::string test;
    std::cin >> test;
    return 0;
}
