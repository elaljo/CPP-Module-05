/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:08:42 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/22 14:40:50 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
    std::cout << "Default Constructor Called" << std::endl;
    this->target_name = "Default";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("ShrubberyCreationForm", 145, 137){
    std::cout << "Constructor Called" << std::endl;
    this->target_name = name;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs){
    std::cout << "Copy Constructor Called" << std::endl;
    target_name = rhs.target_name;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
    std::cout << "Copy Assignment Called" << std::endl;
    if (this != &rhs)
        this->target_name = rhs.target_name;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Destructor Called" << std::endl;
}

std::string ShrubberyCreationForm::get_target_name() const{
    return target_name;
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const{
    if (getSigned_status() == true && executor.getGrade() < getGrade_to_exec())
    {
        std::ofstream outFile(get_target_name() + "_shrubbery");

        if (outFile.is_open())
        {
            outFile << "    *    " << std::endl;
            outFile << "   ***    " << std::endl;
            outFile << "  *****    " << std::endl;
            outFile << " *******    " << std::endl;
            outFile << "    |    " << std::endl;
            outFile.close();
        }
        else
            std::cerr << "Error: enable to create the file." << std::endl;
    }
    else
        throw(ShrubberyCreationForm::AFormException());
}