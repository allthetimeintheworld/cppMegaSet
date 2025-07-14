/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:49:05 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/30 18:09:04 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
So we will do this everytime until we understand it:
Cononical and rule of three: defaul construct, default destructor
copy assignment operator, parameterised constructor (for the values)
gotta call std::osstream &os ect
*/

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <cmath>
# include "Form.hpp"

class Bureaucrat 
{
	private:
	const std::string name;
	int grade;
		
	public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	std::string getName() const;
	int getGrade() const;
	
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &form);

	// exception classes
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif