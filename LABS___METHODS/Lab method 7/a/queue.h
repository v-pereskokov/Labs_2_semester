/*!
*\file
*\brief Заголовочный файл с описанием класса

*Данный файл содержит в себе определение
класса структуры данных - очередь
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
*\brief Класс - очередь

*Данный класс описывает методы структуры данных - очередь
*/

class queue : public InterfaceQueue {
public:
	/*!
	*Функция создания объекта(ибо конструктором нельзя воспользоваться)
	*\param[in] size Размер очереди
	*/

	void create(const std::size_t size);

	/*!
	*Добавляет элемент в очередь
	*\param[in] data Значение нового элемента
	*/

	void add(const int data);
	/*!
	*Удаляет элемент из очереди
	*/

	void del();
	/*!
	*Получение первого элемента очереди
	*\return Значение первого элемента очереди
	*/

	int get() const;
	/*!
	*Деструктор класса. Освобождает память от массива элементов.
	*/

private:
	std::size_t size_; /*!< Размер очереди */
	std::size_t begin_; /*!< Начало очереди */
	std::size_t end_; /*!< Конец очереди */
	std::size_t count_; /*!< Количество объектов очереди */
	int *data_; /*!< Массив под очередь */
};

extern "C"
{
	__declspec(dllexport) InterfaceQueue *GetIQueue();
}