#include "./Reception/Reception.hpp"
#include "./Manager/Manager.hpp"
#include <iostream>
#include <cstdlib>
#include "includes.hpp"
#include "Core/Core.hpp"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " \n\t<multiplier> <numChefs> <restockTime>" << std::endl;
        return 1;
    }

    int numChefs = std::atoi(argv[2]);
    int restockTime = std::atoi(argv[3]);

    Plazza::Manager::getInstance().setNumChefs(numChefs);
    Plazza::Manager::getInstance().setRestockTime(restockTime);

    Plazza::Reception reception;
    reception.run();

    return 0;
}
