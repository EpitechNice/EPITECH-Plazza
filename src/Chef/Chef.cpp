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
    {
        this->_isBaking = false;
    }

//TODO : Serveur
    void Chef::cook(const std::string& name, const std::string& size, int cookingTime)
    {
        while (this->_isBaking)
            std::this_thread::sleep_for(std::chrono::seconds(1));
        this->_isBaking = true;
        std::cout << "\tThe Cook " << this->_id << " is preparing a pizza " << name << " of size " << size << "..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(cookingTime));
        std::cout << "\tPizza " << name << " of size " << size << " was prepared by Cook " << this->_id << std::endl;
        this->_numPizzasInProgress--;
        this->_isBaking = false;
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