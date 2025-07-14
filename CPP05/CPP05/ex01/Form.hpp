/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:53:33 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/30 18:05:08 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
//# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat; // to avoid the circular dependencies need to add forward Declaration of the 
//class. otherwise if we add the Form.h in the B.Cpp will will dance forever

class Form
{
	private:
	const std::string name;
	bool _signed;
	const int signGrade;
	const int executeGrade;
	
	public:
	Form();
	Form(const std::string &name, int signGrade, int executeGrade);
	Form(const Form &other);
	~Form();
	Form &operator=(const Form &other);
	
	std::string getName() const;
	bool getSigned() const;
	int getSignedGrade() const;
	int getExecuteGrade() const;

	void beSigned(const Bureaucrat &bureaucrat);
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif