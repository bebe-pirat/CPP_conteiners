#include "s21_queue.h"

template<typename Type> 
S21Queue<Type>::S21Queue(): head_(nullptr), tail_(nullptr), size_(0) {}

template<typename Type>
S21Queue<Type>::S21Queue(const S21Queue& other): head_(other.head_), tail_(other.tail_), size_(other.size_) {}

template<typename Type>
S21Queue<Type>::S21Queue(S21Queue&& other): head_(other.head_), tail_(other.tail_), size_(other.size_) 
{
    other.head_ = nullptr;
    other.tail_ = nullptr;
    size_ = 0;
}

template<typename Type> 
S21Queue<Type>::~S21Queue() {
    while(!empty()) {
        pop();
    }
}

template<typename Type>
bool S21Queue<Type>::empty() const {
    return head_ == nullptr;
}

template<typename Type>
size_t S21Queue<Type>::size() const {
   return size_; 
}