/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:01:43 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/13 17:38:04 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

class Form{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_exec;
	public:
		Form();
		Form(std::string name, int, int);
		Form(const Form &copy);
		Form& operator=(const Form& copy);
		~Form();
		
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

		std::string getName() const;
		int getSigned() const;
		int getGrade_to_sign() const;
		int getGrade_to_exec() const;

		void	beSigned(Bureaucrat& b);
		void	signForm(Bureaucrat &b);
		
};
std::ostream& operator<<(std::ostream& os, const Form& obj);