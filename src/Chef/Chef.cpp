#include "Chef.hpp"

Chef::Chef(int id) : id(id), numPizzasInProgress(0) {}

Chef::~Chef() {}

void Chef::cook(const std::string& name, const std::string& size, int cookingTime) {
    std::cout << "Chef " << id << " prépare une pizza " << name << " de taille " << size << "..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(cookingTime));
    std::cout << "Pizza " << name << " de taille " << size << " préparée par chef " << id << std::endl;
    Serveur::getInstance().notifyReadyPizza(name + " " + size);
    numPizzasInProgress--;
}

void Chef::takeOrder() {
    numPizzasInProgress++;
}

bool Chef::isAvailable() const {
    return numPizzasInProgress < 2;
}

int Chef::getId() const {
    return id;
}

int Chef::getNumPizzasInProgress() const {
    return numPizzasInProgress;
}

void Chef::setNumPizzasInProgress(int num) {
    numPizzasInProgress = num;
}

std::string Chef::str() const
{
    return make_str(display_attr(id) << ", " << display_attr(numPizzasInProgress));
}
