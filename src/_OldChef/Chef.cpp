/*                                                                                      *
 * EPITECH PROJECT - Fri, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Chef                                                                             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#include "Chef.hpp"

namespace Plazza
{
    Chef::Chef(int id, std::shared_ptr<Plazza::PizzaPool> pool):
        _id(id), _numPizzasInProgress(0), _keepRunning(true), _pool(pool)
    {
        this->_thread = std::thread(Chef::runThread, this);
    }

//TODO : Clock
    void Chef::cook(const std::string& name, const std::string& size, int cookingTime, std::shared_ptr<Plazza::PizzaPool> pool)
    {
        // this->_pool = pool;
        // std::lock_guard<std::mutex> lock(this->_mutex);
        // std::cout << "\tThe Cook " << _id << " is preparing a pizza " << name << " of size " << size << "..." << std::endl;
        // std::this_thread::sleep_for(std::chrono::milliseconds(cookingTime * 1000));
        // std::cout << "\tPizza " << name << " of size " << size << " was prepared by Cook " << _id << std::endl;

        // this->_numPizzasInProgress--;
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
            pizza = self->_pool->startDoPizza();
            if (((std::size_t)pizza.first) == -1)
                continue;
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