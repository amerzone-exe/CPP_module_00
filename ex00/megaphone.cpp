/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:36:43 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/09 10:11:55 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

/*Convert every lowercase character to uppercase of a string passed as parameter
using toupper function*/
std::string	toUppercase(std::string input) {
	for (size_t i = 0; i < input.length(); i++) 
	{
		input[i] = static_cast<char>(std::toupper(input[i]));
	}
	return (input);
}

int main(int ac, char **av) 
{
	if (!av[1])
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
	{
		std::string input = av[i];
		std::cout << toUppercase(input);
	}
	std::cout << std::endl;
	return (0);
}
