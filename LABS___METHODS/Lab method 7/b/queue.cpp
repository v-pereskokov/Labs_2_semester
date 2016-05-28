#include "queue.h"

void PriorityQueue::create() {}

void PriorityQueue::push(const int lhs) {
	con.push_back(lhs);
	std::sort(con.begin(), con.end());
}

void PriorityQueue::pop() {
	con.erase(con.begin());
}

const int PriorityQueue::top() const {
	return con.front();
}

bool PriorityQueue::empty() const {
	return con.empty();
}

InterfaceQueue *GetIQueue()
{
	return new PriorityQueue();
}