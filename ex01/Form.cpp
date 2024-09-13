/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:01:45 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/13 20:48:40 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("Default"), grade_to_sign(20), grade_to_exec(20){
	this->is_signed = false;
	std::cout << "Default Constructor called" << std::endl;
}
Form::Form(std::string name, int gts, int gte) : name(name), grade_to_sign(gts), grade_to_exec(gte){
	this->is_signed = false;
	if (gts < 1)
		throw Form::GradeTooHighException();
	if (gts > 150)
		throw Form::GradeTooLowException();
	std::cout << "Constructor called" << std::endl;
}
Form::Form(const Form &copy) : name(copy.name),grade_to_sign(copy.grade_to_sign),grade_to_exec(copy.grade_to_exec){
	is_signed = copy.is_signed;
	std::cout << "Copy constructor called" << std::endl;
}
Form& Form::operator=(const Form& copy){
	if (&copy != this){
		std::cout << "Copy assignment operator called" << std::endl;
		this->is_signed = copy.is_signed;
	}
	return *this; 
}
Form::~Form(){
	std::cout << "Destructor called" << std::endl;
}

std::string Form::getName() const{
	return this->name;
}
int Form::getSigned() const{
	return this->is_signed;
}
int	Form::getGrade_to_sign() const{
	return this->grade_to_sign;
}
int Form::getGrade_to_exec() const{
	return this->grade_to_exec;
}

std::ostream& operator<<(std::ostream& os, const Form& obj){
	os << "Name: " << obj.getName() << "\n" << "is it signed: " << obj.getSigned() << "\n" << "Grade to sign: " << obj.getGrade_to_sign() << "\n" << "Grade to execute: " << obj.getGrade_to_exec() << std::endl;
	return (os);
}

void Form::beSigned(Bureaucrat& b){
	if (getGrade_to_sign() > 150)
		throw Form::GradeTooLowException();
	if (b.getGrade() <= getGrade_to_sign())
		is_signed = true;
}
void	Form::signForm(Bureaucrat &b){
	if (getSigned() == true)
		std::cout << b.getName() << " signed " << getName() << std::endl;
	else
		std::cout << b.getName() << " couldn't sign " << getName() << " because bureaucrat kasol" << std::endl;
}