/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:08:42 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/20 20:44:24 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
    this->target_name = "Default";
    std::cout << "Default Constructor Called" << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm("ShrubberyCreationForm", 145, 137){
    this->target_name = name;
    std::cout << "Derived Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs){
    target_name = rhs.target_name;
    std::cout << "Copy Constructor Called" << std::endl;
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
    std::cout << "Copy Assignment Called" << std::endl;
    if (this != &rhs)
        this->target_name = rhs.target_name;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Derived Destructor Called" << std::endl;
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