/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:24:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/21 13:24:07 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook_class.hpp"
#include "Contact_class.hpp"
#include <iostream>


PhoneBook::PhoneBook(void) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

bool	phone_number_is_valid(std::string phone_number) {
	int i = 0;

	while (phone_number[i])
	{
		if (!isdigit(phone_number[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	name_is_valid(std::string name) {
	int i = 0;

	while (name[i])
	{
		if (!isalpha(name[i]))
			return (false);
		i++;
	}
	return (true);
}

// Contact PhoneBook::create_contact(int index) {

// 	Contact person;
// 	person.index = index;

// 	std::cout << "First name : ";
// 	std::getline(std::cin, person.first_name);
// 	if (name_is_valid(person.first_name) == false)
// 		std::cout << "Invalid first name" << std::endl;

// 	std::cout << "Last name : ";
// 	std::getline(std::cin, person.last_name);
// 	if (name_is_valid(person.last_name) == false)
// 		std::cout << "Invalid last name" << std::endl;

// 	std::cout << "Nickname : ";
// 	std::getline(std::cin, person.nickname);

// 	std::cout << "Phone number : ";
// 	std::getline(std::cin, person.phone_number);
// 	if (phone_number_is_valid(person.phone_number) == false)
// 		std::cout << "Invalid phone number" << std::endl;

// 	std::cout << "Darkest secret : ";
// 	std::getline(std::cin, person.dark_secret);
// 	return (person);
// }

/*Get the data for a contact and check data, return 1 if there is an error*/
int PhoneBook::create_contact(Contact *person, int index) {

	person->index = index;

	std::cout << "First name : ";
	std::getline(std::cin, person->first_name);
	if (name_is_valid(person->first_name) == false) {
		std::cout << "Invalid first name" << std::endl;
		return (1);
	}
	std::cout << "Last name : ";
	std::getline(std::cin, person->last_name);
	if (name_is_valid(person->last_name) == false) {
		std::cout << "\033[31mInvalid last name\033[m" << std::endl;
		return (1);
	}
	std::cout << "Nickname : ";
	std::getline(std::cin, person->nickname);

	std::cout << "Phone number : ";
	std::getline(std::cin, person->phone_number);
	if (phone_number_is_valid(person->phone_number) == false) {
		std::cout << "Invalid phone number" << std::endl;
		return (1);
	}

	std::cout << "Darkest secret : ";
	std::getline(std::cin, person->dark_secret);
	return (0);
}

/*Shift all contact to pass the first contact to the 2nd and delete the last*/
void	PhoneBook::shift_array(Contact *people, int max) {
	int i = max;

	while (i > 0) {
		people[i] = people[i - 1];
		people[i].index = i + 1;
		i--;
	}
}

// /*Add a new contact to the Phonebook*/
// void	PhoneBook::add_contact(PhoneBook *list, int count) {
// 	int index;

// 	if (count <= 8)
// 		index = count;
// 	else
// 	{
// 		shift_array(list->people);
// 		index = 1;
// 	}
// 	list->people[index - 1] = create_contact(index);
// }

/*Add a new contact to the Phonebook*/
int	PhoneBook::add_contact(PhoneBook *list, int *count) {

	if (*count > 8)
		*count = 7;
	if (*count > 1)
		shift_array(list->people, *count);
	if (create_contact(&list->people[0], 1))
		return (1);
	return (0);
	// list->people[0] = create_contact(1);
}

/*Print the phonebook entierly*/
void	PhoneBook::print_phonebook_list(PhoneBook *list, int count) const {

	int i = 0;
	int max;

	if (count > 8)
		max = 8;
	else
		max = count;
	while (i < max) {
		std::cout << "\033[1;4;31m            INDEX            \033[m" << std::endl;;
		std::cout << list->people[i].index
		<< " | " << list->_resize_input(list->people[i].first_name) 
		<< " | " << list->_resize_input(list->people[i].last_name)
		<< " | " << list->_resize_input(list->people[i].nickname) << std::endl;
		i++;
	}
}

/*Print a selected contact with all of the informations*/
void	PhoneBook::print_contact(PhoneBook *list, int index) const {
	std::cout << "\033[1;4;31m            DETAILS           \033[m" << std::endl;
	std::cout << "First name : " << list->people[index].first_name << std::endl;
	std::cout << "Last name : " << list->people[index].last_name << std::endl;
	std::cout << "Nickname : " << list->people[index].nickname << std::endl;
	std::cout << "Phone number : " << list->people[index].phone_number << std::endl;
	std::cout << "Darkest secret : " << list->people[index].dark_secret << std::endl;
}

/*Resize the input to make it 10 size long
if the input size is more than 10, truncate it and
replace the last character by a "."*/
std::string PhoneBook::_resize_input(std::string input) {
	if (input.length() != 10) {
		if (input.length() > 10)
		{
			input.resize(10, ' ');
			input.replace(9, 1, ".");   
		}
		else {
			input.resize(10, ' ');
		}
	}
	return (input);
}
