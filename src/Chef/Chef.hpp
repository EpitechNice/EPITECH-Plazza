#ifndef CHEF_HPP
#define CHEF_HPP

#include <iostream>
#include <chrono>
#include <thread>
#include "../Serveur/Serveur.hpp"
#include "includes.hpp"

class Chef: Flint::Inspection<Chef>
{
    private:
        int id;
        int numPizzasInProgress;

    public:
        Chef(int id);
        ~Chef();

        void cook(const std::string& name, const std::string& size, int cookingTime);
        void takeOrder();
        bool isAvailable() const;
        int getId() const;
        int getNumPizzasInProgress() const;
        void setNumPizzasInProgress(int num);

        std::string str() const;
};

#endif // CHEF_HPP
