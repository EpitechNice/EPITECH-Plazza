#include <sstream>
#include <chrono>
#include <thread>
#include "Manager.hpp"
#include "../Serveur/Serveur.hpp"

Manager Manager::instance;

Manager& Manager::getInstance() {
    return instance;
}

void Manager::receiveOrder(const std::string& order) {
    std::stringstream ss(order);
    std::string token;
    while (std::getline(ss, token, ';')) {
        preparePizza(token);
        manageKitchens();
    }
}

void Manager::manageKitchens() {
    const auto waitTime = std::chrono::seconds(10);
    for (auto& kitchen : kitchens) {
        if (kitchen.checkCooksStatus() == 1 && kitchen.checkIngredients() == 1) {
            std::this_thread::sleep_for(waitTime);
            kitchen.restockIngredients();
        }
    }
}

void Manager::preparePizza(const std::string& pizza) {
    std::string name;
    std::string size;
    int quantity = 1;
    int multiplier;


    std::stringstream ss(pizza);
    ss >> name >> size;
    if (ss.peek() == 'x') {
        ss.ignore();
        ss >> quantity;
    }
    ss >> multiplier;

    std::map<Ingredients, int> requiredIngredients;
    requiredIngredients = {{Ingredients::Dough, 0}};
    if (name == "Margarita") {
        requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}};
    } else if (name == "Regina") {
        requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Ham, 1}, {Ingredients::Mushrooms, 1}};
    } else if (name == "Americana") {
        requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Steak, 1}};
    } else if (name == "Fantasia") {
        requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Eggplant, 1}, {Ingredients::GoatCheese, 1}, {Ingredients::ChiefLove, 1}};
    } else {
        std::cout << "Nom de pizza non reconnu" << std::endl;
        return;
    }
//TODO : IPC
    for (auto& kitchen : kitchens) {
        if (kitchen.isAvailable(requiredIngredients)) {
            kitchen.preparePizza(name, size, multiplier);
            return;
        }
    }

    kitchens.back().preparePizza(name, size, multiplier);
}

void Manager::setNumChefs(int num) {
    numChefs = num;
}

void Manager::setRestockTime(int time) {
    restockTime = time;
}