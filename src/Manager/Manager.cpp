/*                                                                                      *
 * EPITECH PROJECT - Fri, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Manager                                                                          *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

#include "Manager.hpp"

namespace Plazza
{
    Manager::Manager(double multiplierCooking, int numChefs, int restockTime)
    {
        this->_multiplierCooking = multiplierCooking;
        this->_numChefs = numChefs;
        this->_restockTime = restockTime;
    }
//TODO : Review exception if grammatically invalid order
    bool Manager::receiveOrder(const std::string& order)
    {
        std::vector<std::string> tokens = this->strToWordArrayOnSteroid(order, " \t");

        if (!tokens.size())
            return true;

        if (tokens[0] == "status") {
            this->displayStatus();
            return true;
        }

        if (tokens[0] == "exit" || tokens[0] == "quit")
            return false;

        std::vector<std::string> requests = this->strToWordArrayOnSteroid(order, ";");
        for (const std::string& token: requests) {
            try {
                this->preparePizza(token);
            } catch (const Flint::Exceptions::Exception& e) {
                std::cerr << catch_exception(e) << std::endl;
            }
            this->manageKitchens();
        }
        return true;
    }

    void Manager::manageKitchens()
    {
        const auto waitTime = std::chrono::milliseconds(this->_restockTime);

        for (auto kitchen = _kitchenList.begin(); kitchen != _kitchenList.end();) {
            if ((*kitchen)->getClose()) {
                kitchen = _kitchenList.erase(kitchen);
                continue;
            }
            if ((*kitchen)->checkIngredients() == 1) {
                std::this_thread::sleep_for(waitTime);
                (*kitchen)->restockIngredients();
            }
            kitchen++;
        }
    }

    void Manager::createKitchen(void)
    {
        Plazza::Process _process;
        // pid_t pid = _process.create();
// 
        // if (_process.getType() == Plazza::processType::CHILD)
            // auto firstKitchen = std::make_shared<Kitchen>(this->_multiplierCooking, this->_numChefs, this->_restockTime);
            // this->_kitchenList.push_back(firstKitchen);
        
    }

    void Manager::stringToLower(std::string& str) const
    {
        for (std::size_t i = 0; i < str.size(); i++)
            str[i] = std::tolower(str[i]);
    }

    void Manager::preparePizza(const std::string& pizza)
    {
        std::string token = pizza;
        std::regex first_token("[a-z]+");
        std::regex second_token("^(S|M|L|XL|XXL)$");
        std::regex third_token("x[1-9][0-9]*");
        std::vector<std::string> tokens = this->strToWordArrayOnSteroid(token, " \t");

        if (tokens.size() != 3)
            throw_exception(Flint::Exceptions::InvalidCommandError, "There must be 3 tokens, " + std::to_string(tokens.size()) + " found.");

        this->stringToLower(tokens[0]);
        this->stringToLower(tokens[2]);

        if (!std::regex_match(tokens[0], first_token))
            throw_exception(Flint::Exceptions::InvalidCommandError, "First token of the order does not match regex !");

        if (!std::regex_match(tokens[1], second_token))
            throw_exception(Flint::Exceptions::InvalidCommandError, "Second token of the order does not match regex !");

        if (!std::regex_match(tokens[2], third_token))
            throw_exception(Flint::Exceptions::InvalidCommandError, "Third token of the order does not match regex !");

        std::size_t quantity = std::stoul(tokens[2].substr(1));
        size_t kitchenCount = this->_kitchenList.size();

        if (!kitchenCount) {
            auto firstKitchen = std::make_shared<Kitchen>(this->_multiplierCooking, this->_numChefs, this->_restockTime);
            this->_kitchenList.push_back(firstKitchen);
            kitchenCount++;
        }

        std::size_t pizzasPerKitchen = quantity / kitchenCount;
        std::size_t remainingPizzas  = quantity % kitchenCount;

        std::map<Ingredients, int> requiredIngredients = {};
        if (tokens[0] == "margarita") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}};
        } else if (tokens[0] == "regina") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Ham, 1}, {Ingredients::Mushrooms, 1}};
        } else if (tokens[0] == "americana") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Steak, 1}};
        } else if (tokens[0] == "fantasia") {
            requiredIngredients = {{Ingredients::Dough, 1}, {Ingredients::Tomato, 1}, {Ingredients::Gruyere, 1}, {Ingredients::Eggplant, 1}, {Ingredients::GoatCheese, 1}, {Ingredients::ChiefLove, 1}};
        } else {
            throw_exception(Flint::Exceptions::NotFoundError, "Requested pizza \"" + tokens[0] + "\" does not exists.");
            return;
        }

        for (std::size_t i = 0; i < kitchenCount; ++i) {
            auto& kitchen = this->_kitchenList[i];
            for (std::size_t j = 0; j < pizzasPerKitchen; ++j) {
                if (kitchen->isAvailable(requiredIngredients)) {
                    kitchen->preparePizza(tokens[0], tokens[1]);
                    --quantity;
                }
            }
        }

        for (std::size_t i = 0; i < remainingPizzas; ++i) {
            for (auto& kitchen : this->_kitchenList) {
                if (kitchen->isAvailable(requiredIngredients)) {
                    kitchen->preparePizza(tokens[0], tokens[1]);
                    quantity--;
                    break;
                }
            }
        }

        while (quantity > 0) {
            auto newKitchen = std::make_shared<Kitchen>(this->_multiplierCooking, this->_numChefs, this->_restockTime);
            this->_kitchenList.push_back(newKitchen);
            bool kitchenAvailable = true;
            while (kitchenAvailable && quantity > 0) {
                if (newKitchen->isAvailable(requiredIngredients)) {
                    newKitchen->preparePizza(tokens[0], tokens[1]);
                    quantity--;
                } else {
                    kitchenAvailable = false;
                }
            }
        }
    }

    void Manager::setNumChefs(int num)
    {
        this->_numChefs = num;
    }

    void Manager::setRestockTime(int time)
    {
        this->_restockTime = time;
    }

    void Manager::displayStatus()
    {
        int kitchenNumber = 1;
        if (this->_kitchenList.empty()) {
            std::cout << "\tKitchens status:\n\t\tNo open kitchen" <<std::endl;
        }

        for (const auto& kitchen : this->_kitchenList) {
            std::cout << "\tKitchens " << kitchenNumber << " status:" << std::endl;
            kitchen->displayStatus();
            kitchenNumber++;
        }
    }



    std::vector<std::string> Manager::strToWordArrayOnSteroid(const std::string& str, const std::string& delims) const
    {
        std::vector<std::string> output;

        std::size_t pos_start = 0, pos_end = 0, min = 0;
        std::string token;

        while (min != std::string::npos) {
            min = std::string::npos;
            for (std::size_t i = 0; i < delims.size(); ++i) {
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

        if (pos_start >= str.size())
            return output;
    
        if (str.substr(pos_start).size())
            output.push_back(str.substr(pos_start));

        return output;
    }

    std::string Manager::str() const
    {
        return make_str("No attributes");
    }
}