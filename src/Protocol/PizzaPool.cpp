/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     PizzaPool                                                                        *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "PizzaPool.hpp"

namespace Plazza
{
    PizzaPool::PizzaPool()
    {
        this->_pizzaToReturn.lock();
        this->_pizzaToDo.lock();
    }

    PizzaPool::~PizzaPool()
    {}

    std::pair<Plazza::PizzaType, Plazza::PizzaSize> PizzaPool::startDoPizza()
    {
        this->_pizzaToDo.lock();
        std::pair<Plazza::PizzaType, Plazza::PizzaSize> output = {((Plazza::PizzaType)-1), ((Plazza::PizzaSize)-1)};
        if (this->_todo.size()) {
            output = this->_todo[this->_todo.size() - 1];
            this->_todo.pop_back();
        }
        this->_pizzaToDo.unlock();
        return output;
    }

    void PizzaPool::pizzaDone(std::pair<Plazza::PizzaType, Plazza::PizzaSize> pizza)
    {
        this->_pizzaToReturn.lock();
        this->_done.push_front(pizza);
        this->_pizzaToReturn.unlock();
    }

    void PizzaPool::askForPizza(std::pair<Plazza::PizzaType, Plazza::PizzaSize> pizza)
    {
        this->_pizzaToDo.lock();
        this->_todo.push_front(pizza);
        this->_pizzaToDo.unlock();
    }

    std::pair<Plazza::PizzaType, Plazza::PizzaSize> PizzaPool::getPizzaDone()
    {
        this->_pizzaToReturn.lock();
        std::pair<Plazza::PizzaType, Plazza::PizzaSize> output = {((Plazza::PizzaType)-1), ((Plazza::PizzaSize)-1)};
        if (this->_done.size()) {
            output = this->_done[this->_done.size() - 1];
            this->_done.pop_back();
        }
        this->_pizzaToReturn.unlock();
        return output;
    }
}