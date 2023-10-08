/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:17:35 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/08 11:45:08 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	onStack(int number, int action) {
	while (true)
	{	
		try {
			std::cout << "Input grade level to create bureaucrat on stack (Exit: [-1]): ";
			std::cin >> number;
			if (number == -1)
				break;
			Bureaucrat stack("OnHeap", number);
			std::cout << "Created: " << stack << std::endl;
			std::cout << "To leave bureaucrat alone, input [0]" << std::endl;
			std::cout << "For increment input [1]" << std::endl;
			std::cout << "For decrement input [-1]" << std::endl;
			std::cin >> action;
			try {
				if (action < -1 || action > 1)
					throw std::invalid_argument("Invalid action mode");
				if (action == 1)
					stack.incrementGrade();
				else if (action == -1)
					stack.decrementGrade();
				std::cout << "Updated: " << stack << std::endl;
			}
			catch (const std::exception& e) {
				std::cerr << "Caught an exception: " << e.what() << std::endl;
			}
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

void	onHeap(int number, int action) {
	while (true)
	{	
		try {
			std::cout << "Input grade level to create bureaucrat on heap (Exit: [-1]): ";
			std::cin >> number;
			if (number == -1)
				break;
			Bureaucrat* heap = new Bureaucrat("OnHeap", number);\
			std::cout << "Created: " << *heap << std::endl;
			std::cout << "To leave bureaucrat alone, input [0]" << std::endl;
			std::cout << "For increment input [1]" << std::endl;
			std::cout << "For decrement input [-1]" << std::endl;
			std::cin >> action;
			try {
				if (action < -1 || action > 1)
					throw std::invalid_argument("Invalid action mode");
				if (action == 1)
					heap->incrementGrade();
				else if (action == -1)
					heap->decrementGrade();
				std::cout << "Updated: " << *heap << std::endl;
				delete heap;
			}
			catch (std::exception& e) {
				std::cerr << "Caught an exception: " << e.what() << std::endl;
				delete heap;
			}
		}
		catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
}

int	main() {

	int number = 0;
	int	action = 0;

	onHeap(number, action);
	onStack(number, action);
	return 0;
}
