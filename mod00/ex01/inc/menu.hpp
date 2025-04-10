/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:52:12 by allan             #+#    #+#             */
/*   Updated: 2025/03/30 01:58:17 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MENU_HPP
# define MENU_HPP

#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include <iomanip>

#include "PhoneBook.class.hpp"


# define SUCCESS 0
# define VALID 0
# define ERROR -1
# define FOUND 1
# define NOT_FOUND 0
# define EMPTY 1

int main(void);
int menu(const std::string input, PhoneBook &phonebook);
int check_input(std::string& input, bool check_empty);
int	safe_string_to_int(int &nbr, const std::string &str);


#endif