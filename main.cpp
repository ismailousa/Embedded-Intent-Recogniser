#include <regex>
#include <iostream>
#include <string>

#define weatherRgx std::regex("\\b(weather|rain\\w*|wind\\w*|snow\\w*|sun\\w*|cloud\\w*|humid\\w*|hot|cold|temperature)\\b")
#define cityRgx std::regex("in [A-Z]\\w+")
#define calendarRgx std::regex("(([0-1]?[0-9]|2[0-3]):[0-5][0-9]|free|available|appointment|meeting|calendar)")
#define factRgx std::regex("([Tt]ell|[Ff]act)")

void parse(std::string text) {
    if (std::regex_search(text, weatherRgx))
        if (std::regex_search(text, cityRgx))
            std::cout << "Intent: Get Weather City\n\n";
        else
            std::cout << "Intent: Get Weather\n\n";
    else if (std::regex_search(text, calendarRgx))
        std::cout << "Intent: Check Calendar\n\n";
    else if (std::regex_search(text, factRgx))
        std::cout << "Intent: Get Fact\n\n";
    else
        std::cout << "Intent not understood\n\n";
}

int main() {
    while(1) 
    {
        std::string text;
        std::cout << "Enter your question (enter 'x' to exit): \n";

        getline(std::cin, text);
        if (text == "x") break; 

        parse(text);
    }
    
}