//
// Created by Liam Ross on 11/02/2022.
//

#ifndef HI_LO_HISTORYLOGGER_H
#define HI_LO_HISTORYLOGGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <ctime>

#include "Card.h"

class HistoryLogger {
private:
    std::string playerName;
    std::string outputFileName;
    double startingBalance;
public:
    HistoryLogger();
    HistoryLogger(std::string playerName, double balance);
    void fileSetUp();

    void logGameResult(const Card& card, int betNumber, double betAmount, double result, double currentBalance, double multiplier, std::string& betOn);
    void logDeposit(double depositAmount, double balance);

    void setPlayerName(std::string name);
    void setBalance(double balance);
};


#endif //HI_LO_HISTORYLOGGER_H
