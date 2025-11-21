/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:32:46 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/21 11:15:38 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact_class.hpp"

class PhoneBook {

public :

	Contact people[8];

	PhoneBook(void); /*Peut-etre initialiser les contacts dans le constructeur*/
	~PhoneBook(void);

	void	print_phonebook_list(PhoneBook *list, int count) const;
	void	print_contact(PhoneBook *list, int index) const;
	int		add_contact(PhoneBook *list, int *count);

private :

	int		create_contact(Contact *person, int count);
	void	shift_array(Contact *people, int count);

	std::string _resize_input(std::string input);
};

#endif
