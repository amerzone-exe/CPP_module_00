/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:32:46 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/04 10:02:30 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{

public:
	PhoneBook(void);
	~PhoneBook(void);

	void	printPhonebookList(int count) const;
	void	printContact(int index) const;
	void	addContact(int &count);

private:
	Contact	_people[8];
	void	_shiftArray(int max);
	void	_createContact();
};

#endif
