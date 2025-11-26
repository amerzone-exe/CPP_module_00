/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:22:58 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/26 16:23:25 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->index = 0;
	return;
}

Contact::~Contact(void) 
{
	return;
}

int	Contact::get_index(void) const
{
	return this->index;
}

std::string	Contact::get_first_name(void) const
{
	return this->first_name;
}

std::string	Contact::get_last_name(void) const
{
	return this->last_name;
}

std::string	Contact::get_nickname(void) const
{
	return this->nickname;
}

std::string	Contact::get_phonenumber(void) const
{
	return this->phone_number;
}

std::string	Contact::get_darkest_secret(void) const
{
	return this->dark_secret;
}

void	Contact::set_contact(int index, std::string f_name, std::string l_name, 
	std::string n_name, std::string phone, std::string darkest)
{
	this->index = index;
	this->first_name = f_name;
	this->last_name = l_name;
	this->nickname = n_name;
	this->phone_number = phone;
	this->dark_secret = darkest;
}

void	Contact::change_index(int new_index)
{
	this->index = new_index;
}
// Contact	Contact::create_contact(void)
// {
// 	this->index = 1;

// 	std::cout << "First name : ";
// 	if (!std::getline(std::cin, this->first_name))
// 		throw(1);
// 	else if (this->first_name.empty())
// 		throw(2);

// 	std::cout << "Last name : ";
// 	if (!std::getline(std::cin, this->last_name))
// 		throw(1);
// 	else if (this->last_name.empty())
// 		throw(2);

// 	std::cout << "Nickname : ";
// 	if (!std::getline(std::cin, this->nickname))
// 		throw(1);
// 	else if (this->nickname.empty())
// 		throw(2);

// 	std::cout << "Phone number : ";
// 	if (!std::getline(std::cin, this->phone_number))
// 		throw(1);
// 	else if (this->phone_number.empty())
// 		throw(2);

// 	std::cout << "Darkest secret : ";
// 	if (!std::getline(std::cin, this->dark_secret))
// 		throw(1);
// 	else if (this->dark_secret.empty())
// 		throw(2);
// 	return (this->)
// }
