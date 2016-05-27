#include "list.h"

list::list()
:head_(nullptr), cursor_(nullptr)
{}

void list::add(int index, const int data) {
    cursor_ = head_;
    node* newElement = new node(data);
    --index;
    if (index < 0) {
        newElement->_pnext = head_;
        head_ = newElement;
        return;
    }
    while (--index >= 0)
        cursor_ = cursor_->_pnext;
    newElement->_pnext = cursor_->_pnext;
    cursor_->_pnext = newElement;
}

void list::del(int index) {
    cursor_ = head_;
    --index;
    if (index < 0) {
        head_ = head_->_pnext;
        delete cursor_;
        return;
    }
    while (--index >= 0)
        cursor_ = cursor_->_pnext;
    node *deleted = cursor_->_pnext;
    cursor_->_pnext = cursor_->_pnext->_pnext;
    delete deleted;
}

int list::get(int index) {
    cursor_ = head_;
    while (--index >= 0)
        cursor_ = cursor_->_pnext;
    return cursor_->_data;
}

list::~list() {}
