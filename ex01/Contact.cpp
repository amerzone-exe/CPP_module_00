/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:22:58 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/05 16:23:48 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->_index = 0;
}

Contact::~Contact(void) 
{
}

int	Contact::getIndex(void) const
{
	return this->_index;
}

std::string	Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string	Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string	Contact::getNickname(void) const
{
	return this->_nickName;
}

std::string	Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}

void	Contact::setContact(int index, std::string f_name, std::string l_name, 
	std::string n_name, std::string phone, std::string darkest)
{
	this->_index = index;
	this->_firstName = f_name;
	this->_lastName = l_name;
	this->_nickName = n_name;
	this->_phoneNumber = phone;
	this->_darkestSecret = darkest;
}

void	Contact::changeIndex(int new_index)
{
	this->_index = new_index;
}
