/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:46:06 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/11 14:37:26 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <ostream>
#include <exception>

class Bureaucrat{
	private:
		std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& otherBureaucrat);
		Bureaucrat& operator=(const Bureaucrat& otherBureaucrat);
		~Bureaucrat();
		
		std::string getName()const; 
		int getGrade() const;
		
		void	GradeTooHighException();
		void	GradeTooLowException();
		
		void	increment();
		void	decrement();

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);