/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:46 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/20 20:50:56 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():name("noname"),grade_to_sign(0),grade_to_exec(0)
{
    Signed_status = 0;
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw(AForm::GradeTooHighException());
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw(AForm::GradeTooLowException());
    std::cout << "Default Constructor Called" << std::endl;
}
AForm::AForm(std::string name, int sign_grade, int exec_grade) : name(name), grade_to_sign(sign_grade), grade_to_exec(exec_grade){
    Signed_status = 0;
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw(AForm::GradeTooHighException());
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw(AForm::GradeTooLowException());
    std::cout << "Base Constructor Called" << std::endl;
}
AForm::AForm(const AForm& rhs):name(rhs.name),grade_to_sign(rhs.grade_to_sign),grade_to_exec(rhs.grade_to_exec){
    Signed_status = rhs.Signed_status;
    std::cout << "Copy Constructor Called" << std::endl;
}
AForm& AForm::operator=(const AForm& rhs){
    std::cout << "Copy Assignment Called" << std::endl;
    if (this != &rhs)
        Signed_status = rhs.Signed_status;
    return *this;
}
AForm::~AForm(){
    std::cout << "Base Destructor Called" << std::endl;
}

std::string AForm::getName() const{
    return name;
}
bool AForm::getSigned_status() const{
    return Signed_status;
}
int AForm::getGrade_to_sign() const{
    return grade_to_sign;   
}
int AForm::getGrade_to_exec() const{
    return grade_to_exec;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() <= getGrade_to_sign())
        Signed_status = 1;
    else
        throw(AForm::GradeTooLowException());
}

std::ostream& operator<<(std::ostream& cout, const AForm& obj){
    cout << "Form name: " << obj.getName() << std::endl;
    cout << "Signed status: " << obj.getSigned_status() << std::endl;
    cout << "Grade to sign form: " << obj.getGrade_to_sign() << std::endl;
    cout << "Grade to execute form: " << obj.getGrade_to_exec() << std::endl;
    return cout;
}