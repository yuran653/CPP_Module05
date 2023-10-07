/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:17:35 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/07 14:19:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	int number = 0;
	int	action = 0;

	while (true)
	{	
		try {
			
			std::cout << "Input grade level to create bureaucrat (Exit: [-1]): ";
			std::cin >> number;
			if (number == -1)
				return 0;
			Bureaucrat* a = new Bureaucrat("OnHeap", number);\
			std::cout << "Created: " << *a << std::endl;
			std::cout << "To leave bureaucrat alone, input [0]" << std::endl;
			std::cout << "For increment input [1]" << std::endl;
			std::cout << "For decrement input [-1]" << std::endl;
			std::cin >> action;
			try {
				if (action < -1 || action > 1)
					throw std::invalid_argument("Invalid action mode");
				if (action == 1)
					a->incrementGrade();
				else if (action == -1)
					a->decrementGrade();
				std::cout << "Updated: " << *a << std::endl;
				delete a;
			}
			catch (const std::exception& e) {
				std::cerr << "Caught an exception: " << e.what() << std::endl;
				delete a;
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
