#include "queue.h"

queue::queue(const std::size_t size)
:size_(size), begin_(0), end_(0), count_(0), data_(new int[size_ + 1])
{}

queue::queue(const queue &copy)
:size_(copy.size_), begin_(copy.begin_), end_(copy.begin_), count_(copy.count_), data_(new int[size_ + 1]) {
    for (std::size_t i = 0; i < size_; ++i)
        data_[i] = copy.data_[i];
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

queue::~queue() {
    if (data_)
        delete [] data_;
}