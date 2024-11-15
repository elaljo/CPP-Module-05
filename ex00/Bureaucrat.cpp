/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:34:30 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/15 10:22:07 by moelalj          ###   ########.fr       */
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

std::ostream& operator<<(std::ostream& cout, const Bureaucrat& obj){
    cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return cout;
}
