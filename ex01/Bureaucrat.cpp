/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:47:04 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/13 17:36:22 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(75){
	std::cout << "Default Constructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name){
	std::cout << "Constructor Called" << std::endl;
	this->grade = grade;
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
}
Bureaucrat::Bureaucrat(const Bureaucrat& otherBureaucrat ) : name(otherBureaucrat.name){
	std::cout << "Copy constructor called" << std::endl;
	//doing shallow copy..
	this->grade = otherBureaucrat.grade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& otherBureaucrat){
	if (&otherBureaucrat != this){
		std::cout << "Copy assignment operator called" << std::endl;
		this->grade = otherBureaucrat.grade;
	}
	return *this; 
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Destructor Called" << std::endl;
}

std::string Bureaucrat::getName() const{
	return this->name;
}
int Bureaucrat::getGrade() const{
	return this->grade;
}

void	Bureaucrat::increment(){
	grade--;
	if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}
void	Bureaucrat::decrement(){
	grade++;
	if (grade > 150)
		Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return os;
}