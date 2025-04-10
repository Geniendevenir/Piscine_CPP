/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:51:37 by allan             #+#    #+#             */
/*   Updated: 2025/04/03 19:08:02 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
//CAS AVEC UNE SEULE LIGNE A CORRIGER
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
	
	std::string line;
	while(std::getline(sourceFile, line))
	{
		size_t pos = 0;
		while((pos = line.find(s1, pos)) != std::string::npos) {
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}

		destFile << line << "\n";
	}

	destFile.close();
	sourceFile.close();
	return SUCCESS;	
}

/* int duplicate_file(std::string filename) {
}

int str_replace(std::string s1, std::string s2) {
} */

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cerr << "Error: 3 Parameters Needed: Filename - S1 - S2" << std::endl;
		return ERROR;
	}
	
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (dup_and_remplace(filename, s1, s2))
		return ERROR;
		
	return SUCCESS;
}
