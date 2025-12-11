/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:24:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/11 15:18:25 by jpiquet          ###   ########.fr       */
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
void PhoneBook::_createContact(void)
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

	this->_people[0].setContact(1, first_name, last_name, nickname, phone_number, dark_secret);
}

/*Shift all contact to pass the first contact to the 2nd and delete the last*/
void PhoneBook::_shiftArray(int max)
{
	for (int i = max; i > 0; i--)
	{
		this->_people[i] = this->_people[i - 1];
		this->_people[i].changeIndex(i + 1);
	}
}

/*Add a new contact to the Phonebook*/
void PhoneBook::addContact(int &count)
{

	if (count > 7)
		count = 7;
	if (count > 0)
		_shiftArray(count);
	try
	{
		_createContact();
	}
	catch (int error)
	{
		switch (error)
		{
		case (1):
		{
			std::cout << "EOF reached" << std::endl;
			break;
		}
		case (2):
			std::cout << "Can't be empty" << std::endl;
			break;
		}
	}
}

/*Print the phonebook entierly*/
void PhoneBook::printPhonebookList(int count) const
{
	int max;

	if (count > 7)
		max = 7;
	else
		max = count;
	std::cout << "\033[1;4;31m                   INDEX                   \033[m" << std::endl;
	for (int i = 0; i <= max; i++)
	{
		std::cout << std::setfill(' ') << std::setw(10) << this->_people[i].getIndex()  << "|";

		print_input(this->_people[i].getFirstName());
		std::cout << "|";

		print_input(this->_people[i].getLastName());
		std::cout << "|";

		print_input(this->_people[i].getNickname());
		std::cout << std::endl;
	}
}

/*Print a selected contact with all of the informations*/
void PhoneBook::printContact(int index) const
{
	std::cout << "\033[1;4;31m                  DETAILS                  \033[m" << std::endl;
	std::cout << "First name     : " << this->_people[index].getFirstName() << std::endl;
	std::cout << "Last name      : " << this->_people[index].getLastName() << std::endl;
	std::cout << "Nickname       : " << this->_people[index].getNickname() << std::endl;
	std::cout << "Phone number   : " << this->_people[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << this->_people[index].getDarkestSecret() << std::endl;
}
