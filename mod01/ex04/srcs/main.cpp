/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:51:37 by allan             #+#    #+#             */
/*   Updated: 2025/04/17 13:12:25by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"


int count_lines(std::ifstream &sourceFile) {

	int nbr_of_line = 0;
	std::string line;

	while(std::getline(sourceFile, line))
		nbr_of_line++;
	if (!line.empty() && sourceFile.eof())
		nbr_of_line++;

	sourceFile.clear();
	sourceFile.seekg(0, std::ios::beg);

	return (nbr_of_line);
}

int content_replace(std::ifstream &sourceFile, std::ofstream &destFile, std::string const &s1, std::string const &s2) {
	
	int nbr_of_line = count_lines(sourceFile);

	std::string line;
	
	while(std::getline(sourceFile, line))
	{
		std::string::size_type pos = 0;
		
		while((pos < line.size())) {
			std::string result;
			std::string::size_type found = line.find(s1, pos);
			if (found == std::string::npos) {
				result = line.substr(pos);
				destFile << result;
				break;
			}
			result = line.substr(pos, found - pos);
			result += s2;
			pos = found + s1.size();
			destFile << result;
		}
		if (nbr_of_line > 1)
			destFile << std::endl;
	}
	return SUCCESS;
}

bool dup_and_remplace(std::string const &sourcePath, std::string const &s1, std::string const &s2) {
	std::ifstream sourceFile(sourcePath.c_str()); 
	if (!sourceFile) {
		std::cerr << "Error: opening source file: " << sourcePath << std::endl;
		return ERROR;
	}

	std::string destPath = sourcePath + ".replace";	
	std::cout << destPath << std::endl;

	std::ofstream destFile(destPath.c_str());
	if (!destFile) {
		std::cerr << "Error: opening dest file: " << destPath << std::endl;
		sourceFile.close();
		return ERROR;
	}
	
	if (content_replace(sourceFile, destFile, s1, s2) == ERROR) {
		destFile.close();
		sourceFile.close();
		return ERROR;
	}
	destFile.close();
	sourceFile.close();
	return SUCCESS;	
}


int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Error: 3 Parameters Needed: Filename - S1 - S2" << std::endl;
		return ERROR;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (dup_and_remplace(filename, s1, s2) == ERROR)
		return ERROR;
		
	return SUCCESS;
}
