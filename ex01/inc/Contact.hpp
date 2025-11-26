/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:16:56 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/26 16:29:49 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>

class Contact
{

private:
	int index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string dark_secret;

public:
	Contact(void);
	~Contact(void);

	int			get_index(void) const;
	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phonenumber(void) const;
	std::string	get_darkest_secret(void) const;

	void set_contact(int index, std::string f_name, std::string l_name,
					 std::string n_name, std::string phone, std::string darkest);
	void change_index(int new_index);
};

#endif
