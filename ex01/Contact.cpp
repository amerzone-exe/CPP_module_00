/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:22:58 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/20 13:25:22 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact_class.hpp"
#include <iostream>
#include <string>

Contact::Contact(void) {
	// std::cout << "Constructor done" << std::endl;
	return;
}

Contact::~Contact(void) {
	// std::cout << "Destructor done" << std::endl;
	return;
}

/*void	get_data(int index) {
	
}*/

void Contact::_resize_input(std::string *input) {
	if (input->length() != 10) {
		if (input->length() > 10)
		{
			input->resize(10);
			input->replace(9, 1, ".");   
		}
		else {
			input->resize(10);
		}
	}
}
