#include "parser.hpp"
#include <iostream>
#include <string>

int main() {
    while(1) 
    {
        std::string text;
        std::cout << "Enter your question (enter 'x' to exit): \n";

        getline(std::cin, text);
        if (text == "x") break; 

        std::cout << parser::parse(text);
    }
    
}