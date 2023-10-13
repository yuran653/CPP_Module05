/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:45:40 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/13 17:13:17 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void	decrementIncrementGrade(Bureaucrat** bure) {
	int	number;
	std::cout << "To decrement bureaucrat's grade input positive integer number: ";
	std::cin >> number;
	for (; number; number--)
		(*bure)->decrementGrade();
	std::cout << "Updeted bureaucrat: " << **bure << std::endl;
	std::cout << "To increment bureaucrat's grade input positive integer number: ";
	std::cin >> number;
	for (; number; number--)
		(*bure)->incrementGrade();
	std::cout << "Updeted bureaucrat: " << **bure << std::endl << std::endl;
}

void	createBureaucrat(Bureaucrat** bure) {
	std::string	name;
	int			grade;

	std::cout << "Now let's create the bureaucrat:" << std::endl
		<< "Input bureaurecrat's name (any name is accepted): ";
	std::cin >> name;
	std::cout << "Input bureaucrat's grade (integer number only): ";
	std::cin >> grade;
	*bure = new Bureaucrat(name, grade);
	std::cout << "Bureaucrat is created! " << std::endl << **bure << std::endl;
}

void createForm(Intern& intern, AForm** form) {
	std::string	name;
	std::string	target;

	std::cout << "To create the form, input form's name " << std::endl;
	std::cout << "(available names are: <shrubbery>, <robotomy>, <presidental>): ";
	std::cin >> name;
	std::cout << "To finalize the form's creation, input the target's name: ";
	std::cin >> target;
	*form = intern.makeForm(name, target);
	std::cout << "The form is created! " << std::endl << **form << std::endl << std::endl;
}

int	main() {
	Intern		intern;
	AForm*		form = NULL;
	Bureaucrat*	bure = NULL;
	bool		nbr = 1;
	while (nbr) {
		try {
			createForm(intern, &form);
			try {
				createBureaucrat(&bure);
				decrementIncrementGrade(&bure);
				std::cout << "The form will be signed and executed by: "
					<< *bure << std::endl;
				bure->signForm(*form);
				form->execute(*bure);
			}
			catch (const std::exception& e) {
				std::cerr << "Bureaucrat's error: " << e.what() << std::endl;
			}
		}
		catch (const std::invalid_argument& e) {
			std::cerr << "Form is not created: " << e.what() << std::endl;
		}
		std::cout << std::endl;
		std::cout << "For exit input [0], if you want to continue input [1]: ";
		std::cin >> nbr;
		std::cout << std::endl;
	}
	delete bure;
	delete form;
	return 0;
}
