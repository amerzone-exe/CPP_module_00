/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iomanip.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:41:44 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/11 11:53:37 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

int main()
{
	std::cout << std::setfill(' ') << std::setw(10) << 1 << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "salut" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "cava" << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "textoiuiosdfiusdf" << "|";
	return 0;
}
