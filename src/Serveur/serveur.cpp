// server.cpp
#include "serveur.hpp"
#include <iostream>

Serveur Serveur::instance;

Serveur& Serveur::getInstance() {
    return instance;
}

void Serveur::notifyReadyPizza(const std::string& pizza) {
    std::cout << "Le serveur annonce : Votre pizza " << pizza << " est prête à être dégustée !" << std::endl;
}
