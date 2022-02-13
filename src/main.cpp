#include <iostream>
#include <string>
#include <limits>

#include "HiLo.h"

int main() {
    std::string name;
    double balance;

    std::cout << "Please enter your name: \n>";
    std::cin >> name;

    bool done{false};
    std::string entry;
    do {
        std::cout << "\nEnter your starting Balance: \n>";
        std::cin >> entry;
        std::istringstream validator{entry};
        if (validator >> balance) {
            if (balance != 0)
                done = true;
        }
        else
            std::cout << "\nInvalid starting balance entered!" << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (!done);

    HiLo game{name, balance};
    game.startGame();
    return 0;
}

