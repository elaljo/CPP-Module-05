/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:51:26 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/26 15:35:36 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try{
        Bureaucrat b1("mohamed", 150);
        b1.decrement();
        std::cout << b1;
    }
    catch(std::exception &e){
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}