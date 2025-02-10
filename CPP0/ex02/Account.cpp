/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebioda <llebioda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 09:43:55 by llebioda          #+#    #+#             */
/*   Updated: 2025/01/30 12:11:23 by llebioda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "Account.hpp"

int 	Account::_nbAccounts = 0;
int 	Account::_totalAmount = 0;
int 	Account::_totalNbDeposits = 0;
int 	Account::_totalNbWithdrawals = 0;

Account::Account(void) : _accountIndex(_nbAccounts++), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(int initial_deposit) : _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::_displayTimestamp(void)
{
	time_t now;
	char buffer[24];

	time(&now);
	strftime(buffer, 24, "[%Y%m%d_%H%M%S] ", localtime(&now));
	std::cout << buffer;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
			<< ";total:" << getTotalAmount()
			<< ";deposits:" << getNbDeposits()
			<< ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;

	_totalNbDeposits++;
	_nbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << p_amount
			<< ";deposit:" << deposit
			<< ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	int p_amount = _amount;

	_displayTimestamp();
	if (withdrawal <= _amount)
	{
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;

		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;

		return true;
	}
	else
	{
		std::cout << "index:" << _accountIndex
				<< ";p_amount:" << p_amount
				<< ";withdrawal:refused" << std::endl;
	}
	return false;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";deposits:" << _nbDeposits
			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

