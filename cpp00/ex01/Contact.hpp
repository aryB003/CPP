#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

        static std::string promptField(const std::string &label);
        static std::string truncate(const std::string &value);

    public:
        Contact();

        void fill();
        void printSummary(int index) const;
        void printDetails() const;
};

#endif
