/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:08 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/09 11:38:46 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat; // to avoid the circular dependencies need to add forward Declaration of the 
//class. otherwise if we add the Form.h in the B.Cpp will will dance forever

class AForm
{
	private:
	const std::string name;
	bool _signed;
	const int signGrade;
	const int executeGrade;
	
	public:
	AForm();
	AForm(const std::string &name, int signGrade, int executeGrade);
	AForm(const AForm &other);
	virtual ~AForm();
	AForm &operator=(const AForm &other);
	
	std::string getName() const;
	bool getSigned() const;
	int getSignedGrade() const;
	int getExecuteGrade() const;
	
	virtual void performAction() const = 0;

	void execute(const Bureaucrat &executor) const;

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
	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
	
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif