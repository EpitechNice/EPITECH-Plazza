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
    Chef::Chef(int id) : _id(id), _numPizzasInProgress(0)
    {}

    void Chef::cook(const std::string& name, const std::string& size, int cookingTime)
    {
        std::cout << "The Cook " << this->_id << " prepares a pizza " << name << " of size " << size << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(cookingTime));
        std::cout << "Pizza " << name << " of size " << size << " was prepared by Cook " << this->_id << std::endl;
        Serveur::getInstance().notifyReadyPizza(name + " " + size);
        this->_numPizzasInProgress--;
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