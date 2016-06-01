#include <iostream>
#include <vector>
#include <ctime>
#include "Func.h"

template<typename Type>
void print_vector(const std::vector<Type> &vector) {
	for (const auto &temp : vector)
		std::cout << temp << " ";
	std::cout << std::endl;
}

template<typename Type>
void print_vector_clock(std::vector<Type> &vector) {
	std::cout << "Исходный вектор: " << std::endl;
	print_vector(vector);
	std::cout << "\nОтсортированный вектор: " << std::endl;
	std::clock_t begin = clock();
	InsertionSort(vector.begin(), vector.end());
	std::clock_t end = clock();
	print_vector(vector);
	std::cout << "\nВремя выполнения: " << end << " - " << begin << " ms\n" << std::endl;
}

template<typename Type>
void print_vector_count(std::vector<Type> &vector) {
	std::cout << "Исходный вектор: " << std::endl;
	print_vector(vector);
	std::size_t count = InsertionSort_(vector.begin(), vector.end(), 0);
	std::cout << "\nОтсортированный вектор: " << std::endl;
	print_vector(vector);
	std::cout << "\nЧисло итераций при сортировке двух элементов: " << count << std::endl << std::endl;
}

int main() {
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(0));
	std::vector<int> vect;
	for (std::size_t i = 0; i < 10; ++i)
		vect.push_back(rand() % 10000 - 1000);
	std::vector<int> copy_vect(vect);
	std::cout << "Сортировка вставками: " << std::endl;
	print_vector_clock(vect);
	std::cout << "Merge: " << std::endl;
	std::cout << "Исходный вектор: " << std::endl;
	print_vector(copy_vect);
	std::cout << "\nОтсортированный вектор: " << std::endl;
	std::clock_t begin = clock();
	MergeSort(copy_vect.begin(), copy_vect.end());
	std::clock_t end = clock();
	print_vector(copy_vect);
	std::cout << "\nВремя выполнения: " << end << " - " << begin << " ms\n" << std::endl;
	std::cout << "Binary Search: " << std::endl;
	std::cout << "Найденный элемент: " << std::endl;
	std::clock_t c_start_s = clock();
	auto result = BinarySearch(vect.begin(), vect.end(), vect[9]);
	std::clock_t c_end_s = clock();
	result == vect.end() ? std::cout << "Такого элемента нет" : std::cout << *result;
	std::cout << std::endl;
	std::cout << "\nВремя выполнения бинарного поиска: " << c_end_s << " - " << c_start_s << " ms\n" << std::endl;
	/**
	* Профилирование сортировки вставками
	*/
	// Сортировка двух элементов
	std::vector<int> prof_2;
	for (std::size_t i = 0; i < 2; ++i)
		prof_2.push_back(rand() % 1000 - 200);
	std::cout << "Сортировка двух элементов и число итераций: " << std::endl;
	print_vector_count(prof_2);
	// Бинарный поиск двуx элементов 
	result = BinarySearch(prof_2.begin(), prof_2.end(), prof_2[1]);
	std::cout << "Бинарный поиск двух элементов: " << std::endl;
	system("pause");
	return 0;
}