/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiquet <jpiquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 17:52:37 by jpiquet           #+#    #+#             */
/*   Updated: 2025/12/12 10:05:49 by jpiquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

Account::Account(void)
{
	return;
}

/*Constructor that make an initial deposit in order to create an account
and add this initial deposit to the total amount*/
Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_displayTimestamp();

	this->_accountIndex = Account::_nbAccounts;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";created" << std::endl;

	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	return;
}

/*Destructor that display a message for closing account*/
Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount << ";closed" << std::endl;
	return ;
}

/*Get private informations*/
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
 
/* Get the time and put it in the same format as the original log 
%Y (year) , %m (month), %d(days), %I (hours), %M (minutes), %S (seconds)*/
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

/*Display informations about an account*/
void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
	<< ";amount:" << this->_amount
	<< ";deposits:" << this->_nbDeposits
	<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

/*Return the amount of money that is available on an account*/
int	Account::checkAmount(void) const
{
	return this->_amount;
}

/*Add deposit to actual amount and to total amount*/
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
	<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

/*Make a withdrawal on an account, verify if it'spossible and display either a refusal message
or the state of the account after the withdrawal*/
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

/*Display gobal infomation about all the accounts*/
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}

/*Initialization for static variables*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
