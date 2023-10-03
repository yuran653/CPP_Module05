/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:17:57 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/03 19:27:09 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;

		Bureaucrat();

	public:
		Bureaucrat(const std::string name, int grade);
		// Bureaucrat(Bureaucrat& other);
		~Bureaucrat();

		// Bureaucrat& operator=(const Bureaucrat& other);
		// friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& ptr);

		const std::string	getName() const;
		int					getGrade();
		// void				incrementGrade();
		// void				decrementGrade();
		
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
