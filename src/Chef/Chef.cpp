/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     Chef                                                                             *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#include "Chef.hpp"

namespace Plazza
{
    Chef::Chef(std::size_t id):
        _id(id), _keepRunning(false)
    {}

    void Chef::run(Chef* self)
    {
        while (self->_keepRunning) {
            self->_pizzaToDo.lock();
            std::cout << "\r\tThe Cook " <<
                    self->_id << " is preparing a pizza " <<
                    self->getType(std::get<0>(self->_pizzas[self->_pizzas.size() - 1])) << " of size " <<
                    self->getSize(std::get<1>(self->_pizzas[self->_pizzas.size() - 1])) << "..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(std::get<2>(self->_pizzas[self->_pizzas.size() - 1]) * 1000));
            std::cout << "\r\tPizza " <<
                    self->getType(std::get<0>(self->_pizzas[self->_pizzas.size() - 1])) << " of size " <<
                    self->getSize(std::get<1>(self->_pizzas[self->_pizzas.size() - 1])) << " was prepared by Cook " <<
                    self->_id << std::endl;
            self->_pizzas.pop_back();
            if (self->_pizzas.size())
                self->_pizzaToDo.unlock();
        }
    }

    void Chef::start()
    {
        this->_keepRunning = true;
        this->_pizzaToDo.lock();
        this->_thread = std::thread(Chef::run, this);
    }

    void Chef::stop()
    {
        this->_keepRunning = false;
        if (this->_thread.joinable())
            this->_thread.join();
    }

    bool Chef::isAvailable() const
    {
        return this->_pizzas.size() != 0;
    }

    std::string Chef::getType(Plazza::PizzaType type) const
    {
        switch (type)
        {
            case Plazza::PizzaType::Regina:
                return "Regina";

            case Plazza::PizzaType::Margarita:
                return "Margarita";

            case Plazza::PizzaType::Americana:
                return "Americana";

            case Plazza::PizzaType::Fantasia:
                return "Fantasia";

            default:
                break;
        }
        return "";
    }

    std::string Chef::getSize(Plazza::PizzaSize size) const
    {
        switch (size)
        {
            case Plazza::PizzaSize::S:
                return "S";

            case Plazza::PizzaSize::M:
                return "M";

            case Plazza::PizzaSize::L:
                return "L";

            case Plazza::PizzaSize::XL:
                return "XL";

            case Plazza::PizzaSize::XXL:
                return "XXL";

            default:
                break;
        }
        return "";
    }

    int Chef::getId() const
    {
        return this->_id;
    }

}