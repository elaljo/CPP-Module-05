/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:56:11 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/20 17:46:22 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern{
    public:
        Intern();
        Intern(const Intern& rhs);
        Intern& operator=(const Intern& rhs);
        ~Intern();
        
        AForm* makeForm(std::string form_name, std::string form_target);
        void deleteforms(AForm **form, int i);
};
#endif