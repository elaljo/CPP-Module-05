/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:12:12 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/12 10:31:48 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat n1("nawfal", 1);
		std::cout << n1;
		Bureaucrat n2 = n1;
		n2.increment();
		std::cout << n2;
	}
	catch (std::exception &e){
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}