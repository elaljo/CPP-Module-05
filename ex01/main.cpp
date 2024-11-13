/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:51:26 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/13 14:42:03 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    try{
        Form f1("lma wdo", 9);
        Bureaucrat b1("b1", 10);
        b1.signForm(f1);
    }
    catch(std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}