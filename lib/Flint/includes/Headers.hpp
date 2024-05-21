/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Sun, Apr, 2024                                                     *
 * Title           - CppLib                                                             *
 * Description     -                                                                    *
 *     headers                                                                          *
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

#ifndef INCLUDED_FLINT_HEADERS_HPP
    #define INCLUDED_FLINT_HEADERS_HPP

    #include <algorithm>
    #include <cmath>
    #include <cxxabi.h>
    #include <exception>
    #include <ext/stdio_filebuf.h>
    #include <filesystem>
    #include <initializer_list>
    #include <iostream>
    #include <map>
    #include <memory>
    #include <ostream>
    #include <sstream>
    #include <string>
    #include <sys/stat.h>
    #include <unordered_map>
    #include <unordered_set>
    #include <unistd.h>
    #include <utility>
    #include <vector>

namespace fs = std::filesystem;

// get break trace
#ifdef _WIN32
    #include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
    #include <execinfo.h>
#endif

#endif
