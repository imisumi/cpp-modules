/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:41 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/28 16:57:43 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"

PhoneBook::PhoneBook()
{
	m_contactCount = 0;
}

PhoneBook::~PhoneBook()
{

}

bool	isWhiteSpaceOnly(const std::string& str)
{
	for (char c : str)
	{
		if (!std::isspace(c))
			return (false);
	}
	return (true);
}

void	trimWhiteSpace(std::string& str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	str = str.substr(start, end - start + 1);
}

std::string getInput(const std::string& prompt)
{
	std::string	input;
	while (true)
	{
		std::cout << BLUE << prompt << RESET;
		std::getline(std::cin, input);
		if (isWhiteSpaceOnly(input))
		{
			std::cout << RED << "Invalid input." << RESET << std::endl;
			continue;
		}
		break ;
	}
	trimWhiteSpace(input);
	return (input);
}

void PhoneBook::addContact(void)
{
	Contact contact;

	std::string	input;
	contact.setFirstName(getInput("Enter first name: "));
	contact.setLastName(getInput("Enter last name: "));
	contact.setNickname(getInput("Enter nickname: "));
	contact.setPhoneNumber(getInput("Enter phone number: "));
	contact.setDarkestSecret(getInput("Enter darkest secret: "));

	for (int i = MAX_CONTACTS - 1; i > 0; i--)
	{
		m_contacts[i] = m_contacts[i - 1];
	}
	m_contacts[0] = contact;
	if (m_contactCount < MAX_CONTACTS)
		m_contactCount++;
}

std::string truncateText(const std::string& text, size_t columnWidth)
{
	if (text.length() > columnWidth)
	{
		std::string truncated = text.substr(0, columnWidth);
		truncated[columnWidth - 1] = '.';
		return (truncated);
	}
	else
	{
		return (text);
	}
}

void	PhoneBook::displayContacts(void)
{
	for (int i = 0; i < m_contactCount; i++)
	{
		std::cout << '|' << std::setw(10) << i;
		std::cout << '|' << std::setw(10) << truncateText(m_contacts[i].getFirstName(), 10);
		std::cout << '|' << std::setw(10) << truncateText(m_contacts[i].getLastName(), 10);
		std::cout << '|' << std::setw(10) << truncateText(m_contacts[i].getNickname(), 10);
		std::cout << '|' << std::endl;
	}
	std::cout << "---------------------------------------------" << std::endl;
}
