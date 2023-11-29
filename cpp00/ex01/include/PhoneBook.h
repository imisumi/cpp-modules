/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:57:48 by ichiro            #+#    #+#             */
/*   Updated: 2023/11/28 16:57:49 by ichiro           ###   ########.fr       */
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
	int		getContactCount(void) const { return (m_contactCount); }
	void	printContactInfo(int index) const { m_contacts[index].printContactInfo(); }

private:
	Contact	m_contacts[MAX_CONTACTS];
	int		m_contactCount;
};
