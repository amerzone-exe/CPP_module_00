/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:52:37 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/04 09:21:23 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(void)
{
	return;
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_displayTimestamp();
	/*initialize instance*/
	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	/* display instance data*/
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created" << std::endl;

	/*update class data*/
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	return;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
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

/* %Y (year) , %m (month), %d(days), %I (hours), %M (minutes), %S (seconds)*/
void	Account::_displayTimestamp( void )
{
	time_t timestamp;
	struct tm *timeinfo;
	char buffer[19];
	time(&timestamp);
	timeinfo = localtime(&timestamp);
	strftime(buffer, 19, "[%Y%m%d_%I%M%S] ", timeinfo);
	std::cout << buffer;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposit:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int	Account::checkAmount(void) const
{
	return this->_amount;
}

/*add deposit to actual amount + total amount*/
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;

	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
	<< ";amount:" << this->_amount 
	<< ";nb_deposits" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";p_amount:" << this->_amount;

	if (withdrawal >= this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
	<< ";amount:" << this->_amount
	<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	return true;	
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

/*INTIALISATION*/

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
