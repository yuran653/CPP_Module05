/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:27 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/09 13:33:36 by jgoldste         ###   ########.fr       */
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

	protected:
		AForm(const std::string name, const int sign_grade, const int exec_grade);
		AForm(AForm& other);
		
		AForm& operator=(const AForm& other);

	public:
		virtual ~AForm();

		friend std::ostream& operator<<(std::ostream& os, const AForm& obj);

		std::string		getName() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		bool			getSigned();
		void			beSigned(Bureaucrat& obj);
		virtual void	execute(const Bureaucrat& executor) const = 0;

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