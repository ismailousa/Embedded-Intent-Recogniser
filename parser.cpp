#include <regex>
#include <string>
#include "parser.hpp"

#define weatherRgx std::regex("\\b(weather|rain\\w*|wind\\w*|snow\\w*|sun\\w*|cloud\\w*|humid\\w*|hot|cold|temperature)\\b")
#define cityRgx std::regex("in [A-Z]\\w+")
#define calendarRgx std::regex("(([0-1]?[0-9]|2[0-3]):[0-5][0-9]|free|available|appointment|meeting|calendar)")
#define factRgx std::regex("([Tt]ell|[Ff]act)")

std::string parser::parse(std::string text) {
    if (std::regex_search(text, weatherRgx))
        if (std::regex_search(text, cityRgx))
            return "Intent: Get Weather City\n\n";
        else
            return "Intent: Get Weather\n\n";
    else if (std::regex_search(text, calendarRgx))
        return "Intent: Check Calendar\n\n";
    else if (std::regex_search(text, factRgx))
        return "Intent: Get Fact\n\n";
    else
        return "Intent not understood\n\n";
}