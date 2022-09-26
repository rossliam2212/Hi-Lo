//
// Created by Liam Ross on 11/02/2022.
//

#include "HistoryLogger.h"

#include <utility>

HistoryLogger::HistoryLogger() : HistoryLogger("Default", 0.0) { }

HistoryLogger::HistoryLogger(const std::string& playerName, double balance) :
        playerName{playerName},
        outputFileName{"../GameHistory.txt"},
        startingBalance{balance}
{
    fileSetUp();
}

void HistoryLogger::fileSetUp() {
    std::ofstream outputFile{outputFileName};
    if (!outputFile) {
        std::cerr << "Error creating file!" << std::endl;
        return;
    }

    time_t now = time(0);
    char* dt = ctime(&now);

//    std::cout << "123456789012345678901234567890" << std::endl; // Ruler
    outputFile << "====== Hi-Lo Game Logs =======" << std::endl;
    outputFile << std::setw(20) << std::left << "Player Name: "
              << std::setw(10) << std::right << playerName << std::endl;

    outputFile << std::setw(20) << std::left << "Starting Balance:($)"
               << std::setw(10) << std::right << startingBalance << std::endl;

    outputFile << "\nTime: " << dt;
    outputFile << std::setw(30) << std::setfill('=') << "";
    outputFile << std::setfill(' ');

    outputFile.close();
}

void HistoryLogger::logGameResult(const Card& card, int betNumber, double betAmount, double result, double currentBalance,
                                  double multiplier, const std::string &betOn) {
    std::ofstream outputFile{outputFileName, std::ios::app};
    if (!outputFile) {
        std::cerr << "Error writing details to file!" << std::endl;
        return;
    }

    time_t now = time(0);
    char* dt = ctime(&now);

    outputFile << "\n";
    outputFile << std::setw(26) << std::setfill('-') << "" << std::endl;
    outputFile << std::setfill(' ');
    outputFile << "Bet Number #" << betNumber << std::endl;
    outputFile << dt << std::endl;

    outputFile << card << std::endl << std::endl;
    outputFile << "Bet Amount: $" << betAmount << std::endl;
    outputFile << "Bet On: " << betOn << std::endl;
    if (result == 0)
        outputFile << "Result: -$" << betAmount << std::endl;
    else
        outputFile << "Result: +$" << result << " (" << betAmount << " * " << multiplier << ")" << std::endl;
    outputFile << "Balance: $" << currentBalance << std::endl;
    outputFile << std::setw(26) << std::setfill('-') << "";
    outputFile << std::setfill(' ');
    outputFile << "\n\n";

    outputFile.close();
}

void HistoryLogger::logDeposit(double depositAmount, double balance) {
    std::ofstream outputFile{outputFileName, std::ios::app};
    if (!outputFile) {
        std::cerr << "Error writing details to file!" << std::endl;
        return;
    }

    time_t now = time(0);
    char* dt = ctime(&now);

    outputFile << "\n";
    outputFile << std::setw(26) << std::setfill('-') << "";
    outputFile << std::setfill(' ');

    outputFile << "\n" << dt;
    outputFile << "Deposit Balance: +$" << depositAmount << std::endl;
    outputFile << "New Balance: $" << balance << std::endl;

    outputFile << std::setw(26) << std::setfill('-') << "";
    outputFile << std::setfill(' ');
    outputFile << "\n\n";
    outputFile.close();
}

void HistoryLogger::setPlayerName(const std::string& name) {
    this->playerName = name;
}

void HistoryLogger::setBalance(double balance) {
    this->startingBalance = balance;
}
