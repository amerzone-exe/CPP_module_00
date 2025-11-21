/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:36:43 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/21 13:26:20 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

char	*to_uppercase(char *str) {
	for (size_t i = 0; i < strlen(str); i++) {
		str[i] = toupper(static_cast<char>(str[i]));
	}
	return (str);
}

int main(int ac, char **av) {
	if (!av[1]) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++) {
		std::cout << to_uppercase(av[i]);
	}
	std::cout << std::endl;
	return (0);
}
