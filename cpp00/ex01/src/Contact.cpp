/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:30 by ichiro            #+#    #+#             */
/*   Updated: 2024/03/26 20:59:46 by imisumi-wsl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::setFirstName(const std::string& firstName)
{
	m_firstName = firstName;
}
void	Contact::setLastName(const std::string& lastName)
{
	m_lastName = lastName;
}
void	Contact::setNickname(const std::string& nickname)
{
	m_nickname = nickname;
}
void	Contact::setPhoneNumber(const std::string& phoneNumber)
{
	m_phoneNumber = phoneNumber;
}
void	Contact::setDarkestSecret(const std::string& darkestSecret)
{
	m_darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName(void) const
{
	return (m_firstName);
}

std::string	Contact::getLastName(void) const
{
	return (m_lastName);
}

std::string	Contact::getNickname(void) const
{
	return (m_nickname);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (m_phoneNumber);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (m_darkestSecret);
}

void	Contact::printContactInfo(void) const
{
	std::cout << BLUE << "First name: " << RESET << Contact::m_firstName << std::endl;
	std::cout << BLUE << "Last name: " << RESET << Contact::m_lastName << std::endl;
	std::cout << BLUE << "Nickname: " << RESET << Contact::m_nickname << std::endl;
	std::cout << BLUE << "Phone number: " << RESET << Contact::m_phoneNumber << std::endl;
	std::cout << BLUE << "Darkest secret: " << RESET << Contact::m_darkestSecret << std::endl;
}
