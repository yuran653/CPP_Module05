/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:17:35 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/03 19:42:51 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main() {

	Bureaucrat* a = new Bureaucrat("A", 0);
	Bureaucrat b("B", 151);
	std::cout << a->getName() + " has the grade " << a->getGrade() << std::endl;
	delete a;

	return 0;
}
