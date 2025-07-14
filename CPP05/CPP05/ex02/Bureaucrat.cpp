/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 16:45:52 by jadyar            #+#    #+#             */
/*   Updated: 2025/06/30 18:23:43 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Student") , grade(150)
{
	
}

Bureaucrat::Bureaucrat(const std::string &n, int g) : name(n) , grade(g)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout<<"Copy Con called"<<std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	
}
std::string Bureaucrat::getName() const
{
	return (name);
}

int Bureaucrat::getGrade() const
{
	return(grade);
}

void Bureaucrat::decrementGrade() 
{
	if (grade >= 150)
		throw GradeTooLowException();
	grade ++;
}

void Bureaucrat::incrementGrade()
{
	if (grade <=1)
		throw GradeTooHighException();
	grade --;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os<<bureaucrat.getName() <<", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade needs to be below 1.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade needs to be higher than that!");	
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception &e)
	{
	std::cout << name << " couldn't sign " << form.getName() 
			  << " because " << e.what() << std::endl;
	}
}