#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Contact::Contact() : _first_name(""), _last_name(""), _nickname(""),
    _phone_number(""), _darkest_secret("")
{
}

std::string Contact::promptField(const std::string &label)
{
    std::string line;

    while (true)
    {
        std::cout << label << ": ";
        if (!std::getline(std::cin, line))
        {
            std::cout << std::endl;
            std::exit(0);
        }
        if (!line.empty())
            return (line);
        std::cout << "This field cannot be empty. Please try again.\n";
    }
}

std::string Contact::truncate(const std::string &value)
{
    if (value.size() > 10)
        return (value.substr(0, 9) + ".");
    return (value);
}

void Contact::fill()
{
    _first_name = promptField("First name");
    _last_name = promptField("Last name");
    _nickname = promptField("Nickname");
    _phone_number = promptField("Phone number");
    _darkest_secret = promptField("Darkest secret");
}

void Contact::printSummary(int index) const
{
    std::cout << std::setw(10) << index << "|"
        << std::setw(10) << truncate(_first_name) << "|"
        << std::setw(10) << truncate(_last_name) << "|"
        << std::setw(10) << truncate(_nickname) << "\n";
}

void Contact::printDetails() const
{
    std::cout << "First Name:     " << _first_name << "\n";
    std::cout << "Last Name:      " << _last_name << "\n";
    std::cout << "Nickname:       " << _nickname << "\n";
    std::cout << "Phone Number:   " << _phone_number << "\n";
    std::cout << "Darkest Secret: " << _darkest_secret << "\n";
}
