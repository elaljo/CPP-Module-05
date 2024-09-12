/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:01:43 by moelalj           #+#    #+#             */
/*   Updated: 2024/09/12 11:24:42 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Form{
	private:
		const std::string name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_exec;
	public:
		Form();
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
		
};