/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:52 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/28 16:57:53 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "constants.h"

class Contact
{
public:
	Contact();
	~Contact();

	void	setFirstName(const std::string& firstName) { m_firstName = firstName; }
	void	setLastName(const std::string& lastName) { m_lastName = lastName; }
	void	setNickname(const std::string& nickname) { m_nickname = nickname; }
	void	setPhoneNumber(const std::string& phoneNumber) { m_phoneNumber = phoneNumber; }
	void	setDarkestSecret(const std::string& darkestSecret) { m_darkestSecret = darkestSecret; }


	std::string	getFirstName(void) const { return (m_firstName); }
	std::string	getLastName(void) const { return (m_lastName); }
	std::string	getNickname(void) const { return (m_nickname); }
	std::string	getPhoneNumber(void) const { return (m_phoneNumber); }
	std::string	getDarkestSecret(void) const { return (m_darkestSecret); }

	void	printContactInfo(void) const;

private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickname;
	std::string	m_phoneNumber;
	std::string	m_darkestSecret;
};

