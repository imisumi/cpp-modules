/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi-wsl <imisumi-wsl@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:52 by ichiro            #+#    #+#             */
/*   Updated: 2024/03/26 21:00:31 by imisumi-wsl      ###   ########.fr       */
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

	void	setFirstName(const std::string& firstName);
	void	setLastName(const std::string& lastName);
	void	setNickname(const std::string& nickname);
	void	setPhoneNumber(const std::string& phoneNumber);
	void	setDarkestSecret(const std::string& darkestSecret);

	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

	void	printContactInfo(void) const;

private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickname;
	std::string	m_phoneNumber;
	std::string	m_darkestSecret;
};

