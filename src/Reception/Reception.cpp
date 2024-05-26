/*                                                                                      *
 * EPITECH PROJECT - Sat, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Reception                                                                        *
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

#include "includes.hpp"
#include "Reception.hpp"
#include "../Manager/Manager.hpp"

namespace Plazza
{
    Reception::Reception(double multiplierCooking, int numChefs, int restockTime)
    {
        this->_manager = std::make_shared<Manager>(multiplierCooking, numChefs, restockTime);
    }

    void Reception::run() {
        std::string input;

        while (true) {
            if (isatty(0))
                std::cout << "> ";
            else
                std::cout << "===" << std::endl;
            if (!std::getline(std::cin, input))
                break;
            try {
                if (!this->_manager->receiveOrder(input))
                    break;
            } catch (const Flint::Exceptions::Exception& e) {
                std::cerr << e << std::endl;
            }
        }
    }

    void Reception::notifyReadyPizza(const std::string& pizza)
    {
        std::cout << "Reception: Your pizza " << pizza << " is ready to be enjoyed!" << std::endl;
    }

    std::string Reception::str() const
    {
        return make_str("No attributes");
    }
}