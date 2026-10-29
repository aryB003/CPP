#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook   phone_book;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command))
        {
            std::cout << std::endl;
            break;
        }
        if (command == "ADD")
            phone_book.addContact();
        else if (command == "SEARCH")
            phone_book.searchContact();
        else if (command == "EXIT")
            break;
    }
    return (0);
}
