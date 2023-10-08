/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:27 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/08 16:44:50 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_signed;

	public:
		AForm(const std::string name, const int sign_grade, const int exec_grade);
		AForm(AForm& other);
		virtual ~AForm();

		AForm& operator=(const AForm& other);
		friend std::ostream& operator<<(std::ostream& os, const AForm& obj);

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