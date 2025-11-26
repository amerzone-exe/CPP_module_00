/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:24:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/26 16:31:30 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

/*PhoneBook constructor*/
PhoneBook::PhoneBook(void)
{
	return;
}

/*PhoneBook destructor*/
PhoneBook::~PhoneBook(void)
{
	return;
}

/*Get the data for a contact and check data, return 1 if there is an error*/
void PhoneBook::create_contact(void)
{
	std::string first_name, last_name, nickname, phone_number, dark_secret;

	std::cout << "First name : ";
	if (!std::getline(std::cin, first_name))
		throw(1);
	else if (first_name.empty())
		throw(2);

	std::cout << "Last name : ";
	if (!std::getline(std::cin, last_name))
		throw(1);
	else if (last_name.empty())
		throw(2);

	std::cout << "Nickname : ";
	if (!std::getline(std::cin, nickname))
		throw(1);
	else if (nickname.empty())
		throw(2);

	std::cout << "Phone number : ";
	if (!std::getline(std::cin, phone_number))
		throw(1);
	else if (phone_number.empty())
		throw(2);

	std::cout << "Darkest secret : ";
	if (!std::getline(std::cin, dark_secret))
		throw(1);
	else if (dark_secret.empty())
		throw(2);
	this->people[0].set_contact(1, first_name, last_name, nickname, phone_number, dark_secret);
}

/*Shift all contact to pass the first contact to the 2nd and delete the last*/
void PhoneBook::shift_array(int max)
{
	for (int i = max; i > 0; i--)
	{
		this->people[i] = this->people[i - 1];
		this->people[i].change_index(i + 1);
	}
}

/*Add a new contact to the Phonebook*/
int PhoneBook::add_contact(int &count)
{

	if (count > 7)
		count = 7;
	if (count > 0)
		shift_array(count);
	try
	{
		create_contact();
	}
	catch (int error)
	{
		switch (error)
		{
		case (1):
			break;
		case (2):
			std::cout << "Can't be empty" << std::endl;
			break;
		}
	}
	return 0;
}

/*Print the phonebook entierly*/
void PhoneBook::print_phonebook_list(int count) const
{
	int max;

	if (count > 7)
		max = 7;
	else
		max = count;
	for (int i = 0; i <= max; i++)
	{
		std::cout << "\033[1;4;31m            INDEX            \033[m" << std::endl;
		std::cout << this->people[i].get_index()
				  << " | " << resize_input(this->people[i].get_first_name())
				  << " | " << resize_input(this->people[i].get_last_name())
				  << " | " << resize_input(this->people[i].get_nickname()) << std::endl;
	}
}

/*Print a selected contact with all of the informations*/
void PhoneBook::print_contact(int index) const
{
	std::cout << "\033[1;4;31m            DETAILS           \033[m" << std::endl;
	std::cout << "First name : " << this->people[index].get_first_name() << std::endl;
	std::cout << "Last name : " << this->people[index].get_last_name() << std::endl;
	std::cout << "Nickname : " << this->people[index].get_nickname() << std::endl;
	std::cout << "Phone number : " << this->people[index].get_phonenumber() << std::endl;
	std::cout << "Darkest secret : " << this->people[index].get_darkest_secret() << std::endl;
}
