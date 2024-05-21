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

std::vector<std::string> str_to_word_array_on_steroid(std::string str, std::string delims)
{
    std::vector<std::string> output;
    
    std::size_t pos_start = 0, pos_end = 0, min = 0;
    std::string token;

    while (min != std::string::npos) {
        min = std::string::npos;
        for (std::size_t i = 0; i < delims.size(); i++) {
            pos_end = str.find(delims[i], pos_start);
            if (pos_end != std::string::npos && (pos_end < min || min == std::string::npos))
                min = pos_end;
        }
        if (min == std::string::npos) continue;
        token = str.substr(pos_start, min - pos_start);
        pos_start = min + 1;
        if (token.size())
            output.push_back(token);
    }

    if (str.substr(pos_start).size())
        output.push_back(str.substr(pos_start));
    return output;
}