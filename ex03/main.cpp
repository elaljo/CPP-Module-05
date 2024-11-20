/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moelalj <moelalj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:51:58 by moelalj           #+#    #+#             */
/*   Updated: 2024/11/20 20:52:06 by moelalj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(){

    Intern someRandomIntern;
    AForm* rrf;
    
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    return 0;
}