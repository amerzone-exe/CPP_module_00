/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:24:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/24 18:35:56 by jpiquet          ###   ########.fr       */
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

	this->people[0].index = 1;

	std::cout << "First name : ";
	if (!std::getline(std::cin, this->people[0].first_name))
		throw(1);
	else if (this->people[0].first_name.empty())
		throw(2);

	std::cout << "Last name : ";
	if (!std::getline(std::cin, this->people[0].last_name))
		throw(1);
	else if (this->people[0].last_name.empty())
		throw(2);

	std::cout << "Nickname : ";
	if (!std::getline(std::cin, this->people[0].nickname))
		throw(1);
	else if (this->people[0].nickname.empty())
		throw(2);

	std::cout << "Phone number : ";
	if (!std::getline(std::cin, this->people[0].phone_number))
		throw(1);
	else if (this->people[0].phone_number.empty())
		throw(2);

	std::cout << "Darkest secret : ";
	if (!std::getline(std::cin, this->people[0].dark_secret))
		throw(1);
	else if (this->people[0].dark_secret.empty())
		throw(2);
}

/*Shift all contact to pass the first contact to the 2nd and delete the last*/
void PhoneBook::shift_array(int max)
{
	std::cout << "max = " << max << std::endl;
	for (int i = max; i > 0; i--)
	{
		this->people[i] = this->people[i - 1];
		this->people[i].index = i + 1;
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
		std::cout << this->people[i].index
				  << " | " << resize_input(this->people[i].first_name)
				  << " | " << resize_input(this->people[i].last_name)
				  << " | " << resize_input(this->people[i].nickname) << std::endl;
	}
}

/*Print a selected contact with all of the informations*/
void PhoneBook::print_contact(int index) const
{
	std::cout << "\033[1;4;31m            DETAILS           \033[m" << std::endl;
	std::cout << "First name : " << this->people[index].first_name << std::endl;
	std::cout << "Last name : " << this->people[index].last_name << std::endl;
	std::cout << "Nickname : " << this->people[index].nickname << std::endl;
	std::cout << "Phone number : " << this->people[index].phone_number << std::endl;
	std::cout << "Darkest secret : " << this->people[index].dark_secret << std::endl;
}
