#include <sstream>
#include "Manager.hpp"
#include "Kitchen.hpp"

Manager Manager::instance;

Manager& Manager::getInstance() {
    return instance;
}

void Manager::receiveOrder(const std::string& order) {
    std::stringstream ss(order);
    std::string token;
    while (std::getline(ss, token, ';')) {
        orders.push_back(token);
        manageKitchens();
    }
}

void Manager::manageKitchens() {
    for (auto& kitchen : kitchens) {
        if (kitchen.checkCooksStatus() == 1 && kitchen.checkIngredients() == 1);
            //supp la cuisine;
    }
}

void Manager::preparePizza(const std::string& pizza) {
    std::string name;
    std::string size;
    int multiplier;
    std::map<Ingredients, int> requiredIngredients {
        {Ingredients::Dough, 1},
        {Ingredients::Tomato, 1},
        {Ingredients::Gruyere, 1}
        // a mettre les ingredients deffini par chaque pizza a balancer
    };

    std::stringstream ss(pizza);
    ss >> name >> size >> multiplier;
    if (name == "Margarita") {
        for (auto& kitchen : kitchens) {
            if (kitchen.isAvailable(size, requiredIngredients)) {
                kitchen.preparePizza(name, size, multiplier);
                return;
            }
        }
        kitchens.emplace_back();
        kitchens.back().preparePizza(name, size, multiplier);
    } else if (name == "Regina") {
    } else if (name == "Americana") {
    } else if (name == "Fantasia") {
    } else {
    }
}
