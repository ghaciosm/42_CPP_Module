/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghaciosm <ghaciosm@student.42kocaeli.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:10:46 by ghaciosm          #+#    #+#             */
/*   Updated: 2023/03/18 13:11:05 by ghaciosm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int   main(int ac, char **av)
{
      int   i = 1;
      int   j = 0;
      if(ac == 1)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
      else
      {
            while(i < ac)
            {
                  j = 0;
                  while(av[i][j])
                  {
                        std::cout << (char)std::toupper(av[i][j]);
                        j++;
                  }
                  i++;
            }
      std::cout << std::endl;
      }
}
