#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : _next_index(0), _contact_count(0)
{
}

void PhoneBook::addContact()
{
    _contacts[_next_index].fill();
    _next_index = (_next_index + 1) % MAX_CONTACTS;
    if (_contact_count < MAX_CONTACTS)
        _contact_count++;
    std::cout << "Contact added successfully.\n";
}

void PhoneBook::searchContact() const
{
    if (_contact_count == 0)
    {
        std::cout << "The phonebook is empty.\n";
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
        << std::setw(10) << "First Name" << "|"
        << std::setw(10) << "Last Name" << "|"
        << std::setw(10) << "Nickname" << "\n";
    for (int i = 0; i < _contact_count; i++)
        _contacts[i].printSummary(i);

    std::cout << "Enter the index of a contact to view (or leave empty to cancel): ";
    std::string input;
    if (!std::getline(std::cin, input))
    {
        std::cout << std::endl;
        std::exit(0);
    }
    if (input.empty())
        return;

    if (input.size() != 1 || input[0] < '0' || input[0] >= '0' + _contact_count)
    {
        std::cout << "Invalid index.\n";
        return;
    }
    _contacts[input[0] - '0'].printDetails();
}
