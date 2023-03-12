#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class contact
{
      public:
            std::string name;
            std::string surname;
            std::string nickname;
            std::string phone_num;
            std::string dark_secret;
};

class PhoneBook
{
      public:
            contact     contacts[8];
            int         id;
};

#endif