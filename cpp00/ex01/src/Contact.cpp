/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:30 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/28 16:57:33 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact()
{

}

Contact::~Contact()
{

}

void	Contact::printContactInfo(void) const
{
	std::cout << BLUE << "First name: " << RESET << Contact::m_firstName << std::endl;
	std::cout << BLUE << "Last name: " << RESET << Contact::m_lastName << std::endl;
	std::cout << BLUE << "Nickname: " << RESET << Contact::m_nickname << std::endl;
	std::cout << BLUE << "Phone number: " << RESET << Contact::m_phoneNumber << std::endl;
	std::cout << BLUE << "Darkest secret: " << RESET << Contact::m_darkestSecret << std::endl;
}