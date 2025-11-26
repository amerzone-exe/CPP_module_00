/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:41:04 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/26 16:26:32 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"

#include <iostream>
#include <string>
#include <cstring>

int main(void)
{
	std::string input;
	PhoneBook list;
	int contact_index;
	int count = -1;
	int i = 0;
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
			if (list.add_contact(count))
				continue;
		}
		else if (!input.compare("SEARCH"))
		{
			list.print_phonebook_list(count);
			std::cout << "Contact details (enter a number): ";
			std::cin >> contact_index;
			if (contact_index > 0 && contact_index < 9 && contact_index <= count + 1)
			{
				contact_index -= 1;
				list.print_contact(contact_index);
			}
			else
				std::cout << "This contact doesn't exist" << std::endl;
		}
		else if (!input.compare("EXIT"))
			end = true;
		i++;
	}
	return (0);
}
