/*!
*\file
*\brief ������������ ���� � ��������� ������

*������ ���� �������� � ���� �����������
������ ��������� ������ - �������
*/

#pragma once

#include <iostream>

#define EXPORT __declspec(dllexport)

__interface EXPORT InterfaceQueue
{
	void create(const std::size_t size);
	void add(const int data);
	int get() const;
	void del();
};

/*!
*\brief ����� - �������

*������ ����� ��������� ������ ��������� ������ - �������
*/

class queue : public InterfaceQueue {
public:
	/*!
	*������� �������� �������(��� ������������� ������ ���������������)
	*\param[in] size ������ �������
	*/

	void create(const std::size_t size);

	/*!
	*��������� ������� � �������
	*\param[in] data �������� ������ ��������
	*/

	void add(const int data);
	/*!
	*������� ������� �� �������
	*/

	void del();
	/*!
	*��������� ������� �������� �������
	*\return �������� ������� �������� �������
	*/

	int get() const;
	/*!
	*���������� ������. ����������� ������ �� ������� ���������.
	*/

private:
	std::size_t size_; /*!< ������ ������� */
	std::size_t begin_; /*!< ������ ������� */
	std::size_t end_; /*!< ����� ������� */
	std::size_t count_; /*!< ���������� �������� ������� */
	int *data_; /*!< ������ ��� ������� */
};

extern "C"
{
	__declspec(dllexport) InterfaceQueue *GetIQueue();
}