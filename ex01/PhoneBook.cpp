/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:24:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/20 18:28:26 by jpiquet          ###   ########.fr       */
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

Contact PhoneBook::create_contact(int index) {

	Contact person;
	person.index = index;
	std::cout << "First name : ";
	std::getline(std::cin, person.first_name);
	std::cout << "Last name : ";
	std::getline(std::cin, person.last_name);
	std::cout << "Nickname : ";
	std::getline(std::cin, person.nickname);
	std::cout << "Phone number : ";
	std::getline(std::cin, person.phone_number);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, person.dark_secret);
	return (person);
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
void	PhoneBook::add_contact(PhoneBook *list, int *count) {

	if (*count > 8)
		*count = 7;
	if (*count > 1)
		shift_array(list->people, *count);
	list->people[0] = create_contact(1);
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
		std::cout << list->people[i].index
		<< " | " << list->_resize_input(list->people[i].first_name) 
		<< " | " << list->_resize_input(list->people[i].last_name)
		<< " | " << list->_resize_input(list->people[i].nickname) << std::endl;
		i++;
	}
}

/*Print a selected contact with all of the informations*/
void	PhoneBook::print_contact(PhoneBook *list, int index) const {
	std::cout << "//------------DETAILS------------//" << std::endl;
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
