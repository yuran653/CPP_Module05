/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:37:01 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/07 16:52:47 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, const int sign_grade, const int exec_grade)
	: _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	
}

Form::Form(Form& other) : _name(other._name), _sign_grade(other._sign_grade),
	_exec_grade(other._exec_grade), _signed(other._signed) {
}

Form::~Form() {
}

Form& Form::operator=(const Form& other) {
	if (this == &other)
		return *this;
	const_cast<std::string&>(_name) = other._name;
	const_cast<int&>(_sign_grade) = other._sign_grade;
	const_cast<int&>(_exec_grade) = other._exec_grade;
	_signed = other._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form name: [" << obj.getName() << "]" << std::endl
		<< "Required sign grade: [" << obj.getSignGrade() << "]" << std::endl
		<< "Required execute grate: [" << obj.getExecGrade() << "]" << std::endl
		<< "The form's signature status: ["
		<< const_cast<Form&>(obj).getSigned() << "]" << std::endl;
	return os;
}

std::string	Form::getName() const {
	return (_name);
}

int	Form::getSignGrade() const {
	return (_sign_grade);
}

int	Form::getExecGrade() const {
	return (_exec_grade);
}

bool	Form::getSigned() {
	return (_signed);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("The grade is too high");
}
const char* Form::GradeTooLowException::what() const throw() {
	return ("The grade is to low");
}
