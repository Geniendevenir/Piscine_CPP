/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:52:59 by allan             #+#    #+#             */
/*   Updated: 2025/04/17 14:47:32 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <string>
#include <iostream>
#include <fstream>

#define ERROR 1
#define SUCCESS 0



int main(int argc, char **argv);
int count_lines(std::ifstream &sourceFile);
bool dup_and_remplace(std::string const &sourcePath, std::string const &s1, std::string const &s2);
int content_replace(std::ifstream &sourceFile, std::ofstream &destFile, std::string const &s1, std::string const &s2);

#endif