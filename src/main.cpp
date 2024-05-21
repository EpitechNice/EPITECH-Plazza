#include "User.hpp"
#include "Manager.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <multiplier> <numChefs> <restockTime>" << std::endl;
        return 1;
    }

    int numChefs = std::atoi(argv[2]);
    int restockTime = std::atoi(argv[3]);

    Manager::getInstance().setNumChefs(numChefs);
    Manager::getInstance().setRestockTime(restockTime);

    User user;
    user.readCommand();

    return 0;
}
