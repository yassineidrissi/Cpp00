/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaidriss <yaidriss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:01:30 by yaidriss          #+#    #+#             */
/*   Updated: 2023/11/15 22:52:42 by yaidriss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
	std::cout << GREEN << "Form Default Constructor Called" << RESET << std::endl;
	this->name = "default";
	this->isSigned = false;
	this->gradeToSign = 150;
	this->gradeToExecute = 150;
}

Form::Form(Form const & src)
{
	std::cout << GREEN << "Form Copy Constructor Called" << RESET << std::endl;
	this->name = src.name;
	this->isSigned = src.isSigned;
	this->gradeToExecute = src.gradeToExecute;
	*this = src;
}

Form::Form(std::string name, int gradeTosign, int gradeToExecute)
{
	std::cout << GREEN << "Form Constructor Called" << RESET << std::endl;
	this->name = name;
	this->isSigned = false;
	this->gradeToSign = gradeTosign;
	this->gradeToExecute = gradeToExecute;
}

Form::~Form()
{
	std::cout << RED << "Form Destructor Called" << RESET << std::endl;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
	{
		std::cout << bureaucrat.getName() << RED <<" is not signed" << this->name << RESET << std::endl;
		throw Form::GradeTooLowException();
	}
	else
	{
		std::cout << bureaucrat.getName() << GREEN <<" is signed" << this->name << RESET << std::endl;
		this->isSigned = true;
	}
}

Form & Form::operator=(Form const & src)
{
	std::cout << BLUE << "Form Assignation Operator Called" << RESET << std::endl;
	this->isSigned = src.isSigned;
	return (*this);
}


bool Form::getIsSigned() const
{
	return (this->isSigned);
}

std::string Form::getName() const
{
	return (this->name);
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
	output << "Form name is :" <<  BLUE << form.getName()<< RESET << std::endl;
	return (output);
}