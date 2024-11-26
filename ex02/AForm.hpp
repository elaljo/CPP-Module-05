/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:37:49 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/22 15:45:36 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool Signed_status;
        const int grade_to_sign;
        const int grade_to_exec;
    public:
        AForm();
        AForm(std::string name, int , int);
        AForm(const AForm& rhs);
        AForm& operator=(const AForm& rhs);
        virtual ~AForm();
        
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
        class AFormException : public std::exception{
            virtual const char* what() const throw(){
                return "Cannot execute the form.";
            }
        };

        std::string getName() const;
        bool getSigned_status() const;
        int getGrade_to_sign() const;
        int getGrade_to_exec() const;

        void beSigned(const Bureaucrat& bureaucrat);
        virtual void execute(Bureaucrat const& executor)const = 0;
};
std::ostream& operator<<(std::ostream& cout, const AForm& obj);
#endif