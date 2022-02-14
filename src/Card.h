//
// Created by Liam Ross on 10/02/2022.
//

#ifndef HI_LO_CARD_H
#define HI_LO_CARD_H

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>

#define black "\x1B[30m"
#define red "\x1B[31m"
#define green "\x1B[32m"
#define white "\x1B[97m"

class Card {
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
private:
    std::string value;
    std::string color;

    static const int numberOfValues{14};
    static const int numberOfColors{2};

    int cardValueIndex;
    std::string cardValues[numberOfValues];
    std::string cardColors[numberOfColors];

    // Harder Mode*
    bool harderMode{};
    static const int numberOfValuesHard{36};
    std::string cardValuesHard[numberOfValuesHard];

public:
    Card();
    explicit Card(bool harderMode);
    Card(const Card& source) = default;
    void generateRandomCard();
    void printCard() const;
    void printCardBack() const;

    std::string getCardValue() const;
    std::string getCardColor() const;
    int getCardValueIndex() const;

    bool operator<(const Card &rhs) const;
    bool operator>(const Card &rhs) const;

private:
    int getRandomNumber(int min, int max);
};


#endif //HI_LO_CARD_H
