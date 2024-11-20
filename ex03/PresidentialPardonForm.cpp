/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:42:36 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/20 20:50:29 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
    target_name = "Default";
    std::cout << "Default Constructor Called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string name) : AForm("PresidentialPardonForm", 25, 5){
    target_name = name;
    std::cout << "Derived Constructor Called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs){
    target_name = rhs.target_name;
    std::cout << "Copy constructor Called" << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &rhs)
        target_name = rhs.target_name;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Derived Destructor Called" << std::endl;
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