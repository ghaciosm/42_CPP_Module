/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:11:47 by ghaciosm          #+#    #+#             */
/*   Updated: 2023/03/18 13:11:50 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
            std::cout << std::setw(9) << s.substr(0,9) << "." << "|";
      else
            std::cout << std::setw(10) << s << "|";
}

int   num_check(std::string s)
{
      int i = 0;

      while(s[i])
      {
            if (std::isdigit(s[i]) == 0)
                  return (1);
            i++;
      }
      return(0);
}

void  search_func(PhoneBook  *phonebook)
{
      int i = 0;
      std::string s;
      int index;
      int count = phonebook->id;
      if (count > 8)
            count = 8;
      std::cout << "|----------|----------|----------|----------|\n";
      std::cout << "|    ID    |   NAME   |  SURNAME | NICKNAME |\n";
      std::cout << "|----------|----------|----------|----------|\n";
      while(i < count)
      {
            std::cout << "|"<< std::setw(10) << i<< "|";
            correct_func(phonebook->contacts[i].name);
            correct_func(phonebook->contacts[i].surname);
            correct_func(phonebook->contacts[i].nickname);
            std::cout << "\n|----------|----------|----------|----------|\n";
            i++;
      }
      if(phonebook->id == 0)
            std::cout << "\nNo one has been added yet!!!\n";
      else
      {
            std::cout << "\nEnter the number : \n";
            std::cin >> s;
            if (num_check(s))
            {
                  std::cout << "\nYou entered an invalid index!!!\n";
                  return ;
            }
            index = std::stoi(s);
            if(index >= 0 && (index < count))
            {
                  std::cout << "Name : " << phonebook->contacts[index].name << std::endl;
                  std::cout << "Surname : " << phonebook->contacts[index].surname << std::endl;
                  std::cout << "Nickname : " << phonebook->contacts[index].nickname << std::endl;
                  std::cout << "Phone number : " << phonebook->contacts[index].phone_num << std::endl;
                  std::cout << "Dark Secret : " << phonebook->contacts[index].dark_secret << std::endl;
            }
            else
                  std::cout << "\nYou entered an invalid index!!!\n";
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
                  std::cout << "Invalid command!!!!\n";
      }
}
