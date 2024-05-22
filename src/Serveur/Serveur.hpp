// server.hpp
#ifndef SERVEUR_HPP
#define SERVEUR_HPP

#include <string>
#include "includes.hpp"

class Serveur: Flint::Inspection<Serveur>
{
    private:
        Serveur() {}
        static Serveur instance;

    public:
        static Serveur& getInstance();
        void notifyReadyPizza(const std::string& pizza);

        std::string str() const;
};

#endif // SERVEUR_HPP
