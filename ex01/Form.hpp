/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:49 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/15 10:28:49 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat; //Forward declaration c++

class Form{
    private:
        const std::string name;
        bool Signed_status;
        const int grade_to_sign;
        const int grade_to_exec;
    public:
        Form();
        Form(std::string name, int sign_grade);
        Form(const Form& rhs);
        Form& operator=(const Form& rhs);
        ~Form();
        
        class GradeTooHighException : public std::exception{
            virtual const char* what() const throw(){
                return "Form: Grade Too High.";
            }
        };
        class GradeTooLowException : public std::exception{
            virtual const char* what() const throw(){
                return "Form: Grade Too Low.";
            }
        };

        std::string getName() const;
        bool getSigned_status() const;
        int getGrade_to_sign() const;
        int getGrade_to_exec() const;

        void beSigned(const Bureaucrat& bobureaucrat);
};
std::ostream& operator<<(std::ostream& cout, const Form& obj);
#endif