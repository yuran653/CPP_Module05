/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:44:44 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/12 19:44:48 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	_request[0] = "shrubbery request";
	_request[1] = "robotomy request";
	_request[2] = "presidental request";
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
}

AForm* Intern::makeForm(std::string request, std::string target) {
	AForm* form = NULL;
	for (int i = 0; i < AMOUNT; i++) {
		if (_request[i].compare(request) == 0) {
			switch (i) {
				case 0:
					return &ShrubberyCreationForm(target);
				case 1:
					return &RobotomyRequestForm(target);
				case 2:
					return &PresidentialPardonForm(target);
			}
		}
	}
	return form;
}
