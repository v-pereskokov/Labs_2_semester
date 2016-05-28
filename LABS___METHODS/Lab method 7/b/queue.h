#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#define EXPORT __declspec(dllexport)

__interface EXPORT InterfaceQueue
{
	void create();
	void push(const int data);
	void pop();
	const int top() const;
	bool empty() const;
};

class PriorityQueue : public InterfaceQueue {
public:
	void create();

	void push(const int lhs);

	void pop();

	const int top()const;

	bool empty() const;
private:
	std::vector<int> con;
};

extern "C"
{
	__declspec(dllexport) InterfaceQueue *GetIQueue();
}