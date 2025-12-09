/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:16:56 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/09 10:24:36 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{

private:
	int			_index;
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickName;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact(void);
	~Contact(void);

	int			getIndex(void) const;
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickname(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;

	void setContact(int index, std::string f_name, std::string l_name,
					 std::string n_name, std::string phone, std::string darkest);
	void changeIndex(int new_index);
};

#endif
