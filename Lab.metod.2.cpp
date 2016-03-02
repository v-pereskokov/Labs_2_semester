#include <iostream>
#include <string>
#include <fstream>

template<typename IT>
IT findValue(IT begin1, IT end1,
	IT begin2, IT end2)
{
	if (begin2 == end2)
		return begin1;
	while (begin1 != end1)
	{
		auto it1 = begin1, it2 = begin2;
		while (*it1 == *it2)
		{
			it1++, it2++;
			if (it1 == end1)
				return end1;
			if (it2 == end2)
				return begin1;
		}
		begin1++;
	}
	return end1;
}

void search_func(std::fstream &file)
{
	std::string string;
	std::string find = "\\func ";
	size_t i(1);
	while (!file.eof())
	{
		std::getline(file, string);
		auto result = findValue(string.begin(), string.end(), find.begin(), find.end());
		if (result != string.end())
		{
			std::cout << i << ".";
			for (auto it = result + find.length(); it != string.end(); it++)
			{

				if (*(it - 1) == ')')
					break;
				std::cout << *it;
			}
			std::cout << std::endl;
			i++;
		}
	}
	file.seekg(0);
}

int main()
{
	std::string fileName;
	std::cin >> fileName;
	std::fstream file(fileName);
	search_func(file);
	return 0;
}
