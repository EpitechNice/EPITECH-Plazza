// kitchen.cpp
#include "kitchen.hpp"
#include <iostream>
#include <thread>

Kitchen::Kitchen() {
    ingredientsStock[Ingredients::Dough] = 5;
    ingredientsStock[Ingredients::Tomato] = 5;
    ingredientsStock[Ingredients::Gruyere] = 5;
    ingredientsStock[Ingredients::Ham] = 5;
    ingredientsStock[Ingredients::Mushrooms] = 5;
    ingredientsStock[Ingredients::Eggplant] = 5;
    ingredientsStock[Ingredients::GoatCheese] = 5;
    ingredientsStock[Ingredients::ChiefLove] = 5;
    ingredientsStock[Ingredients::Steak] = 5;
}

bool Kitchen::isAvailable(const std::string& size, const std::map<Ingredients, int>& requiredIngredients) {
    std::lock_guard<std::mutex> lock(mtx);
    bool enoughIngredients = true;
    for (const auto& ingredient : requiredIngredients) {
        if (ingredientsStock[ingredient.first] < ingredient.second) {
            enoughIngredients = false;
            break;
        }
    }
    return enoughIngredients && chefs.size() > 0;
}

void Kitchen::preparePizza(const std::string& name, const std::string& size, int multiplier) {
    std::cout << "Préparation de la pizza " << name << " de taille " << size << "..." << std::endl;
    int cookingTime = calculateCookingTime(name, size, multiplier);
    std::vector<std::thread> threads;
    for (auto& chef : chefs) {
        if (chef.isAvailable()) {
            chef.takeOrder(name, size, cookingTime);
            threads.push_back(std::thread(&Chef::cook, chef, name, size, cookingTime));
        }
    }
    for (auto& thread : threads) {
        thread.join();
    }
    std::cout << "Pizza " << name << " de taille " << size << " prête à être dégustée !" << std::endl;
}

void Kitchen::checkCooksStatus() {
    for (auto& chef : chefs) {
        if (chef.getNumPizzasInProgress() < 2) {
            chef.setNumPizzasInProgress(2);
            break;
        }
    }
}

void Kitchen::checkIngredients() {
    // Vérifier les niveaux d'ingrédients et les reconstituer si nécessaire
}

int Kitchen::calculateCookingTime(const std::string& name, const std::string& size, int multiplier) {
    int baseTime;
    if (name == "Margarita") {
        baseTime = 1;
    } else if (name == "Regina" || name == "Americana") {
        baseTime = 2;
    } else if (name == "Fantasia") {
        baseTime = 4;
    } else {
        baseTime = 0;
    }
    return baseTime * multiplier;
}
