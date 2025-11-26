/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:32:46 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/25 19:20:00 by jpiquet          ###   ########.fr       */
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

	void print_phonebook_list(int count) const;
	void print_contact(int index) const;
	int add_contact(int &count);

private:
	Contact people[8];
	void shift_array(int max);
	void create_contact();
};

#endif
