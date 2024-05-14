/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2024                                                     *
 * Title           - Plazza                                                             *
 * Description     -                                                                    *
 *     Parsing                                                                          *
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

#include "Parsing.hpp"

Parsing& Parsing::get()
{
    static Parsing instance;
    return instance;
}

void Parsing::parse(int argc, char** argv)
{
    if (argc != 4)
        throw_exception(Flint::Exceptions::ParsingError, "Required 3 arguments, but got " + std::to_string(argc - 1));

    try {
        this->_multiplierTime = std::stod(argv[1]);
    } catch (const std::invalid_argument& e) {
        throw_exception(Flint::Exceptions::ParsingError, "Invalid value for type double: " + std::string(argv[1]));
    }
    // if (this->_multiplierTime > 1.0 &&
    //     (this->_multiplierTime != (int)this->_multiplierTime))
    //     throw_exception(Flint::Exceptions::ParsingError, "Multiplier should be 0 < x < 1 or integer value");
    if (std::string(argv[1]).find('-') != std::string::npos)
        throw_exception(Flint::Exceptions::ParsingError, "Values should not be negatives !");
    if (std::string(argv[2]).find('.') != std::string::npos ||
        std::string(argv[2]).find('-') != std::string::npos)
        throw_exception(Flint::Exceptions::ParsingError, "Invalid value for type std::size_t: " + std::string(argv[2]));
    if (std::string(argv[3]).find('.') != std::string::npos ||
        std::string(argv[3]).find('-') != std::string::npos)
        throw_exception(Flint::Exceptions::ParsingError, "Invalid value for type std::size_t: " + std::string(argv[3]));

    try {
        this->_nbCooks = std::stoul(argv[2]);
    } catch (const std::invalid_argument& e) {
        throw_exception(Flint::Exceptions::ParsingError, "Invalid value for type std::size_t: " + std::string(argv[2]));
    }
    try {
        this->_refillTime = std::stoul(argv[3]);
    } catch (const std::invalid_argument& e) {
        throw_exception(Flint::Exceptions::ParsingError, "Invalid value for type std::size_t: " + std::string(argv[3]));
    }
}

double Parsing::getMultiplierTime() const
{
    return this->_multiplierTime;
}

int Parsing::getNbCooks() const
{
    return this->_nbCooks;
}

std::size_t Parsing::getRefillTime() const
{
    return this->_refillTime;
}
