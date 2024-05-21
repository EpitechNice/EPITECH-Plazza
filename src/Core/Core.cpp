/*                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - Visual Studio Live Share (Workspace)                               *
 * Description     -                                                                    *
 *     Core                                                                             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *       _|_|_|_|  _|_|_|    _|_|_|  _|_|_|_|_|  _|_|_|_|    _|_|_|  _|    _|           *
 *       _|        _|    _|    _|        _|      _|        _|        _|    _|           *
 *       _|_|_|    _|_|_|      _|        _|      _|_|_|    _|        _|_|_|_|           *
 *       _|        _|          _|        _|      _|        _|        _|    _|           *
 *       _|_|_|_|  _|        _|_|_|      _|      _|_|_|_|    _|_|_|  _|    _|           *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#include "Core.hpp"

namespace Plazza
{
    Core::Core(int argc, char **argv)
    {
        if (argc == 2 &&
            (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
            this->usage(argv[0]);
            std::exit(0);
        }
        try {
            Parsing::get().parse(argc, argv);
        } catch (const Flint::Exceptions::Exception& e) {
            std::cerr << catch_exception(e) << std::endl;
            std::exit(84);
        }

        std::cout << "Multiplier time: " << Parsing::get().getMultiplierTime() << std::endl;
        std::cout << "Nb cooks: " << Parsing::get().getNbCooks() << std::endl;
        std::cout << "Refill time: " << Parsing::get().getRefillTime() << std::endl;
        this->run();
    }

    void Core::usage(std::string filename)
    {
        std::cout << "Usage: " + filename + " [-h|--help] [MultipierTime] [NbCooks] [RefillTime]" << std::endl;
    }

    void Core::run(void)
    {
        std::string input;

        while (std::getline(std::cin, input)) {
            std::cout << "> ";
            try {
                std::cout << "DEBUG" << input << std::endl;
                Manager::getInstance().receiveOrder(input);
            } catch (const std::exception& e) {
                std::cerr << "Invalid command. (TEST)" << e.what() << std::endl;
            }
        }
    }
}