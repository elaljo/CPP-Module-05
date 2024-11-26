/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:58 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/26 16:09:56 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(){
    
    try{
        Bureaucrat b1("b1", 4);
        AForm* form1 = new PresidentialPardonForm("target");
        
        form1->beSigned(b1);
        b1.executeForm(*form1);
        delete form1;
    }
    catch(std::exception &e){
        std::cout << "Execption caught: " << e.what() << std::endl;
    }
    return 0;
}