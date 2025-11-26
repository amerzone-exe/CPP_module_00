/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:52:37 by jpiquet           #+#    #+#             */
/*   Updated: 2025/11/26 19:04:14 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(void)
{
	return;
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	Account::_totalAmount = initial_deposit;
	/*initialize*/
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts += 1;
	return;
}

Account::~Account(void)
{
	return;
}

int Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

/*add deposit to actual amount + total amount*/
void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal >= this->_amount)
	{
		std::cout << "withdrawal:refused";
		return false;
	}
	/*faire l'inverse pour le dépot*/
}

void Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << Account::_nbAccounts << ";"
			  << "total:" << Account::_totalAmount << ";"
			  << "deposits:" << Account::_totalNbDeposits << ";"
			  << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/*INTIALISATION*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
