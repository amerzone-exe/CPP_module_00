/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone_copy.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:36:43 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/19 13:11:57 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

std::string	to_uppercase(std::string input) {
	for (int i = 0; i < input.length(); i++) {
		input[i] = std::toupper(static_cast<unsigned char>(input[i]));
	}
	return (input);
}

int main(int ac, char **av) {
	if (!av[1]) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++) {
		std::string input = av[i];
		std::cout << to_uppercase(input);
	}
	std::cout << std::endl;
	return (0);
}
