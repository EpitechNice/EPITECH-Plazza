/*        ./User/User.hpp""                                                                     *
 * EPITECH.gitignore"/Manue, May, 2024                                                     *
 * Title           - Visual Studio Live Share (Workspace)                               *
 * Description     -                                                                    *
 *     Main                                                                             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  *
 *                                                                                      *
 *         ░        ░       ░░        ░        ░        ░░      ░░  ░░░░  ░             *
 *         ▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒▒▒▒▒▒▒  ▒▒▒▒  ▒  ▒▒▒▒  ▒             *
 *         ▓      ▓▓▓       ▓▓▓▓▓  ▓▓▓▓▓▓▓  ▓▓▓▓      ▓▓▓  ▓▓▓▓▓▓▓        ▓             *
 *         █  ███████  ██████████  ███████  ████  ███████  ████  █  ████  █             *
 *         █        █  ███████        ████  ████        ██      ██  ████  █             *
 *                                                                                      *
 * -----------------------------------------------------------------------------------  */

    #include "includes.hpp"
    #include "Core/Core.hpp"

int main(int argc, char** argv)
{
    try {
        Plazza::Core core(argc, argv);
    } catch (const Flint::Exceptions::Exception& e) {
        std::cerr << e << std::endl;
        return 84;
    }
    return 0;
}
