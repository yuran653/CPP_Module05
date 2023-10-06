/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:17:35 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/06 19:32:21 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	int number = 0;

	while (number != -1)
	{	
		try {
			
			std::cout << "Input integer number for creating : ";
			std::cin >> number;
			Bureaucrat* a = new Bureaucrat("OnHeap", number);
			a->incrementGrade();
			std::cout << *a << std::endl;
			delete a;
		}
		catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
