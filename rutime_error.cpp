/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutime_error.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:12:49 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/11 13:36:36 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

void withdrawMoney(int balance, int amount) {
    if (amount > balance) {
        throw std::runtime_error("Insufficient funds to withdraw.");
    }
    balance -= amount;
    std::cout << "Withdrawn " << amount << ". Remaining balance: " << balance << std::endl;
}

int main() {
    int accountBalance = 100;
    int withdrawAmount = 101;
    
    try {
		std::cout << "Account balance: " << accountBalance << std::endl;
        std::cout << "Withdraw amount: " << withdrawAmount << std::endl;
        withdrawMoney(accountBalance, withdrawAmount);
        std::cout << "Withdraw: successful" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
