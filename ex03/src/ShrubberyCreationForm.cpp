/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:03:43 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/12 18:54:51 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& other) 
	: AForm(other), _target(other._target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this == &other)
		return *this;
	AForm::operator=(other);
	const_cast<std::string&>(_target) = other._target;
	return *this;
}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream outputFile(_target + "_shrubbery");
	if (outputFile.is_open() == false)
		throw std::runtime_error("Can't open file [" + _target +  "_shrubbery]");
	outputFile << "                              +------------------+" << std::endl
<< "                              |       AForm      |" << std::endl
<< "                              +------------------+" << std::endl
<< "                              | - name           |" << std::endl
<< "                              | - signed         |" << std::endl
<< "                              | - gradeToSign    |" << std::endl
<< "                              | - gradeToExecute |" << std::endl
<< "                              +--------|---------+" << std::endl
<< "                                       |" << std::endl
<< "            +--------------------------|--------------------------+" << std::endl
<< "            |                          |                          |" << std::endl
<< "+-----------|-----------+  +-----------|-----------+  +-----------|-----------+" << std::endl
<< "| ShrubberyCreationForm |  |  RobotomyRequestForm  |  | PresidentialPardonForm|" << std::endl
<< "+--------------=====----+  +-----------------------+  +-----------------------+" << std::endl
<< "|       + target        |  |       + target        |  |       + target        |" << std::endl
<< "+-----------------------+  +-----------------------+  +-----------------------+" << std::endl;
}

// ShrubberyCreationForm: Required grades: sign 145, exec 137
// Create a file <target>_shrubbery in the working directory, and writes ASCII trees
// inside it