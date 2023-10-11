/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:37:01 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/11 19:37:28 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, const int sign_grade, const int exec_grade)
	: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	if (sign_grade < 1 || exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (sign_grade > 150 || exec_grade > 150)
		throw AForm::GradeTooLowException();
	_signed = false;
}

AForm::AForm(AForm& other) : _name(other._name), _sign_grade(other._sign_grade),
	_exec_grade(other._exec_grade), _signed(other._signed) {
}

AForm::~AForm() {
}

AForm& AForm::operator=(const AForm& other) {
	if (this == &other)
		return *this;
	const_cast<std::string&>(_name) = other._name;
	const_cast<int&>(_sign_grade) = other._sign_grade;
	const_cast<int&>(_exec_grade) = other._exec_grade;
	_signed = other._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "Form name: [" << obj.getName() << "]" << std::endl
		<< "Required sign grade: [" << obj.getSignGrade() << "]" << std::endl
		<< "Required execute grade: [" << obj.getExecGrade() << "]" << std::endl
		<< "The form's signature status: [";
		if (const_cast<AForm&>(obj).getSigned() == true)
			std::cout << "signed";
		else if (const_cast<AForm&>(obj).getSigned() == false)
			std::cout << "not signed";
		std::cout << "]" << std::endl;
	return os;
}

std::string	AForm::getName() const {
	return (_name);
}

int	AForm::getSignGrade() const {
	return (_sign_grade);
}

int	AForm::getExecGrade() const {
	return (_exec_grade);
}

bool	AForm::getSigned() {
	return (_signed);
}

void	AForm::beSigned(Bureaucrat& obj) {
	if (obj.getGrade() > _sign_grade)
		throw GradeTooLowException();
	_signed = true;
}

// void	AForm::isSigned() const {
// 	if (_signed == false)
// 		throw FormNotSignedException();
// }

void	AForm::isSigned() const {
	if (_signed == false)
		throw std::invalid_argument("The form is not signed");
}

void	AForm::isEnoughGrade(const int grade, const std::string name) const {
	if (grade > _exec_grade)
		throw std::invalid_argument("Bureaucrat [" + name + "] has not enough grade");
	std::cout << name + " executed " + getName() << std::endl;
}

void	AForm::execute(const Bureaucrat& executor) const{
	try {
		isSigned();
		isEnoughGrade(executor.getGrade(), executor.getName());
		try {
			executeAction();
		}
		catch (const std::runtime_error& e) {
			std::cerr << "Runtime error exception caught: " << e.what() << std::endl;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "The form [" << getName() << "] can't be executed: "
			<< e.what() << std::endl;
	}
}

// void	AForm::execute(const Bureaucrat& executor) const{
// 	try {
// 		isSigned();
// 		try {
// 			executeAction();
// 		}
// 		catch (const std::runtime_error& e) {
// 			std::cerr << "Runtime error exception caught: " << e.what() << std::endl;
// 		}
// 	}
// 	catch (const std::exception& e) {
// 		std::cerr << "The form [" << getName() << "] can't be executed: "
// 			<< e.what() << std::endl;
// 	}
// }

const char* AForm::GradeTooHighException::what() const throw() {
	return ("The grade is too high");
}
const char* AForm::GradeTooLowException::what() const throw() {
	return ("The grade is to low");
}

// const char* AForm::FormNotSignedException::what() const throw() {
// 	return ("The form is not signed");
// }
