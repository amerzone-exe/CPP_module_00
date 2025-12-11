/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:26:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/11 15:07:48 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include <cctype>
#include <iomanip>

/*Convert every lowercase character to uppercase of a string passed as parameter
using toupper function*/
std::string	toUppercase(std::string input) {
	for (size_t i = 0; i < input.length(); i++) 
	{
		input[i] = static_cast<char>(std::toupper(input[i]));
	}
	return (input);
}

// /*Resize the input to make it 10 size long
// if the input size is more than 10, truncate it and
// replace the last character by a "."*/
// std::string resize_input(std::string input)
// {
// 	if (input.length() != 10) {
// 		if (input.length() > 10) {
// 			input.resize(10);
// 			input.replace(9, 1, ".");
// 		}
// 		else {
// 			input.resize(10, ' ');
// 		}
// 	}
// 	return (input);
// }

/*Resize the input to make it 10 size long
if the input size is more than 10, resize it and
replace the last character by a "."*/
std::string print_input(std::string input)
{
	if (input.length() > 10) 
	{
		input.resize(10);
		input.replace(9, 1, ".");
	}
	std::cout << std::setfill(' ') << std::setw(10) << input;
	return (input);
}
