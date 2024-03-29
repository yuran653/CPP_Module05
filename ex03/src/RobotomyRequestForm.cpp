/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:04:54 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/12 18:40:41 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	const_cast<std::string&>(_target) = other._target;
	return *this;
}

void	RobotomyRequestForm::executeAction() const {
	std::cout << "[" << getName() << "] makes drilling noise" << std::endl;
	try {
		srand(time(NULL));
		if (rand() % 2)
			throw std::invalid_argument("Robotmiztion of the form's target [" + _target + "] failed");
		std::cout << "Robotmiztion of the form's target [" + _target + "] successful" << std::endl;
	}
	catch (std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
}

// RobotomyRequestForm: Required grades: sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed
