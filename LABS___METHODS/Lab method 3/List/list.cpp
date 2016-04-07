#include "list.h"

list::list()
:head_(nullptr)
{}

list::list(const list &copy)
:head_(copy.head_)
{}

void list::add(const std::size_t index, const int data) {
    list::node *new_node = new node(data);
    if (head_ == nullptr)
        head_ = new_node;
    else {
        list::node *temp = head_;
        std::size_t i = 0;
        while (i++ < index) {
            temp->_pnext = new_node;
            temp = temp->_pnext;
        }
    }
}

void list::del(const std::size_t index) {
    list::node *temp = head_;
    if (index == 0) {
        head_ = head_->_pnext;
        delete temp;
    }
    else if (index > 0) {
        list::node *new_node = head_;
        for (std::size_t i = 1; i < index - 1; ++i)
            new_node = new_node->_pnext;
        temp = new_node->_pnext;
        new_node->_pnext = new_node->_pnext->_pnext;
        delete temp;
    }
}

int list::get(const std::size_t index) const {
    list::node *temp = head_;
    std::size_t i = 0;
    while (i++ < index)
        temp = temp->_pnext;
    return temp->_data;
}

list::~list() {
    list::node *temp = head_;
    list::node *delete_node = head_;
    while (delete_node != nullptr) {
        temp = temp->_pnext;
        delete delete_node;
        delete_node = temp;
    }
    head_ = nullptr;
}