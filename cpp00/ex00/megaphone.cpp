#include <iostream>
#include <string>
#include <locale>

int main(int argc, char const *argv[])

{
    int i = 1;
    
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while ( i < argc)
		{
			std::string str(argv[i]);
            size_t j = 0;
			while( j < str.length())
            {
                std::cout << (char)std::toupper(str[j]);
                j++;
            }
            i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
