#include <cctype>
#include <iostream>
#include <string>

void	printUpperCase(const std::string &word)
{
	for (std::string::const_iterator it = word.begin(); it != word.end(); ++it)
		std::cout << static_cast<char>(std::toupper(*it));
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; ++i)
		{
			std::string word(argv[i]);
			printUpperCase(word);
			std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}