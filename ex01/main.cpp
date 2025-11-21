/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:41:04 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/21 13:26:39 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_class.hpp"
#include "PhoneBook_class.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <stdio.h>

// void	print_contact(void)
// {
// 	Contact first(1);
// 	std::cout << first.index << " | " << first.first_name << " | " << first.last_name << " | " << first.nickname;
// }

std::string	to_uppercase(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		str[i] = toupper(static_cast<char>(str[i]));
	}
	return (str);
}

int main(void) {
	
	std::string input;
	PhoneBook	list;
	int			contact_index;
	int 		count = 0;
	bool		end = false;

	while (end != true)
	{
		std::cout << ">>";
		std::getline(std::cin, input);
		input = to_uppercase(input);
		if (!input.compare("ADD")) {
			count++;
			std::cout << "\033[1;4;31m            ADD-NEW            \033[m" << std::endl;
			if (list.add_contact(&list, &count))
				continue;
		}
		else if (!input.compare("SEARCH")) {

			list.print_phonebook_list(&list, count);
			std::cout << "Contact details (enter a number): ";
			std::cin >> contact_index;
			if (contact_index > 0 && contact_index < 9)
			{
				contact_index -= 1;
				list.print_contact(&list, contact_index);
			}
			else
				std::cout << "This contact doesn't exist";
		}
		else if (!input.compare("EXIT")) {
			std::cout << "End of program" << std::endl;
			end = true;
		}
		else
			std::cout << "Please enter ADD, SEARCH or EXIT" << std::endl;
	}
	return (0);
}
