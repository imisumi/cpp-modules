/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:48 by ichiro            #+#    #+#             */
/*   Updated: 2024/04/16 16:33:06 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>

#include "constants.h"
#include "Contact.h"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void	addContact(void);
	void	displayContacts(void);
	int		getContactCount(void) const;
	void	printContactInfo(int index) const;

private:
	Contact	m_contacts[MAX_CONTACTS];
	int		m_contactCount;
};
