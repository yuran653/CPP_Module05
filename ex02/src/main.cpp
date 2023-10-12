/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:47:41 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/12 19:02:30 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	onHeap(int sign_grade, int exec_grade) {
	try {
		if (sign_grade < 1)
			throw std::invalid_argument("Sign grade is too high");
		if (exec_grade < 1)
			throw std::invalid_argument("Execute grade is too high");
		if (sign_grade > 150)
			throw std::invalid_argument("Sign grade is too low");
		if (exec_grade > 150)
			throw std::invalid_argument("Execute grade is too low");
		Bureaucrat* sign_bure = new Bureaucrat("Signer", sign_grade);
		std::cout << std::endl << *sign_bure << std::endl;
		Bureaucrat* exec_bure = new Bureaucrat("Executor", exec_grade);
		std::cout << std::endl << *exec_bure << std::endl << std::endl;
		AForm* shru = new ShrubberyCreationForm("ShruHeapTarget");
		AForm* robo = new RobotomyRequestForm("RoboHeapTarget");
		AForm* pres = new PresidentialPardonForm("PresHeapTarget");
		sign_bure->signForm(*shru);
		std::cout << *shru << std::endl;
		shru->execute(*exec_bure);
		std::cout << std::endl;
		sign_bure->signForm(*robo);
		std::cout << *robo << std::endl;
		robo->execute(*exec_bure);
		std::cout << std::endl;
		sign_bure->signForm(*pres);
		std::cout << *pres << std::endl;
		pres->execute(*exec_bure);
		std::cout << std::endl;
		for (; sign_grade > pres->getSignGrade(); sign_grade--)
			sign_bure->incrementGrade();
		std::cout << *sign_bure << std::endl;
		for (; exec_grade > pres->getExecGrade(); exec_grade--)
			exec_bure->incrementGrade();
		std::cout << std::endl << *exec_bure << std::endl << std::endl;
		sign_bure->signForm(*pres);
		std::cout << *pres << std::endl;
		pres->execute(*exec_bure);
		std::cout << std::endl;
		delete sign_bure;
		delete exec_bure;
		delete shru;
		delete robo;
		delete pres;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: Unable to create Bureaucrat: " << e.what() << std::endl;
	}
}

void	onStack(int sign_grade, int exec_grade) {
	try {
		Bureaucrat sign_bure("Signer", sign_grade);
		std::cout << std::endl << sign_bure << std::endl;
		Bureaucrat exec_bure("Executor", exec_grade);
		std::cout << std::endl << exec_bure << std::endl << std::endl;
		ShrubberyCreationForm shru("ShruStackTarget");
		RobotomyRequestForm robo("RoboStackTarget");
		PresidentialPardonForm pres("PresStackTarget");
		sign_bure.signForm(shru);
		std::cout << shru << std::endl;
		shru.execute(exec_bure);
		std::cout << std::endl;
		sign_bure.signForm(robo);
		std::cout << robo << std::endl;
		robo.execute(exec_bure);
		std::cout << std::endl;
		sign_bure.signForm(pres);
		std::cout << pres << std::endl;
		pres.execute(exec_bure);
		std::cout << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error: Unable to create Bureaucrat: " << e.what() << std::endl; 
	}
}

int	main() {
	onStack(25, 45);
	onHeap(72, 5);
	return 0;
}
