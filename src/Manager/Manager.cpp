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
    }
}

void Manager::manageKitchens() {
    for (auto& kitchen : kitchens) {
        kitchen.checkCooksStatus();
        kitchen.checkIngredients();
    }
}

void Manager::preparePizza(const std::string& pizza) {
    std::string name;
    std::string size;
    int multiplier;

    std::stringstream ss(pizza);
    ss >> name >> size >> multiplier;
    if (name == "Margarita") {
        for (auto& kitchen : kitchens) {
            if (kitchen.isAvailable(size, {Ingredients::Dough, Ingredients::Tomato, Ingredients::Gruyere})) {
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
