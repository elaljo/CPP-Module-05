/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:34:30 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/18 12:50:32 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Default"){
    std::cout << "Default Constructor Called" << std::endl;
    this->grade = 75;
}
Bureaucrat::Bureaucrat(std::string name, int grade):name(name){
    std::cout << "Constructor Called" << std::endl;
    this->grade = grade;
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
    else if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
}
Bureaucrat::Bureaucrat(const Bureaucrat& rhs):name(rhs.name){
    std::cout << "Copy Constructor Called" << std::endl;
    this->grade = rhs.grade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &rhs)
        this->grade = rhs.grade;
    return *this;
}
Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor Called" << std::endl;
}

std::string Bureaucrat::getName() const{
    return (this->name);
}
int Bureaucrat::getGrade() const{
    return (this->grade);
}

void Bureaucrat::increment(){
    this->grade--;
    if (grade < 1)
        throw(Bureaucrat::GradeTooHighException());
}
void    Bureaucrat::decrement(){
    this->grade++;
    if (grade > 150)
        throw(Bureaucrat::GradeTooLowException());
}

void Bureaucrat::signForm(AForm& form){
    if (form.getSigned_status() == true)
        std::cout << getName() << " signed " << form.getName() << std::endl;
    else
        std::cout << getName() << " couldn't sign " << form.getName() << " because bureaucrat grade is not high enough." << std::endl;
}

void Bureaucrat::executeForm(AForm const& form){
    try{
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e){
        std::cout << "Exception Caught: " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream& cout, const Bureaucrat& obj){
    cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return cout;
}
