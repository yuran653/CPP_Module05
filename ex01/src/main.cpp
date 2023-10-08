/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:30:28 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/08 12:46:50 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void trySignForm(Bureaucrat bure, Form form)
{
	try {
		bure.signForm(form);
	}
	catch (std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void onHeap(int bure_grade, int form_grade)
{
	if (form_grade > bure_grade) {
		for (int i = form_grade; bure_grade <= i;) {
			std::cout << std::endl;
			try {
				Bureaucrat* bure = new Bureaucrat("Bureaucrat", bure_grade);
				std::cout << "Created: " << *bure << std::endl;
				try {
					Form* form = new Form("WTForm", form_grade, 1);
					std::cout << *form;
					trySignForm(*bure, *form);
					delete form;
				}
				catch (std::exception& e) {
					std::cerr << "Error: unable to create Form: " << e.what() << std::endl;
				}
				delete bure;
			}
			catch (std::exception& e) {
				std::cerr << "Error: Unable to create Bureaucrat: " << e.what() << std::endl;
			}
			std::cout << std::endl;
			bure_grade++;
			form_grade--;
		}
	}
	else
		std::cerr << "Error: incorrect arguments" << std::endl;
}

void onStack(int bure_grade, int form_grade)
{
	if (form_grade > bure_grade) {
		for (int i = form_grade; bure_grade <= i;) {
			std::cout << std::endl;
			try {
				Bureaucrat bure("Bureaucrat", bure_grade);
				std::cout << "Created: " << bure << std::endl;
				try {
					Form form("WTForm", form_grade, 1);
					std::cout << form;
					trySignForm(bure, form);
				}
				catch (std::exception& e) {
					std::cerr << "Error: unable to create Form: " << e.what() << std::endl;
				}
			}
			catch (std::exception& e) {
				std::cerr << "Error: Unable to create Bureaucrat: " << e.what() << std::endl;
			}
			std::cout << std::endl;
			bure_grade++;
			form_grade--;
		}
	}
	else
		std::cerr << "Error: incorrect arguments" << std::endl;
}

int	main() {
	onHeap(-1, 4);
	onStack(148, 151);
	return 0;
}
