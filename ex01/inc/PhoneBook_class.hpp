/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:32:46 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/20 13:13:24 by jpiquet          ###   ########.fr       */
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

	/*-----PROBABLEMENT PUBLIC----------*/

	/*fonction pour print le phone book en entier avec tous les contacts "en const car il ne modifie aucune valeur"*/ 
	void	print_phonebook_list(PhoneBook *list) const;

	/*fonction pour print un contact du phonebook ligne par ligne "en const car il ne modifie aucune valeur"*/
	void	print_contact(PhoneBook *list, int index) const;

	/*fonction pour crée le nouveau contact*/
	Contact create_contact(int count);

private :
	/*-----PROBABLEMENT EN PRIVE----------*/
	/*fonction pour ajouter un nouveau contact au phone book*/
	void	add_contact(PhoneBook *list, int count);
	/*fonction pour décaler tout le tableau de contact en rajoutant +1 a chaque en indice*/
	void	shift_array(Contact *people);
};

#endif
