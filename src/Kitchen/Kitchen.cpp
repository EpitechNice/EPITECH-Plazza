#include "Kitchen.hpp"
#include <iostream>
#include <thread>
#include <chrono>

Kitchen::Kitchen(int numChefs) : running(true) {
    ingredientsStock[Ingredients::Dough] = 5;
    ingredientsStock[Ingredients::Tomato] = 5;
    ingredientsStock[Ingredients::Gruyere] = 5;
    ingredientsStock[Ingredients::Ham] = 5;
    ingredientsStock[Ingredients::Mushrooms] = 5;
    ingredientsStock[Ingredients::Eggplant] = 5;
    ingredientsStock[Ingredients::GoatCheese] = 5;
    ingredientsStock[Ingredients::ChiefLove] = 5;
    ingredientsStock[Ingredients::Steak] = 5;
    for (int i = 0; i < numChefs; ++i) {
        chefs.emplace_back(i);
    }
    startMonitoring(); // Démarrer la surveillance de l'activité
}

Kitchen::~Kitchen() {
    stopMonitoring();
    if (monitorThread.joinable()) {
        monitorThread.join();
    }
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
    return enoughIngredients;
}

void Kitchen::preparePizza(const std::string& name, const std::string& size, int multiplier) {
    std::cout << "Préparation de la pizza " << name << " de taille " << size << "..." << std::endl;
    int cookingTime = calculateCookingTime(name, size, multiplier);
    std::vector<std::thread> threads;
    for (auto& chef : chefs) {
        if (chef.isAvailable()) {
            chef.takeOrder(name, size, cookingTime);
            threads.push_back(std::thread(&Chef::cook, &chef, name, size, cookingTime));
        }
    }
    for (auto& thread : threads) {
        thread.join();
    }
    std::cout << "Pizza " << name << " de taille " << size << " prête à être dégustée !" << std::endl;
}

int Kitchen::checkCooksStatus() {
    for (auto& chef : chefs) {
        if (chef.getNumPizzasInProgress() > 0) {
            return 0;
        }
    }
    return 1;
}

int Kitchen::checkIngredients() {
    for (const auto& ingredient : ingredientsStock) {
        if (ingredient.second < 1) {
            return 1; // Si un ingrédient est épuisé
        }
    }
    return 0; // Tous les ingrédients sont disponibles
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

void Kitchen::restockIngredients() {
    std::lock_guard<std::mutex> lock(mtx);
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

void Kitchen::monitorActivity() {
    while (running) {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        if (checkCooksStatus() == 1 && checkIngredients() == 1) {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            if (checkCooksStatus() == 1 && checkIngredients() == 1) {
                std::lock_guard<std::mutex> lock(mtx);
                restockIngredients();
                std::cout << "La cuisine est fermée car aucune pizza n'était en préparation et les ingrédients étaient épuisés." << std::endl;
                running = false;
            }
        }
    }
}

void Kitchen::startMonitoring() {
    monitorThread = std::thread(&Kitchen::monitorActivity, this);
}

void Kitchen::stopMonitoring() {
    running = false;
    if (monitorThread.joinable()) {
        monitorThread.join();
    }
}
