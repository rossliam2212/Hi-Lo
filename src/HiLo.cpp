//
// Created by Liam Ross on 10/02/2022.
//

#include "HiLo.h"

HiLo::HiLo(std::string name, double balance) :
    name{std::move(name)},
    balance{balance},
    currentBet{},
    currentBetOption{},
    totalWin{},
    gameLog{name, balance},
    currentCard{},
    previousCards{},
    gameRunning{false},
    newGame{true}
{
}

void HiLo::startGame() {
    if (newGame) {
        printWelcome();
        printInstructions();
        newGame = false;
    } else {
        char choice;
        std::cout << "Would you like to view the instructions? (y/n)" << green << "\n>" << white;
        std::cin >> choice;

        while (tolower(choice) != 'y' && tolower(choice) != 'n') {
            std::cout << "Invalid Option! Try again. (y/n)" << green << "\n>" << white;
            std::cin >> choice;
        }

        if (choice == 'y')
            printInstructions();
    }

    char choice{};
    std::cout << "\nReady to play? (y/n)" << green << "\n>" << white;
    std::cin >> choice;
    while (tolower(choice) != 'y' && tolower(choice) != 'n') {
        std::cout << "Invalid option! Try again. (y/n)" << green << "\n>" << white;
        std::cin >> choice;
    }

    if (choice == 'y')
        gameRunning = true;
    else {
        std::cout << "No problem! See you soon " << green << ":)" << white << std::endl;
        return;
    }

    std::cout << green << "\n-- Game Started. Good Luck! --" << white << std::endl;
    while (gameRunning) {
        betNumber++;
        currentCard.printCardBack();
        std::cout << underline << "Balance:" << removeUnderline " $" << balance << std::endl;
        printBetOptions();
        getPlayerBet();
        currentCard.printCard();
        printResult();
    }
}

void HiLo::getPlayerBet() {
    double betAmount{};
    bool done{false};
    std::string entry;

    do {
        std::cout << "Enter your bet amount:" << green << "\n>" << white;
        std::cin >> entry;
        std::istringstream validator{entry};
        if (validator >> betAmount) {
            if (validateBetAmount(betAmount)) {
                done = true;
                balance -= betAmount;
                currentBet = betAmount;
            }
            else {
                std::cout << "Insufficient funds available! Try again." << std::endl;
                if (balance <= 0)
                    askDepositBalance();
            }
        } else
            std::cout << "Invalid bet amount! Try again." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);

    checkPlayerBet();
}

void HiLo::checkPlayerBet() {
    switch (currentBetOption) {
        // Hi
        case 1: {
            Card previousCard{previousCards.at(previousCards.size() - 1)};
            if (currentCard > previousCard) {
                totalWin = currentBet * hiWinMultiplier;
            } else
                totalWin = 0;
            break;
        }
        // Lo
        case 2: {
            Card previousCard{previousCards.at(previousCards.size() - 1)};
            if (currentCard < previousCard) {
                totalWin = currentBet * loWinMultiplier;
            } else
                totalWin = 0;
            break;
        }
        // Red
        case 3:
            if (currentCard.getCardColor() == "red") {
                totalWin = currentBet * colorWinMultiplier;
            } else
                totalWin = 0;
            break;
        // Black
        case 4:
            if (currentCard.getCardColor() == "black") {
                totalWin = currentBet * colorWinMultiplier;
            } else
                totalWin = 0;
            break;
        // 2 - 10
        case 5:
            for (int i = 2; i <= 10; i++) {
                if (std::stoi(currentCard.getCardValue()) == i) {
                    totalWin = currentBet * numbersWinMultiplier;
                    break;
                } else {
                    if (i == 10)
                        totalWin = 0;
                }
            }
            break;
        // J, Q, K, A
        case 6:
            if (currentCard.getCardValue() == "J" || currentCard.getCardValue() == "Q" || currentCard.getCardValue() == "K" || currentCard.getCardValue() == "A") {
                totalWin = currentBet * facesWinMultiplier;
            } else
                totalWin = 0;
            break;
        // K, A
        case 7:
            if (currentCard.getCardValue() == "K" || currentCard.getCardValue() == "A") {
                totalWin = currentBet * kingAceWinMultiplier;
            } else
                totalWin = 0;
            break;
        // A
        case 8:
            if (currentCard.getCardValue() == "A") {
                totalWin = currentBet * aceWinMultiplier;
            } else
                totalWin = 0;
            break;
        // Joker
        case 9:
            if (currentCard.getCardValue() == "Joker" && currentCard.getCardColor() == "green") {
                totalWin = currentBet * jokerWinMultiplier;
            } else
                totalWin = 0;
            break;
    }
    updateBalance(totalWin);
}

void HiLo::getBetOption() {
    bool done{false};
    std::string entry;
    do {
        std::cout << "\nWhat would you like to bet on?" << green << "\n>" << white;
        std::cin >> entry;
        std::istringstream validator{entry};

        if (validator >> currentBetOption) {
            if (validateBetOption(currentBetOption)) {
                done = true;
            }
            else if (currentBetOption == 10) {
                done = true;
                printExtraOptions();
            }
            else
                std::cout << "Invalid option! Try again." << std::endl;
        } else
            std::cout << "Invalid option! Try again." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);
}

bool HiLo::validateBetAmount(double bet) const {
    if (balance - bet >= 0) return true;
    return false;
}

bool HiLo::validateBetOption(int option) const {
    if (option < 1 || option > 9) return false;
    return true;
}

void HiLo::askDepositBalance() {
    int choice{};
    bool done{false};
    std::string entry;
    std::cout << "\nIt appears that you have run out of balance!" << std::endl;
    do {
        std::cout << "\nWhat would you like to do?" << std::endl;
        std::cout << "1 - Deposit Balance." << std::endl;
        std::cout << "2 - Quit Game." << std::endl;

        std::cin >> entry;
        std::istringstream validator{entry};
        if (validator >> choice) {
            switch (choice) {
                case 1: {
                    done = true;
                    double depositAmount{};
                    std::cout << "\nHow much would you like to deposit?" << green << "\n>" << white;
                    std::cin >> depositAmount;
                    if (addBalance(depositAmount)) {
                        std::cout << depositAmount << " has been successfully added to your balance." << std::endl;
                        gameLog.logDeposit(depositAmount, balance);
                    }
                    else
                        std::cout << "An error occurred adding your Balance. Try Again!" << std::endl;
                    break;
                }
                case 2: {
                    done = true;
                    gameRunning = false;
                    printGoodBye();
                    break;
                }
                default:
                    std::cout << "\nInvalid Option! Try again." << std::endl;
                    break;
            }
        }
        else
            std::cout << "\nInvalid option! Try again." << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);
}

bool HiLo::addBalance(double amount) {
    if (amount <= 0) return false;
    balance += amount;
    return true;
}

void HiLo::updateBalance(double amount) {
    balance += amount;
}

void HiLo::setNextCard() {
    calculateHiLoRangeAndMultipliers();
    previousCards.push_back(currentCard);
    currentCard.generateRandomCard();
}

void HiLo::printResult()  {
    std::string betOn{};
    double betMultiplier{};
    switch (currentBetOption) {
        case 1:
            betOn = "Hi";
            betMultiplier = hiWinMultiplier;
            break;
        case 2:
            betOn = "Lo";
            betMultiplier = loWinMultiplier;
            break;
        case 3:
            betOn = "Red";
            betMultiplier = colorWinMultiplier;
            break;
        case 4:
            betOn = "Black";
            betMultiplier = colorWinMultiplier;
            break;
        case 5:
            betOn = "2 - 10";
            betMultiplier = numbersWinMultiplier;
            break;
        case 6:
            betOn = "J, Q, K, A";
            betMultiplier = facesWinMultiplier;
            break;
        case 7:
            betOn = "K, A";
            betMultiplier = kingAceWinMultiplier;
            break;
        case 8:
            betOn = "A";
            betMultiplier = aceWinMultiplier;
            break;
        case 9:
            betOn = "Joker";
            betMultiplier = jokerWinMultiplier;
            break;

    }
    std::cout << std::setfill(' ');
    std::cout << "Bet Amount: $" << currentBet << std::endl;
    std::cout << "Bet on: " << betOn << std::endl;
    if (totalWin == 0)
        std::cout << "Result: " << red << "-$" << currentBet << white << std::endl;
    else
        std::cout << "Result: " << green << "+$" << green << totalWin << white << std::endl;

    gameLog.logGameResult(currentCard, betNumber, currentBet, totalWin, balance, betMultiplier, betOn);
    setNextCard();
}

void HiLo::calculateHiLoRangeAndMultipliers() {
    if (currentCard.getCardValue() == "2") {
        hiRange = "(3-A)";
        hiWinMultiplier = 1.09;
        hiMultiplier = "[1.09x]";

        loRange = "(2)";
        loWinMultiplier = 12;
        loMultiplier = "[12x]";
    } else if (currentCard.getCardValue() == "3") {
        hiRange = "(4-A)";
        hiWinMultiplier = 1.2;
        hiMultiplier = "[1.2x]";

        loRange = "(2)";
        loWinMultiplier = 12;
        loMultiplier = "[12x]";
    } else if (currentCard.getCardValue() == "4") {
        hiRange = "(5-A)";
        hiWinMultiplier = 1.33;
        hiMultiplier = "[1.33x]";

        loRange = "(2-3)";
        loWinMultiplier = 6;
        loMultiplier = "[6x]";
    } else if (currentCard.getCardValue() == "5") {
        hiRange = "(6-A)";
        hiWinMultiplier = 1.5;
        hiMultiplier = "[1.5x]";

        loRange = "(2-4)";
        loWinMultiplier = 4;
        loMultiplier = "[4x]";
    } else if (currentCard.getCardValue() == "6") {
        hiRange = "(7-A)";
        hiWinMultiplier = 1.71;
        hiMultiplier = "[1.71x]";

        loRange = "(2-5)";
        loWinMultiplier = 3;
        loMultiplier = "[3x]";
    } else if (currentCard.getCardValue() == "7") {
        hiRange = "(8-A)";
        hiWinMultiplier = 2;
        hiMultiplier = "[2x]";

        loRange = "(2-6)";
        loWinMultiplier = 2.4;
        loMultiplier = "[2.4x]";
    } else if (currentCard.getCardValue() == "8") {
        hiRange = "(9-A)";
        hiWinMultiplier = 2.4;
        hiMultiplier = "[2.4x]";

        loRange = "(2-7)";
        loWinMultiplier = 2;
        loMultiplier = "[2x]";
    } else if (currentCard.getCardValue() == "9") {
        hiRange = "(10-A)";
        hiWinMultiplier = 3;
        hiMultiplier = "[3x]";

        loRange = "(2-8)";
        loWinMultiplier = 1.71;
        loMultiplier = "[1.71x]";
    } else if (currentCard.getCardValue() == "10") {
        hiRange = "(J-A)";
        hiWinMultiplier = 3;
        hiMultiplier = "[3x]";

        loRange = "(2-9)";
        loWinMultiplier = 1.71;
        loMultiplier = "[1.71x]";
    } else if (currentCard.getCardValue() == "J") {
        hiRange = "(Q-A)";
        hiWinMultiplier = 4;
        hiMultiplier = "[4x]";

        loRange = "(2-10)";
        loWinMultiplier = 1.5;
        loMultiplier = "[1.5x]";
    } else if (currentCard.getCardValue() == "Q") {
        hiRange = "(K-A)";
        hiWinMultiplier = 6;
        hiMultiplier = "[6x]";

        loRange = "(2-J)";
        loWinMultiplier = 1.33;
        loMultiplier = "[1.33x]";
    } else if (currentCard.getCardValue() == "K") {
        hiRange = "(A)";
        hiWinMultiplier = 12;
        hiMultiplier = "[12x]";


        loRange = "(2-Q)";
        loWinMultiplier = 1.2;
        loMultiplier = "[1.2x]";
    } else if (currentCard.getCardValue() == "A") {
        hiRange = "(A)";
        hiWinMultiplier = 12;
        hiMultiplier = "[12x]";

        loRange = "(2-K)";
        loWinMultiplier = 1.09;
        loMultiplier = "[1.09x]";
    }
}

void HiLo::printBetOptions() {
    const int optionTableWidth{36};
    const int optionTableField1{18};
    const int optionTableField2{23};

    const int optionTableRangeWidth{8};
    const int optionTableMultiplierWidth1{10};
    const int optionTableMultiplierWidth2{13};

    std::cout << std::setw(optionTableWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(optionTableField1) << std::left << "Option"
              << std::setw(optionTableRangeWidth) << std::left << "Range"
              << std::setw(optionTableMultiplierWidth1) << std::left << "Multiplier" << std::endl;

    std::cout << std::setw(optionTableWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    if (betNumber > 1) {
        std::cout << std::setw(optionTableField1) << std::left << "1 - Bet Hi"
                  << std::setw(optionTableRangeWidth) << std::left << hiRange
                  << std::setw(optionTableMultiplierWidth1) << std::right << hiMultiplier << std::endl;

        std::cout << std::setw(optionTableField1) << std::left << "2 - Bet Lo"
                  << std::setw(optionTableRangeWidth) << std::left << loRange
                  << std::setw(optionTableMultiplierWidth1) << std::right << loMultiplier << std::endl;
    }

    std::cout << std::setw(optionTableField2) << std::left << "3 - Bet Red" << std::setw(optionTableMultiplierWidth2) << std::right<< "[2x]" << std::endl;
    std::cout << std::setw(optionTableField2) << std::left << "4 - Bet Black" << std::setw(optionTableMultiplierWidth2) << std::right << "[2x]" << std::endl;
    std::cout << std::setw(optionTableField2) << std::left << "5 - Bet 2-10" << std::setw(optionTableMultiplierWidth2) << std::right << "[1.5x]" << std::endl;
    std::cout << std::setw(optionTableField2) << std::left << "6 - Bet J,Q,K,A" << std::setw(optionTableMultiplierWidth2) << std::right << "[3x]" << std::endl;
    std::cout << std::setw(optionTableField2) << std::left << "7 - Bet K,A" << std::setw(optionTableMultiplierWidth2) << std::right << "[6x]" << std::endl;
    std::cout << std::setw(optionTableField2) << std::left << "8 - Bet A" << std::setw(optionTableMultiplierWidth2) << std::right << "[12x]" << std::endl;
    std::cout << std::setw(optionTableField2) << std::left << "9 - Bet Joker" << std::setw(optionTableMultiplierWidth2) << std::right << "[24x]" << std::endl;
    std::cout << std::setw(optionTableField2) << std::left << "\n10 - Additional Options" << std::endl;

    std::cout << std::setw(optionTableWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
    printPreviousCards();
    getBetOption();
}

void HiLo::printExtraOptions() {
    std::cout << green << "\nAdditional Options:" << white << std::endl;
    std::cout << "1 - View Balance." << std::endl;
    std::cout << "2 - Deposit Balance." << std::endl;
    std::cout << "3 - View previous cards in a table." << std::endl;
    std::cout << "4 - Quit Game." << std::endl;

    int option{};
    std::string entry;
    bool done{false};
    do {
        std::cout << "\nWhat would you like to do? \n>";
        std::cin >> entry;
        std::istringstream validator{entry};

        if (validator >> option) {
            done = true;
            switch (option) {
                case 1:
                    std::cout << "\nCurrent Balance: $" << balance << "\n" << std::endl;
                    break;
                case 2: {
                    double depositAmount{};
                    std::cout << "\nHow much would you like to deposit?" << green << "\n>" << white;
                    std::cin >> depositAmount;
                    if (addBalance(depositAmount)) {
                        std::cout << depositAmount << " has been successfully added to your balance." << std::endl;
                        gameLog.logDeposit(depositAmount, balance);
                    }
                    else
                        std::cout << "An error occurred adding your balance. Try Again!" << std::endl;
                    break;
                }
                case 3:
                    printPreviousCardsTable();
                    break;
                case 4:
                    printGoodBye();
                    return;
            }
        } else
            std::cout << "Invalid option! Try again." << std::endl;
    } while (!done);

    printBetOptions();
    getBetOption();
}

void HiLo::printPreviousCards() const {
    std::cout << "Previous Cards: ";
    for (const auto& card : previousCards) {
        if (card.getCardColor() == "red")
            std::cout << red << card.getCardValue()  << white << ", ";
        else if (card.getCardColor() == "black")
            std::cout << black << card.getCardValue() << white << ", ";
        else if (card.getCardColor() == "green")
            std::cout << green << card.getCardValue() << white << ", ";
    }
    std::cout << "\n";
}

void HiLo::printPreviousCardsTable() {
    std::cout << "\nPrevious Cards Table PlaceHolder" << std::endl;
}

void HiLo::printWelcome() const {
    std::cout << green << "\n=== Welcome to Hi-Lo " << name << "! ===" << white << std::endl;
}

void HiLo::printInstructions() const {
    std::cout << underline << green << "\n-- Game Instructions --"  << white << removeUnderline << std::endl;
    std::cout << green << "-" << white << " When the game starts, you will be shown the back of a card like below.";
    currentCard.printCardBack();
    std::cout << green << "-" << white << " You will then be asked what you would like to be on from the options displayed." << std::endl;
    std::cout << green << "-" << white << " Once an option is chosen, you will be asked to enter the amount you want to bet." << std::endl;
    std::cout << green << "-" << white << " After your bet has been entered, the card will be flipped and the results will be calculated and displayed." << std::endl;
    std::cout << green << "\n-" << white << " The win multipliers for all of the options are displayed beside each option every round." << std::endl;
    std::cout << green << "-" << white << " The multipliers for Red, Black, (2-10), (J,Q,K,A), (K,A), (A) and Joker are fixed." << std::endl;
    std::cout << green << "-" << white << " However, the Hi & Lo multipliers are calculated based on what the previous card flipped was." << std::endl;
    std::cout << green << "-" << white << " The range for the Hi & Lo options are also calculated based on what the previous card flipped was." << std::endl;
    std::cout << green << "- Note:" << white << " You will not be able to bet on Hi or Lo until after the first card has been flipped." << std::endl;
    std::cout << green << "- Note:"  << white " The Joker is a " << underline "special card" << removeUnderline << " and is not included in the Hi & Lo ranges or bets." << std::endl;

}

void HiLo::printGoodBye() {
    std::cout << "\nThanks for playing " << name << "!" << std::endl;
    std::cout << "Come back soon :)" << std::endl;
    gameRunning = false;
    exit(0);
}

