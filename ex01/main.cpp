#include "contact.hpp"

void  add_func(PhoneBook *phonebook)
{
      std::cout << "\nName :";
      std::cin >> phonebook->contacts[phonebook->id % 8].name;
      std::cout << "\nSurname :";
      std::cin >> phonebook->contacts[phonebook->id % 8].surname;
      std::cout << "\nNickname :";
      std::cin >> phonebook->contacts[phonebook->id % 8].nickname;
      std::cout << "\nPhone number :";
      std::cin >> phonebook->contacts[phonebook->id % 8].phone_num;
      std::cout << "\nDark secret :";
      std::cin >> phonebook->contacts[phonebook->id % 8].dark_secret;
      std::cout << std::endl;
}

void correct_func(std::string s)
{
      if(s.length() > 10)
            std::cout << std::setw(10) << s.substr(0,9) << "." << "|";
      else
            std::cout << std::setw(10) << s << "|";
}

void  search_func(PhoneBook  *phonebook)
{
      int i = 0;
      int index;

      std::cout << "|----------|----------|----------|----------|\n";
      std::cout << "|    ID    |   NAME   |  SURNAME | NICKNAME |\n";
      std::cout << "|----------|----------|----------|----------|\n";

      while(i < phonebook->id)
      {
            std::cout << "|"<< std::setw(10) << i<< "|";
            correct_func(phonebook->contacts[i].name);
            correct_func(phonebook->contacts[i].surname);
            correct_func(phonebook->contacts[i].nickname);
            std::cout << "\n|----------|----------|----------|----------|\n";
            i++;
      }
      if(phonebook->id == 0)
            std::cout << "\n\033[95mNo one has been added yet!!!\033[0m\n";
      else
      {
            std::cout << "\n\033[95mEnter the number : \033[0m\n";
            std::cin >> index;
            if(index >= 0 && (index < phonebook->id))
            {
                  std::cout << "Name : " << phonebook->contacts[index].name << std::endl;
                  std::cout << "Surname : " << phonebook->contacts[index].surname << std::endl;
                  std::cout << "Nickname : " << phonebook->contacts[index].nickname << std::endl;
                  std::cout << "Phone number : " << phonebook->contacts[index].phone_num << std::endl;
                  std::cout << "Dark Secret : " << phonebook->contacts[index].dark_secret << std::endl;
            }
            else
                  std::cout << "\n\033[95mYou entered an invalid index!!!\033[0m\n";
      }
}

int main()
{
      PhoneBook   phonebook;
      std::string str;
      phonebook.id = 0;

      while(1)
      {
            std::cout << "\n\033[95mPLEASE SELECT A COMMAND -> (ADD, SEARCH, EXIT)\033[0m\n\n";
            std::cin >> str;
            if(str == "ADD")
            {
                  add_func(&phonebook);
                  phonebook.id++;
            }
            else if(str == "SEARCH")
                  search_func(&phonebook);
            else if(str == "EXIT")
                  break;
            else
                  std::cout << "\033[95mInvalid command!!!!\033[0m\n";
      }
}