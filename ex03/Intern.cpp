/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:08:48 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/20 20:51:54 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern(){
    std::cout << "Default Constructor Called" << std::endl;
}
Intern::Intern(const Intern& rhs){
    std::cout << "Copy Constructor Called" << std::endl;
    *this = rhs;
}
Intern& Intern::operator=(const Intern& rhs){
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this != &rhs)
    {
        
    }
    return *this;
}
Intern::~Intern(){
    std::cout << "Intern Destructor Called" << std::endl;
}
void Intern::deleteforms(AForm** form, int i){
    int j = 0;

    while (j < 3){
        if (j != i)
            delete form[j];
        j++;
    }
}

AForm* Intern::makeForm(std::string form_name, std::string form_target){
    AForm* forms[3] = {new ShrubberyCreationForm(form_target), new RobotomyRequestForm(form_target), new PresidentialPardonForm(form_target)};
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i;
    
    for(i = 0; i < 3; i++){
        if (form_name == names[i])
        {
            std::cout << "Intern creates " << forms[i]->getName() << std::endl;
            deleteforms(forms, i);
            return forms[i];
        }
    }
    std::cout << "Intern fails to creates the form." << std::endl;
    deleteforms(forms, i);
    return (NULL);
}