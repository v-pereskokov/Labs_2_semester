#include "stack.h"

stack::stack(const std::size_t size)
:size_(size), data_(new int[size]), head_(0)
{}

stack::stack(const stack &copy)
:size_(copy.size_), data_(new int[copy.size_]), head_(copy.head_)
{
    for (std::size_t i = 0; i < head_; ++i)
        data_[i] = copy.data_[i];
}

void stack::add(const int data)
{
    if (head_ < size_)
        data_[head_++] = data;
    else
        throw std::out_of_range("Stack is full!");
}

void stack::del()
{
    if (head_ > 0)
        --head_;
    else
        throw std::out_of_range("Stack is empty!");
}

int stack::get() const
{
    return data_[head_ - 1];
}

stack::~stack()
{
    if (data_)
        delete [] data_;
}