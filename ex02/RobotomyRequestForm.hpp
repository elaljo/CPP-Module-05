/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:13:42 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/18 15:36:12 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include <cstdlib> //for rand() & srand()
#include <ctime> //for time()

class RobotomyRequestForm : public AForm{
    private:
        std::string target_name;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string name);
        RobotomyRequestForm(const RobotomyRequestForm& rhs);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
        ~RobotomyRequestForm();

        std::string get_target_name() const;

        void execute(Bureaucrat const& executor)const;
        
};

#endif