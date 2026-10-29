#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
    private:
        Contact     _contacts[MAX_CONTACTS];
        int         _next_index;
        int         _contact_count;

    public:
        PhoneBook();

        void addContact();
        void searchContact() const;
};

#endif
