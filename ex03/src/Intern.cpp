/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:44:44 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/13 13:49:20 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	_request[0] = "shrubbery";
	_request[1] = "robotomy";
	_request[2] = "presidental";
}

Intern::~Intern() {
}

Intern::Intern(Intern& other) {
	*this = other;
}
		
Intern& Intern::operator=(Intern& other) {
	if (this == &other)
		return *this;
	_request[0] = other._request[0];
	_request[1] = other._request[1];
	_request[2] = other._request[2];
	return *this;
}

AForm* Intern::makeForm(std::string request, std::string target) {
	AForm* form = NULL;
	for (int i = 0; i < AMOUNT; i++) {
		if (_request[i].compare(request) == 0) {
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(target);
				case 1:
					return new RobotomyRequestForm(target);
				case 2:
					return new PresidentialPardonForm(target);
			}
		}
	}
	throw std::invalid_argument("Incorrect request: [" + request + "]");
	return form;
}
