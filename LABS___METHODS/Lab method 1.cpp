#include <iostream>
#include <string>
#include <fstream>

class compareFiles
{
public:
	compareFiles(std::string &fileName1, std::string &fileName2)
		: i_(0), f1_(fileName1),
		f2_(fileName2)
	{
	}

	void search_sim(std::ostream &out = std::cout)//Находит одинаковые строки в файлах
	{
		std::string stringFirstFile, stringSecondFile, linesFirstFile, linesSecondFile;
		size_t lineFile1(0), lineFile2(0), countLine(0);
		while (!f1_.eof())
		{
			std::getline(f1_, stringFirstFile);
			lineFile1++;
			if (stringFirstFile == stringFirstFile)
				linesFirstFile += std::to_string(lineFile1) + ' ';
			while (!f2_.eof())
			{
				std::getline(f2_, stringSecondFile);
				lineFile2++;
				if (stringFirstFile == stringSecondFile)
				{
					linesSecondFile += std::to_string(lineFile2) + ' ';
					countLine++;
				}
			}
			if (countLine != 0)
			{
				out << "String : < " << stringFirstFile << " > First file : " << linesFirstFile << "lines; "
					<< " Second file : " << linesSecondFile << "lines" << std::endl;
			}
			countLine = lineFile2 = 0;
			f2_.seekg(0);
		}
		f1_.seekg(0);
	}
	
	void search_diff(std::ostream &out = std::cout)//Находит уникальные строк в двух файлах
	{
		std::string stringFirstFile, stringSecondFile;
		size_t flag(0), stringNumber(1);
		out << "____FILE 1____" << std::endl;
		while (!f1_.eof())
		{
			std::getline(f1_, stringFirstFile);
			while (!f2_.eof())
			{
				std::getline(f2_, stringSecondFile);
				if (stringFirstFile == stringSecondFile)
				{
					flag++;
					break;
				}
			}
			if (flag == 0)
				out << "String < " << stringFirstFile << "> line(s) " << stringNumber << std::endl;
			flag = 0;
			stringNumber++;
			f2_.seekg(0);
		}
		stringNumber = 1;
		f1_.seekg(0);
		out << "____FILE 2____" << std::endl;
		while (!f2_.eof())
		{
			std::getline(f2_, stringSecondFile);
			while (!f1_.eof())
			{
				std::getline(f1_, stringFirstFile);
				if (stringFirstFile == stringSecondFile)
				{
					flag++;
					break;
				}
			}
			if (flag == 0)
				out << "String < " << stringSecondFile << "> line(s) " << stringNumber << std::endl;
			flag = 0;
			stringNumber++;
			f1_.seekg(0);
		}
		f2_.seekg(0);
	}

	~compareFiles()
	{
		f1_.close();
		f2_.close();
	}
private:
	std::fstream f1_, f2_;
	size_t i_;
};

int main() {
	std::string fileName1, fileName2;
	std::cout << "Enter the file name of first document : ";
	std::cin >> fileName1;
	std::cout << "Enter the file name of second document : ";
	std::cin >> fileName2;
	compareFiles first(fileName1, fileName2);
	first.search_diff();
	return 0;
}
