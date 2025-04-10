#include "menu.hpp"

int menu(const std::string input, PhoneBook &phonebook)
{
	int result;

	if (input == "ADD") {
		Contact new_contact;
		result = new_contact.create(); 
		if (result == EMPTY)
			return SUCCESS;
		else if (result == ERROR)
			return ERROR;

		phonebook.add(new_contact);
		return SUCCESS;
	}
	else if (input == "SEARCH") {
		if (phonebook.search() == ERROR)
			return ERROR;
		return SUCCESS;
	}
	else if (input == "EXIT") {
		std::cout << "Closing PhoneBook, See ya!\n" << std::endl;
		exit(EXIT_SUCCESS);
	}
	return SUCCESS;	
}

int main(void)
{
	PhoneBook phonebook;
	system("clear");
	std::cout << "WELCOME TO THE PHONEBOOK SERVICE" << std::endl;

	while(true)
	{
		std::string input;

		std::cout << "Select an Option: \"ADD\" - \"SEARCH\" - \"EXIT\"" << std::endl;

		if (check_input(input, false) == ERROR)
			return ERROR;

		if (menu(input, phonebook) == ERROR)
			return ERROR;
	}
	return 0;
}
