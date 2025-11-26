/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:26:26 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/26 16:31:43 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

std::string to_uppercase(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = toupper(static_cast<char>(str[i]));
	return (str);
}

/*Resize the input to make it 10 size long
if the input size is more than 10, truncate it and
replace the last character by a "."*/
std::string resize_input(std::string input)
{
	if (input.length() != 10) {
		if (input.length() > 10) {
			input.resize(10, ' ');
			input.replace(9, 1, ".");
		}
		else {
			input.resize(10, ' ');
		}
	}
	return (input);
}
