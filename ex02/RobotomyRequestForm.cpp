/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:16:48 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/18 15:39:51 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){
    target_name = "Default";
    std::cout << "Default Constructor Called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("RobotomyRequestForm", 72, 45){
    target_name = name;
    std::cout << "Constructor Called" << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs){
    target_name = rhs.target_name;
    std::cout << "Copy Constructor Called" << std::endl;
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
    std::cout << "Copy Assignment Called" << std::endl;
    if (this != &rhs)
        this->target_name = rhs.target_name;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Destructor Called" << std::endl;
}

std::string RobotomyRequestForm::get_target_name() const{
    return target_name;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const{
    if (getSigned_status() == true && executor.getGrade() < getGrade_to_exec())
    {
        std::srand(static_cast<unsigned int>(std::time(0)));
        if (std::rand() % 2 == 0)
            std::cout << get_target_name() << " has been robotomized successfully." << std::endl;
        else
            std::cout << "The robotomy failed." << std::endl;
    }
    else
        throw(RobotomyRequestForm::AFormException());
}