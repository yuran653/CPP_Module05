/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:44:35 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/08 14:37:47 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : _name(other._name), _grade(other._grade){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this == &other)
		return *this;
	const_cast<std::string&>(_name) = other._name;
	_grade = other._grade;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << "'s grade is: [" << obj.getGrade() << "]";
	return os;
}

std::string	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::incrementGrade() {
	_grade--;
}

void	Bureaucrat::decrementGrade() {
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("The grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("The grade is to low");
}
