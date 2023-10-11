/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:47:41 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/11 19:37:48 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	try {
		Bureaucrat bure("Bure", 1);
		std::cout << bure << std::endl;
		AForm* form = new ShrubberyCreationForm("WTForm");
		bure.signForm(*form);
		bure.executeForm(*form);
		std::cout << *form << std::endl;
		delete form;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: Unable to create Bureaucrat: " << e.what() << std::endl; 
	}
	return 0;
}
