#include <iostream>
#include <algorithm>
#include <functional>

/**
* C��������� ��������(��� ����������)
* ��������:
* ����� ������� � ��������� � ������ �����
* ��������� O(n^2)
*/

// ������� ������ ���������
template<typename Type>
void Swap(Type &lhs, Type &rhs) {
	Type temp(lhs);
	lhs = rhs;
	rhs = temp;
}

// ������� '��������������' � ������������ �������(���������)
// ������� ��������, ������ �� ��� ������ std::advance
template<typename Iterator>
Iterator Next(Iterator iterator, std::size_t step = 1) {
	return iterator + step;
}

// �������, ������� ������ �� ������ ����� new_first �������
template<typename Iterator>
void Rotate(Iterator begin, Iterator new_first, Iterator end) {
	Iterator next = new_first;
	while (begin != next) {
		Swap(*begin++, *next++);
		if (next == end) {
			next = new_first;
		}
		else if (begin == new_first) {
			new_first = next;
		}
	}
}

// �������, ������� 
template<typename Iterator, typename Type>
Iterator UpperBound(Iterator begin, Iterator end, const Type &value)
{
	Iterator it;
	auto distance = end - begin;
	while (distance > 0) {
		it = begin;
		auto step = distance / 2;
		std::advance(it, step);
		if (!(value < *it)) {
			begin = ++it;
			distance -= step + 1;
		}
		else distance = step;
	}
	return begin;
}

// ���������� ���������
template<typename Iterator>
void InsertionSort(Iterator begin, Iterator end) {
	for (auto it = begin; it != end; ++it)
		Rotate(UpperBound(begin, it, *it), it, Next(it));
}

// ���������� ��������� �� ���������
template<typename Iterator>
std::size_t InsertionSort_(Iterator begin, Iterator end, std::size_t count) {
	for (auto it = begin; it != end; ++it) {
		++count;
		Rotate(UpperBound(begin, it, *it), it, Next(it));
	}
	return count;
}

/*
* ���������� ��������(STL)
* ����� ������(���������) �� ��� ����� �� ��� ���, ���� �� ������� ������� �����(�� ������ ��������)
* ����� �������� �������, �� ���� ���� �������� ��� � ���������
* ������ ����� ������ �����, �������� ��� ������� ����� - ��� ��������� ��, ����� ��������
*/

template<typename Iterator>
void MergeSort(Iterator begin, Iterator end) {
	const auto distance = end - begin;
	if (distance < 2)
		return;
	auto middle = begin + distance / 2;
	MergeSort(begin, middle);
	MergeSort(middle, end);
	std::inplace_merge(begin, middle, end);
}

// �������� �����(����� �������� � ��������������� �������(����������)). �������� �������� �� ���� �� ��������, ��� � merge
template<typename Iterator, typename Type>
Iterator BinarySearch(Iterator begin, Iterator end, const Type& key) {
	auto result = end;
	while (begin < end) {
		auto distance = end - begin;
		const Iterator Middle = begin + distance / 2;
		if (*Middle == key) {
			return Middle;
		}
		else if (*Middle > key) {
			end = Middle;
		}
		else {
			begin = Middle + 1;
		}
	}
	return result;
}