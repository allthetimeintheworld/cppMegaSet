/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:53:29 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/02 14:18:33 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : name("DefaultForm"), _signed(false), signGrade(150),
	executeGrade(150)
{
}

Form::Form(const std::string &name, int signGrade,
	int executeGrade) : name(name), _signed(false), signGrade(signGrade),
	executeGrade(executeGrade)
{
	if (signGrade < 1)
	{
		throw GradeTooHighException();
	}
	if (signGrade > 150)
	{
		throw GradeTooLowException();
	}
	if (executeGrade < 1)
	{
		throw GradeTooHighException();
	}
	if (executeGrade > 150)
	{
		throw GradeTooLowException();
	}
}

Form::Form(const Form &other) : name(other.name), _signed(other._signed),
	signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "just constructing" << std::endl;
}


/*
* is a copy constuctor necessary... Check if this is canononical
*/


std::string Form::getName() const
{
	return (name);
}

bool Form::getSigned() const
{
	return (_signed);
}

int Form::getSignedGrade() const
{
	return (signGrade);
}

int Form::getExecuteGrade() const
{
	return (executeGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
	{
		throw GradeTooLowException();
	}
	_signed = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Too damn high!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Too damn Low!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "FORM " << form.getName() 
	<< ", signed: " << (form.getSigned() ? "yes" : "no") 
	<< ", signed grade required: " << form.getSignedGrade() << ",execute grade required: " << form.getExecuteGrade();
	return (os);
}
