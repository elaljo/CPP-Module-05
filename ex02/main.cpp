/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:58 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/19 15:07:37 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
    
    try{
        Bureaucrat b1("b1", 138);
        AForm* form1 = new ShrubberyCreationForm("target");
        
        form1->beSigned(b1);
        std::cout << form1->getSigned_status() << std::endl;
        b1.executeForm(*form1);
    }
    catch(std::exception &e){
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
    return 0;
}