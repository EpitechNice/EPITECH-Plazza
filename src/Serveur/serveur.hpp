// server.hpp
#ifndef SERVEUR_HPP
#define SERVEUR_HPP

#include <string>

class Serveur {
private:
    Serveur() {}
    static Serveur instance;

public:
    static Serveur& getInstance();
    void notifyReadyPizza(const std::string& pizza);
};

#endif // SERVEUR_HPP
