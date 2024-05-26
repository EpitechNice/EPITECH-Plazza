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
    Chef::Chef(int id):
        _id(id), _numPizzasInProgress(0), _keepRunning(true)
    {
        this->_thread.start(Chef::runThread, this);
    }

    void Chef::cook(const std::string& name, const std::string& size, int cookingTime)
    {
        std::lock_guard<Plazza::Mutex> lock(this->_mutex);
        std::cout << "\tThe Cook " << _id << " is preparing a pizza " << name << " of size " << size << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(cookingTime * 1000));
        std::cout << "\tPizza " << name << " of size " << size << " was prepared by Cook " << _id << std::endl;

        this->_numPizzasInProgress--;
        while (this->_keepRunning)
        {
            this->_mutex.lock();
            std::cout << "\tThe Cook " << _id << " is preparing a pizza " << name << " of size " << size << "..." << std::endl;
        }

    }

    void Chef::runThread(Chef* self)
    {
        while (self->_keepRunning)
        {
            // pizza = self->_pool->startDoPizza();
            // if (((std::size_t)pizza.first) == -1)
            //     continue;
        }
    }

    void Chef::takeOrder()
    {
        this->_numPizzasInProgress++;
    }

    bool Chef::isAvailable() const
    {
        return this->_numPizzasInProgress < 2;
    }

    int Chef::getId() const
    {
        return this->_id;
    }

    int Chef::getNumPizzasInProgress() const
    {
        return this->_numPizzasInProgress;
    }

    void Chef::setNumPizzasInProgress(int num)
    {
        this->_numPizzasInProgress = num;
    }

    std::string Chef::str() const
    {
        return make_str(display_attr(_id) << ", " << display_attr(_numPizzasInProgress));
    }
}
