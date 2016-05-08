/*
 * В первых трех заданиях используются первые две библиотеки
 * Кроме задания с перемножением матриц
 */

#include <iostream>
#include <thread>
#include <fstream>
#include <string>

/**
 * Сумма от 0 до N
 */

void sumOdd(int &n1, int N) {
	for (std::size_t i = 1; i <= N; i += 2)
		n1 += i;
}

void sumEven(int &n2, int N) {
	for (std::size_t i = 0; i <= N; i += 2)
		n2 += i;
}

int main() {
	int n1 = 0;
	int n2 = 0;
	std::cout << "Enter N : ";
	int N;
	std::cin >> N;
	std::thread sumodd(sumOdd, std::ref(n1), N);
	std::thread sumeven(sumEven, std::ref(n2), N);
	sumodd.detach();
	sumeven.detach();
	std::cout << "Sum = " << n1 + n2 << std::endl;
	system("pause");
	return 0;
}

/**
 * Факториал числа N
 */

void fact_1(int &N) {
	if (N <= 0) {
		N = 1;
		return;
	}
	for (int i = N - 2; i > 0; i -= 2)
		N *= i;
}

void fact_2(int &N) {
	if (N <= 0) {
		N = 1;
		return;
	}

	for (int i = N - 2; i > 0; i -= 2)
		N *= i;

}

int main() {
	std::cout << "Enter N : ";
	int N;
	std::cin >> N;
	int n1 = N;
	int n2 = N - 1;
	std::thread fact1(fact_1, std::ref(n1));
	fact1.detach();
	std::thread fact2(fact_2, std::ref(n2));
	fact2.detach();
	std::cout << "Fact(N) = " << n1 * n2 << std::endl;
	system("pause");
	return 0;
}

/**
 * Количество сочетаний(C из n по k)
 */

void fact(int &N) {
	if (N <= 0) {
		N = 1;
		return;
	}
	for (std::size_t i = N - 1; i > 0; --i)
		N *= i;
}

int main() {
	std::cout << "Enter n : ";
	int n;
	std::cin >> n;
	std::cout << "Enter k : ";
	int k;
	std::cin >> k;
	int d = n - k;
	int C;
	std::thread factN(fact, std::ref(n));
	std::thread factK(fact, std::ref(k));
	std::thread factN_K(fact, std::ref(d));
	factN.detach();
	factK.detach();
	factN_K.detach();
	C = n / k / d;
	std::cout << "C(n)k = " << C << std::endl;
	system("pause");
	return 0;
}

/**
 * Перемножение матриц
 */

const int lines_mas1 = 4;
const int columns_mas1 = 5;
const int lines_mas2 = 5;
const int columns_mas2 = 4;

void initMatrix(int **&mas, int lines, int columns) {
	mas = new int*[lines];
	for (std::size_t i = 0; i < lines; ++i)
		mas[i] = new int[columns];
}

void delMatrix(int **&mas, int lines) {
	for (std::size_t i = 0; i < lines; ++i)
		delete[] mas[i];
	delete[] mas;
}

void readMatrix(int **mas, int lines, int columns, const std::string &string)
{
	std::fstream file(string);
	if (!file.good())
	{
		file.close();
		return;
	}
	size_t i = 0;
	size_t j = 0;
	while (file >> mas[i][j])
	{
		++j;
		if (j == columns)
		{
			j = 0;
			++i;
		}
		if (i == lines)
			break;
	}
	file.close();
}

void multMatrix(int **&mas3, int **mas1, int **mas2, int lines_mas1, int columns_mas1, int columns_mas2) {
	for (std::size_t i = 0; i < lines_mas1; ++i) {
		for (std::size_t j = 0; j < columns_mas2; ++j) {
			mas3[i][j] = 0;
			for (std::size_t k = 0; k < columns_mas1; ++k) {
				mas3[i][j] += mas1[i][k] * mas2[k][j];
			}
		}
	}
}

void printMas(int **mas, int lines, int columns) {
	for (std::size_t i = 0; i < lines; ++i)
	{
		for (std::size_t j = 0; j < columns; ++j)
			std::cout << mas[i][j] << " ";
		std::cout << std::endl;
	}
}

int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	int **mas1;
	int **mas2;
	int **mas3;
	std::thread initMas1(initMatrix, std::ref(mas1), lines_mas1, columns_mas1);
	std::thread initMas2(initMatrix, std::ref(mas2), lines_mas2, columns_mas2);
	std::thread initMas3(initMatrix, std::ref(mas3), lines_mas1, columns_mas2);
	initMas1.detach();
	initMas2.detach();
	initMas3.detach();
	std::thread readMas1(readMatrix, std::ref(mas1), lines_mas1, columns_mas1, s1);
	std::thread readMas2(readMatrix, std::ref(mas2), lines_mas2, columns_mas2, s2);
	readMas1.detach();
	readMas2.detach();
	std::thread multMas1(multMatrix, std::ref(mas3), mas1, mas2, lines_mas1, columns_mas1, 0);
	std::thread multMas2(multMatrix, std::ref(mas3), mas1, mas2, lines_mas1, columns_mas1, 1);
	std::thread multMas3(multMatrix, std::ref(mas3), mas1, mas2, lines_mas1, columns_mas1, 2);
	std::thread multMas4(multMatrix, std::ref(mas3), mas1, mas2, lines_mas1, columns_mas1, 3);
	std::thread multMas5(multMatrix, std::ref(mas3), mas1, mas2, lines_mas1, columns_mas1, 4);
	multMas1.detach();
	multMas2.detach();
	multMas3.detach();
	multMas4.detach();
	multMas5.detach();
	printMas(mas3, lines_mas1, columns_mas2);
	std::cout << std::endl;
	std::thread delMas1(delMatrix, std::ref(mas1), lines_mas1);
	std::thread delMas2(delMatrix, std::ref(mas2), lines_mas2);
	std::thread delMas3(delMatrix, std::ref(mas3), lines_mas1);
	delMas1.detach();
	delMas2.detach();
	delMas3.detach();
	system("pause");
	return 0;
}