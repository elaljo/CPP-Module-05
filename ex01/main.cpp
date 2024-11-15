/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:51:26 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/15 11:02:23 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try{
        Form f1("lma wdo", 10);
        Bureaucrat b1("b1", 10);
        f1.beSigned(b1);
        b1.signForm(f1);
    }
    catch(std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}