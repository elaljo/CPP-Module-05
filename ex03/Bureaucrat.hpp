/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:35:03 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/16 20:39:37 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat& rhs);
        Bureaucrat& operator=(const Bureaucrat& rhs);
        ~Bureaucrat();
        
        class GradeTooHighException : public std::exception{
            virtual const char* what() const throw(){
                return "Grade Too High..";
            }
        };
        class GradeTooLowException : public std::exception{
            virtual const char* what() const throw(){
                return "Grade Too Low..";
            }
        };
        std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();

        void signForm(AForm& form);
        void executeForm(AForm const& form);
};
std::ostream& operator<<(std::ostream& cout, const Bureaucrat& obj);

#endif