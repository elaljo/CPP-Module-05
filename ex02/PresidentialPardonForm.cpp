/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:42:36 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/22 14:44:58 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
    std::cout << "Default Constructor Called" << std::endl;
    target_name = "Default";
}
PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("PresidentialPardonForm", 25, 5){
    std::cout << "Constructor Called" << std::endl;
    target_name = name;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs){
    std::cout << "Copy constructor Called" << std::endl;
    target_name = rhs.target_name;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &rhs)
        target_name = rhs.target_name;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Destructor Called" << std::endl;
}

std::string PresidentialPardonForm::get_target_name() const{
    return target_name;
}
void PresidentialPardonForm::execute(Bureaucrat const& executor)const{
    if (getSigned_status() == true && executor.getGrade() < getGrade_to_exec())
        std::cout << get_target_name() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    else
        throw(PresidentialPardonForm::AFormException());
}