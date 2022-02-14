//
// Created by Liam Ross on 10/02/2022.
//

#include "Card.h"

Card::Card() :
    value{},
    color{},
    cardValueIndex{},
    cardValues{"2", "3", "4", "5", "6", "7",
               "8", "9", "10","J", "Q", "K",
               "A", "Joker"},
    cardColors{"red", "black"},
    cardValuesHard{"2","2", "3", "3", "4", "4", "5", "5", "6", "6", "7", "7",
                   "8", "8", "9", "9", "10", "10","J", "J", "Q", "Q", "K", "K",
                   "A", "A", "Joker"}
{
    generateRandomCard();
}

Card::Card(bool harderMode) : Card() {
    this->harderMode = harderMode;
}

void Card::printCard() const {
    const int cardWidth{9};

    std::cout << "\n";
    std::cout << std::setw(cardWidth) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "|" << std::setw(cardWidth-2) << "" << "|" << std::endl;
    if (value.length() == 5)
        std::cout << "| " << green << value << white << " |" << std::endl;
    else if (value.length() == 2) {
        if (color == "red")
            std::cout << "|   " << red << value << white << "  |" << std::endl;
        else
            std::cout << "|   " << black << value << white << "  |" << std::endl;
    }
    else
        if (color == "red")
            std::cout << "|   " << red << value << white << "   |" << std::endl;
        else
            std::cout << "|   " << black << value << white << "   |" << std::endl;
    std::cout << "|" << std::setw(cardWidth-2) << "" << "|" << std::endl;
    std::cout << std::setw(cardWidth) << std::setfill('=') << "" << std::endl;
}

void Card::printCardBack() const {
    const int cardWidth{9};

    std::cout << "\n";
    std::cout << std::setw(cardWidth) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << "|" << std::setw(cardWidth-2) << "" << "|" << std::endl;
    std::cout << "|   " << "\u2660" << "   |" << std::endl;
    std::cout << "|" << std::setw(cardWidth-2) << "" << "|" << std::endl;
    std::cout << std::setw(cardWidth) << std::setfill('=') << "" << std::endl;
}

void Card::generateRandomCard() {
    if (harderMode) {
        cardValueIndex = getRandomNumber(0, numberOfValuesHard-1);
        value = cardValuesHard[cardValueIndex];
    } else {
        cardValueIndex = getRandomNumber(0, numberOfValues-1);
        value = cardValues[cardValueIndex];
    }

    if (value == "Joker") {
        color = "green";
        return;
    }
    color = cardColors[getRandomNumber(0, numberOfColors-1)];
}

int Card::getRandomNumber(int min, int max) {
    std::default_random_engine defaultRandomEngine(time(0));
    std::uniform_int_distribution<int> intDistribution(min, max);

    return intDistribution(defaultRandomEngine);
}

std::string Card::getCardValue() const {
    return value;
}

std::string Card::getCardColor() const {
    return color;
}

int Card::getCardValueIndex() const {
    return cardValueIndex;
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << "Card Value: " << card.value << "\nCard Color: " << card.color;
    return os;
}

bool Card::operator<(const Card &rhs) const {
    return cardValueIndex < rhs.cardValueIndex;
}

bool Card::operator>(const Card &rhs) const {
    return cardValueIndex > rhs.cardValueIndex;
}


