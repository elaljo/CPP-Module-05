/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:46:06 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/12 12:02:11 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& otherBureaucrat);
		Bureaucrat& operator=(const Bureaucrat& otherBureaucrat);
		~Bureaucrat();
		
		std::string getName()const; 
		int getGrade() const;
		
		class GradeTooHighException : public std::exception{
			virtual const char* what() const throw(){
				return("Grade too high..");
			}
		};
		
		class GradeTooLowException : public std::exception{
			virtual const char* what() const throw(){
				return ("Grade too Low..");
			}
		};
		
		void	increment();
		void	decrement();

};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);