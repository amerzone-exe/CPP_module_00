/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:41:04 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/04 11:14:06 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

int main(void)
{
	std::string input;
	PhoneBook list;

	int contact_index;
	int count = -1;
	bool end = false;

	while (end != true)
	{
		std::cout << ">>";
		if (!std::getline(std::cin, input))
		{
			std::cout << "EOF reached" << std::endl;
			return (1);
		}
		input = to_uppercase(input);
		if (!input.compare("ADD"))
		{
			count++;
			std::cout << "\033[1;4;31m            ADD-NEW            \033[m" << std::endl;
			list.addContact(count);
		}
		else if (!input.compare("SEARCH"))
		{
			list.printPhonebookList(count);
			std::cout << "Contact details (enter a number): ";
			if (!std::getline(std::cin, input))
			{
				std::cout << "EOF reached" << std::endl;
				return (1);
			}
			if (input.empty())
				continue;
			contact_index = atoi(input.c_str());
			if (contact_index > 0 && contact_index < 9 && contact_index <= count + 1)
			{
				contact_index -= 1;
				list.printContact(contact_index);
			}
			else
				std::cout << "This contact doesn't exist" << std::endl;
		}
		else if (!input.compare("EXIT"))
			end = true;
	}
	return (0);
}
