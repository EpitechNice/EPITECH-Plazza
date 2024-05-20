#include <sstream>
#include "Manager.hpp"
#include "Serveur.hpp"

Manager Manager::instance;

Manager& Manager::getInstance() {
    return instance;
}

void Manager::receiveOrder(const std::string& order, int nbrChefs) {
    std::stringstream ss(order);
    std::string token;
    while (std::getline(ss, token, ';')) {
        preparePizza(token);
        manageKitchens();
    }
}

void Manager::manageKitchens() {
    for (auto it = kitchens.begin(); it != kitchens.end();) {
        if (it->checkCooksStatus() == 1 && it->checkIngredients() == 1) {
            it = kitchens.erase(it); // Supprime la cuisine si les conditions sont remplies
        } else {
            ++it;
        }
    }
}

void Manager::preparePizza(const std::string& pizza) {
    std::string name;
    std::string size;
    int multiplier;

    std::stringstream ss(pizza);
    ss >> name >> size >> multiplier;

    std::map<Ingredients, int> requiredIngredients;
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

    for (auto& kitchen : kitchens) {
        if (kitchen.isAvailable(size, requiredIngredients)) {
            kitchen.preparePizza(name, size, multiplier);
            return;
        }
    }

    // Si aucune cuisine n'est disponible, créer une nouvelle cuisine
    kitchens.emplace_back(numChefs);
    kitchens.back().preparePizza(name, size, multiplier);
}
