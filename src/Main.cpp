/*
** EPITECH PROJECT, 2024
** Cpp-Project-Template
** File description:
** main
*/

#include "includes.hpp"

void dosomething()
{
    doSomthingElse(12);
}

class SubclassShowcase: public Flint::Inspection<SubclassShowcase>
{
    private:
        std::string string = "Hello world";
        std::size_t bigNumber = ((std::size_t)-1);

    public:
        SubclassShowcase() {}

        std::string str() const
        {
            return make_str(display_attr(string) << ", " << display_attr(bigNumber));
        }
};

class SelfMirroringShowcase: public Flint::Inspection<SelfMirroringShowcase>
{
    private:
        int number = 7;
        SubclassShowcase subObject;

    public:
        SelfMirroringShowcase() {}

        std::string str() const
        {
            return make_str(display_attr(number) << ", " << display_attr(subObject));
        }

};

int main(int argc, char** argv)
{
    (void) argc;
    (void) argv;

    try {
        dosomething();
    } catch(const Flint::Exceptions::Exception& e) {
        std::cerr << catch_exception(e) << std::endl;
    }

    std::cout << std::endl;

    std::cout << Flint::Colors::HIGHLIGHTED << "Self mirroring showcase :" << Flint::Colors::RESET << std::endl;

    std::cout << std::endl;

    SelfMirroringShowcase object;

    std::cout << object << std::endl;
}
