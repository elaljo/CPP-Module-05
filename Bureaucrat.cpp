/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:47:04 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/11 10:06:59 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
	this->name = "Default";
	this->grade = 75;
}

Bureaucrat::Bureaucrat(std::string name, int grade){
	this->name = name;
	this->grade = grade;
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Called Destructor" << std::endl;
}