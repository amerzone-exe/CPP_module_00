/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:24:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/20 13:14:30 by jpiquet          ###   ########.fr       */
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
	std::cin >> person.first_name;
	std::cout << "Last name : ";
	std::cin >> person.last_name;
	std::cout << "Nickname : ";
	std::cin >> person.nickname;
	std::cout << "Phone number : ";
	std::cin >> person.phone_number;
	std::cout << "Darkest secret : ";
	std::cin >> person.dark_secret;
	return (person);
}

void	PhoneBook::shift_array(Contact *people) {
	int i = 7;

	while (i > 0) {
		people[i] = people[i - 1];
		i--;
	}
}

void	PhoneBook::add_contact(PhoneBook *list, int count) {
	int index;

	if (count <= 8)
		index = count;
	else
	{
		shift_array(list->people);
		index = 1;
	}
	list->people[index] = create_contact(index);
}

void	PhoneBook::print_phonebook_list(PhoneBook *list) const {

	int i = 0;

	while (i < 8)
	{
		std::cout << list->people[i].index << " | " << list->people[i].first_name 
		<< " | " << list->people[i].last_name << " | " << list->people[i].nickname << std::endl;
		i++;
	}
}

void	PhoneBook::print_contact(PhoneBook *list, int index) const {
		std::cout << "First name : " << list->people[index].first_name << std::endl;
		std::cout << "Last name : " << list->people[index].last_name << std::endl;
		std::cout << "Nickname : " << list->people[index].nickname << std::endl;
		std::cout << "Phone number : " << list->people[index].phone_number << std::endl;
		std::cout << "Darkest secret : " << list->people[index].dark_secret << std::endl;
}
