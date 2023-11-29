/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:16 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/28 16:57:20 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.h"
#include "constants.h"

void	inputLoop()
{
	PhoneBook	phoneBook;
	std::string	input;

	std::cout << BOLD_TEXT << WELCOME << RESET << std::endl;
	while (true)
	{
		std::cout << CYAN << "Enter a command: " << RESET;
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
		{
			phoneBook.addContact();
		}
		else if (input == "SEARCH")
		{
			if (phoneBook.getContactCount() == 0)
			{
				std::cout << RED << "PhoneBook is empty." <<  RESET << std::endl;
				continue;
			}
			std::cout << BOLD_TEXT << HEADER << RESET << std::endl;
			phoneBook.displayContacts();
			while (true)
			{
				std::cout << CYAN << "Enter an index: " << RESET;
				std::getline(std::cin, input);
				if (input.length() == 1 && std::isdigit(input[0]) && std::stoi(input) < phoneBook.getContactCount())
				{
					phoneBook.printContactInfo(std::stoi(input));
					break ;
				}
				else
					std::cout << RED << "Invalid index." << RESET << std::endl;
			}
		}
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
	}
}

int	main(void)
{
	inputLoop();
	return (EXIT_SUCCESS);
}
