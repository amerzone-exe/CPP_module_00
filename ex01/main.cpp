/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:41:04 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/20 13:25:17 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_class.hpp"
#include "PhoneBook_class.hpp"
#include <iostream>
#include <string>
#include <cstring>
#include <unistd.h>

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
	int 		count = 1;
	bool		end = false;
	/*Peut etre déclarer une variable compteur qui permet de savoir ou on en est dans l'ajout de contact*/
	while (end != true)
	{
		std::cout << ">>";
		std::cin >> input;
		input = to_uppercase(input);
		if (!input.compare("ADD"))
		{
			list.add_contact(&list, count);
			// std::cout << "New contact added" << std::endl;
			count++;
			// continue;
		}
		else if (!input.compare("SEARCH")) {
			list.print_phonebook_list(&list);
			std::cout << "Contact you need more details on (enter a number): " << std::endl;
			std::cin >> contact_index;
			if (contact_index < 0 || contact_index > 8)
			{
				/*afficher le contact en détail*/
				list.print_contact(&list, contact_index);
			}
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
