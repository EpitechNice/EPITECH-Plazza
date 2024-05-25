/*                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Process                                                                          *
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

#include "Process.hpp"

namespace Plazza
{
    Process::Process() : _pid(0), _running(false)
    {
        this->_running = false;
        this->_pid = fork();
    }

    Process::~Process()
    {
        if (this->_running)
            this->killPid();
    }

    void Process::create(void)
    {
        if (this->_pid == -1) {
            std::cout << "Exception fork failed" << std::endl;
            return;
        }

        if (this->_pid == 0) {
            this->_running = true;
            this->_type = processType::CHILD;
        } else {
            this->_running = true;
            this->_type = processType::PARENT;
        }
    }

    void Process::wait(void)
    {
        if (this->_running) {
            if (waitpid(this->_pid, nullptr, 0) != 0) {
                std::cout << "Throw Exception" << std::endl;
                return;
            }
            this->_running = false;
        }
    }

    void Process::killPid(void)
    {
        if (this->_running){
            kill(this->_pid, SIGTERM);
            this->_running = false;
        }
    }
}