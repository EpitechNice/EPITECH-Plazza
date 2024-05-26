/*                                                                                      *
 * EPITECH PROJECT - Sun, May, 2024                                                     *
 * Title           - EPITECH-Plazza                                                     *
 * Description     -                                                                    *
 *     Thread                                                                           *
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

#ifndef THREAD_HPP
    #define THREAD_HPP

    #include "includes.hpp"

namespace Plazza
{
    class Thread
    {
        private:
            std::thread _thread;
            bool _running;

        public:
            Thread();
            ~Thread();

            void start(void (*function)(void));
            void join();
            bool joinable() const;
    };

    template <typename T>
    class SelfThread
    {
        private:
            std::thread _thread;
            bool _running;

        public:
            SelfThread()
            {
                this->_running = false;
            }

            ~SelfThread()
            {
                this->join();
            }


            void start(void (*function)(T* self), T* self)
            {
                if (!this->_running) {
                    this->_running = true;
                    this->_thread = std::thread(function, self);
                }
            }
            void join()
            {
                if (this->_running && this->_thread.joinable()) {
                    this->_thread.join();
                    this->_running = false;
                }
            }

            bool joinable() const
            {
                return this->_thread.joinable();
            }

    };
}

#endif
