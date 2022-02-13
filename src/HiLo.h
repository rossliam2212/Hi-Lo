//
// Created by Liam Ross on 10/02/2022.
//

#ifndef HI_LO_HILO_H
#define HI_LO_HILO_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
#include "Card.h"
#include "HistoryLogger.h"

#define underline "\033[4m"
#define removeUnderline "\033[0m"

class HiLo {
private:
    std::string name;
    double balance;
    double currentBet;
    int currentBetOption;
    double totalWin;

    int betNumber{};
    HistoryLogger gameLog;

    Card currentCard;
    std::vector<Card> previousCards;

    bool gameRunning;
    bool newGame;

    std::string hiRange{};
    std::string loRange{};
    std::string hiMultiplier{};
    std::string loMultiplier{};
    double hiWinMultiplier{};
    double loWinMultiplier{};

    const double colorWinMultiplier{2}; // Red/Black
    const double numbersWinMultiplier{1.5}; // 2-10
    const double facesWinMultiplier{3}; // J,Q,K,A
    const double kingAceWinMultiplier{6}; // K,A
    const double aceWinMultiplier{12}; // A
    const double jokerWinMultiplier{24}; // Joker

    int redCards{};
    int blackCards{};
    int twoCards{};
    int threeCards{};
    int fourCards{};
    int fiveCards{};
    int sixCards{};
    int sevenCards{};
    int eightCards{};
    int nineCards{};
    int tenCards{};
    int jackCards{};
    int queenCards{};
    int kingCards{};
    int aceCards{};
    int jokerCards{};


public:
    HiLo(std::string name, double balance);
    void startGame();
    bool addBalance(double amount);

private:
    void getBetOption();
    void getPlayerBet();
    bool validateBetAmount(double bet) const;
    bool validateBetOption(int option) const;
    void checkPlayerBet();
    void updateBalance(double amount);
    void setNextCard();

    void askDepositBalance();

    void calculateHiLoRangeAndMultipliers();
    std::string calculatePreviousCardPercentages(int cardAmount);

    void printResult();
    void printWelcome() const;
    void printInstructions() const;
    void printBetOptions();
    void printExtraOptions();
    void printPreviousCards() const;
    void printPreviousCardsTable();

    void printGoodBye();
};


#endif //HI_LO_HILO_H
