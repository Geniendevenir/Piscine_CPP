#include <iostream>

std::string to_upper(const std::string& input)
{
	std::string result = input;
	for (long unsigned i = 0; i < result.length(); ++i) {
		result[i] = std::toupper(result[i]);
	}
	return result;
}

int main(int argc, char*argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for (int i = 1; i < argc; i++) {
		std::cout << to_upper(argv[i]);
		if (i < argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
