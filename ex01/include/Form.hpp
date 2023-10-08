/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:27 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/08 14:15:01 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_signed;

	public:
		Form(const std::string name, const int sign_grade, const int exec_grade);
		Form(Form& other);
		~Form();

		Form& operator=(const Form& other);
		friend std::ostream& operator<<(std::ostream& os, const Form& obj);

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getSigned();
		void		beSigned(Bureaucrat& obj);

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