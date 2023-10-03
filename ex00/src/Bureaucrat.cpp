/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:44:35 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/03 19:44:01 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	try {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception& e) {
		std::cerr << "Unable to create bureaucrat " + _name + ": " << e.what() << std::endl;
	}
	// _grade = grade;
}

Bureaucrat::~Bureaucrat() {
}

// Bureaucrat(Bureaucrat& other);
		// ~Bureaucrat();

		// Bureaucrat& operator=(const Bureaucrat& other);
		// friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& ptr);

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("The grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is to low");
}

const std::string	Bureaucrat::getName() const {
	return (_name);
}
int	Bureaucrat::getGrade() {
	return (_grade);
}
		// void				incrementGrade();
		// void				decrementGrade();
		
		
