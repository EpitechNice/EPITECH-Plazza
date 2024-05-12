/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Thu, May, 2024                                                     *
 * Title           - CppLib                                                             *
 * Description     -                                                                    *
 *     Preprocessor                                                                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *       ▄▀▀█▄▄▄▄  ▄▀▀▄▀▀▀▄  ▄▀▀█▀▄    ▄▀▀▀█▀▀▄  ▄▀▀█▄▄▄▄  ▄▀▄▄▄▄   ▄▀▀▄ ▄▄             *
 *      ▐  ▄▀   ▐ █   █   █ █   █  █  █    █  ▐ ▐  ▄▀   ▐ █ █    ▌ █  █   ▄▀            *
 *        █▄▄▄▄▄  ▐  █▀▀▀▀  ▐   █  ▐  ▐   █       █▄▄▄▄▄  ▐ █      ▐  █▄▄▄█             *
 *        █    ▌     █          █        █        █    ▌    █         █   █             *
 *       ▄▀▄▄▄▄    ▄▀        ▄▀▀▀▀▀▄   ▄▀        ▄▀▄▄▄▄    ▄▀▄▄▄▄▀   ▄▀  ▄▀             *
 *       █    ▐   █         █       █ █          █    ▐   █     ▐   █   █               *
 *       ▐        ▐         ▐       ▐ ▐          ▐        ▐         ▐   ▐               *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

#ifndef INCLUDED_FLINT_PREPROCESSOR_HPP
    #define INCLUDED_FLINT_PREPROCESSOR_HPP

#if defined(__GNUC__)
    #define __FUNCTION__ __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
    #define __FUNCTION__ __FUNCSIG__
#else
    #define __FUNCTION__ __func__
#endif

    #define __POSITION_INFOS__ {{std::string(__FILE__), __LINE__}, std::string(__FUNCTION__)}
    #define throw_exception(exception, message) throw(exception(message, __POSITION_INFOS__))
    #define catch_exception(exception) exception.show(__POSITION_INFOS__)

// Inspection
    #define display_attr(attribute) Flint::Colors::F_BLUE << #attribute << Flint::Colors::RESET << "=" << Flint::Colors::RED << this->attribute << Flint::Colors::RESET
    #define make_str(display) ({std::stringstream ss; ss << Flint::Colors::RESET << "<" << Flint::Colors::F_PURPLE << this->getClassName() << Flint::Colors::RESET << " at " << Flint::Colors::YELLOW << std::hex << this << std::dec << Flint::Colors::RESET << ": " << display << ">"; ss.str();})

#endif
