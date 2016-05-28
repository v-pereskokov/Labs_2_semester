#include "queue.h"

void queue::create(const std::size_t size) {
	size_ = size;
	data_ = new int[size_ + 1];
	for (std::size_t i = 0; i < size_; ++i)
		data_[i] = 0;
}

void queue::add(int data) {
	if (count_ > size_)
		throw std::out_of_range("Queue is full!");
	data_[end_++] = data;
	++count_;
	if (end_ > size_)
		end_ -= size_ + 1;
}

void queue::del() {
	if (count_ < 0)
		throw std::out_of_range("Queue is empty!");
	++begin_;
	--count_;
	if (begin_ > size_)
		begin_ -= size_ + 1;
}

int queue::get() const {
	return data_[begin_];
}

InterfaceQueue *GetIQueue()
{
	return new queue();
}