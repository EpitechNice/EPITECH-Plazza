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
        double multiplierCooking;
        int numChefs;
        int restockTime;

        if (argc == 2 &&
            (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
            this->usage(argv[0]);
            std::exit(0);
        }
        try {
            Parsing::get().parse(argc, argv);
            multiplierCooking = Parsing::get().getMultiplierTime();
            numChefs = Parsing::get().getNbCooks();
            restockTime = Parsing::get().getRefillTime();
        } catch (const Flint::Exceptions::Exception& e) {
            std::cerr << catch_exception(e) << std::endl;
            std::exit(84);
        }

        // std::cout << "DEBUG | Multiplier time: " << Parsing::get().getMultiplierTime() << std::endl;
        // std::cout << "DEBUG | Nb cooks: " << Parsing::get().getNbCooks() << std::endl;
        // std::cout << "DEBUG | Refill time: " << Parsing::get().getRefillTime() << std::endl;
        this->loop(multiplierCooking, numChefs, restockTime);
    }

    void Core::usage(std::string filename)
    {
        std::cout << "USAGE\n\t" + filename + " [MultipierTime] [NbCooks] [RefillTime]" << std::endl;
    }

    void Core::loop(double multiplierCooking, int numChefs, int restockTime)
    {
        Plazza::Reception reception(multiplierCooking, numChefs, restockTime);

        reception.run();
    }

    std::string Core::str() const
    {
        return make_str("");
    }
}