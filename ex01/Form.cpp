/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:46 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/20 17:42:40 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():name("noname"),grade_to_sign(10),grade_to_exec(20)
{
    Signed_status = 0;
    std::cout << "Default Constructor Called" << std::endl;
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw(Form::GradeTooHighException());
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw(Form::GradeTooLowException());
}
Form::Form(std::string name, int sign_grade, int sign_exec) : name(name), grade_to_sign(sign_grade), grade_to_exec(sign_exec){
    Signed_status = 0;
    std::cout << "Constructor Called" << std::endl;
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw(Form::GradeTooHighException());
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw(Form::GradeTooLowException());
}
Form::Form(const Form& rhs):name(rhs.name),grade_to_sign(rhs.grade_to_sign),grade_to_exec(rhs.grade_to_exec){
    std::cout << "Copy Constructor Called" << std::endl;
    Signed_status = rhs.Signed_status;
}
Form& Form::operator=(const Form& rhs){
    std::cout << "Copy Assignment Called" << std::endl;
    if (this != &rhs)
        Signed_status = rhs.Signed_status;
    return *this;
}
Form::~Form(){
    std::cout << "Destructor Called" << std::endl;
}

std::string Form::getName() const{
    return name;
}
bool Form::getSigned_status() const{
    return Signed_status;
}
int Form::getGrade_to_sign() const{
    return grade_to_sign;   
}
int Form::getGrade_to_exec() const{
    return grade_to_exec;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= getGrade_to_sign())
        Signed_status = 1;
    else
        throw(Form::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& cout, const Form& obj){
    cout << "Form name: " << obj.getName() << std::endl;
    cout << "Signed status: " << obj.getSigned_status() << std::endl;
    cout << "Grade to sign form: " << obj.getGrade_to_sign() << std::endl;
    cout << "Grade to execute form: " << obj.getGrade_to_exec() << std::endl;
    return cout;
}