/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoldste <jgoldste@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:33:27 by jgoldste          #+#    #+#             */
/*   Updated: 2023/10/13 18:18:52 by jgoldste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <cstdlib>
#include <ctime>
#include <fstream>
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
		
		virtual void	executeAction() const = 0;

	public:
		virtual ~AForm();

		std::string		getName() const;
		int				getSignGrade() const;
		int				getExecGrade() const;
		bool			getSigned();
		void			beSigned(Bureaucrat& obj);
		void			isSigned() const;
		void			execute(const Bureaucrat& executor) const;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif
