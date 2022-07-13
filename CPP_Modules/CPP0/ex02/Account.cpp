/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschwalm <cschwalm@students.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:42:25 by cschwalm          #+#    #+#             */
/*   Updated: 2022/07/12 12:47:20 by cschwalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts;
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "created" << std::endl;
	Account::_totalAmount += this->_amount;
	Account::_nbAccounts++;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "closed" << std::endl;
	_nbAccounts--;
}

int		Account::getNbAccounts()
{
	return (_nbAccounts);
}

int		Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int		Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

int		Account::getTotalAmount()
{
	return (_totalAmount);
}

int		Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:" << BLUE << this->_amount << RESET << ";";
	this->_amount += deposit;
	std::cout << "deposit:" << deposit << BLUE << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "nb_deposits:" << BLUE << this->_nbDeposits << RESET << ";" << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "p_amount:" << BLUE << this->_amount << RESET << ";";
	if (withdrawal > this->checkAmount())
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		this->_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		std::cout << "withdrawal:" << BLUE << withdrawal << RESET << ";";
		std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
		std::cout << "nb_withdrawals:" << BLUE << this->_nbWithdrawals << RESET ";" << std::endl;
		return (true);
	}
}

void	Account::displayStatus() const
{
	Account::_displayTimestamp();
	std::cout << "index:" << BLUE << this->_accountIndex << RESET << ";";
	std::cout << "amount:" << BLUE << this->_amount << RESET << ";";
	std::cout << "deposits:" << BLUE << this->_nbDeposits << RESET << ";";
	std::cout << "withdrawals:" << BLUE << this->_nbWithdrawals << RESET << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t time = std::time(0);
	std::tm *ltm = localtime(&time);
	std::cout << "[";
	std::cout << ltm->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_mon;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_hour;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_min;
	std::cout << std::setfill('0') << std::setw(2);
	std::cout << ltm->tm_sec;
	std::cout << "]";
}

void	Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << BLUE << getNbAccounts() << RESET << ";";
	std::cout << "total:"	 << BLUE << getTotalAmount() << RESET << ";";
	std::cout << "deposits:" << BLUE << _totalNbDeposits << RESET << ";";
	std::cout << "withdrawls:" << BLUE << _totalNbWithdrawals << RESET << ";" << std::endl;
}
