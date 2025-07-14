/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:00:36 by jadyar            #+#    #+#             */
/*   Updated: 2025/07/09 12:11:37 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Form::AForm() 
{
}

Form::AForm(const std::string &name, int signGrade,
	int executeGrade) : name(name), 
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

AForm::AForm(const Form &other) : name(other.name), _signed(other._signed),
	signGrade(other.signGrade), executeGrade(other.executeGrade)
{
	std::cout << "just constructing" << std::endl;
}

std::string AForm::getName() const
{
	return (name);
}

bool AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignedGrade() const
{
	return (signGrade);
}

int AForm::getExecuteGrade() const
{
	return (executeGrade);
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw (FormNotSignedException());
	if(executor.getGrade() > executeGrade)
		throw (GradeTooLowException());
	performAction(); //check derived class implementation
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
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

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed and cannot be executed!");
}
std::ostream &operator<<(std::ostream &os, const AForm &aform)
{
	os << "FORM " << aform.getName() 
	<< ", signed: " << (aform.getSigned() ? "yes" : "no") 
	<< ", signed grade required: " << aform.getSignedGrade() << ",execute grade required: " << form.getExecuteGrade();
	return (os);
}
