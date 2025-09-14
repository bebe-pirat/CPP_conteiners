// #include "s21_queue.h"

// template<typename Type> 
// S21Queue<Type>::S21Queue(): head_(nullptr), tail_(nullptr), size_(0) {}

// template<typename Type>
// S21Queue<Type>::S21Queue(const S21Queue& other): head_(other.head_), tail_(other.tail_), size_(other.size_) {}

// template<typename Type>
// S21Queue<Type>::S21Queue(S21Queue&& other): head_(other.head_), tail_(other.tail_), size_(other.size_) 
// {
//     other.head_ = nullptr;
//     other.tail_ = nullptr;
//     size_ = 0;
// }

// template<typename Type> 
// S21Queue<Type>::~S21Queue() {
//     while(!empty()) {
//         pop();
//     }
// }

// template<typename Type>
// bool S21Queue<Type>::empty() const {
//     return head_ == nullptr;
// }

// template<typename Type>
// size_t S21Queue<Type>::size() const {
//    return size_; 
// }

// template<typename Type>
// void S21Queue<Type>::push(const Type& value) {
//     Node* newNode = new Node(value);
//     if (tail_ == nullptr) {
//         head_ = tail_ = newNode;
//     } else {
//         tail_->next = newNode;
//         tail_ = newNode;
//     }
//     size_++;
// }

// template<typename Type>
// void S21Queue<Type>::pop() {
//     if (empty()) {
//         throw std::out_of_range("Queue is empty");
//     }
    
//     Node* temp = head_;
//     head_ = head_->next;
    
//     if (head_ == nullptr) {
//         tail_ = nullptr;
//     }
    
//     delete temp;
//     size_--;
// }

// template<typename Type>
// Type& S21Queue<Type>::front() {
//     if (empty()) throw std::out_of_range("Query is empty");

//     return head_.data;
// }

// template<typename Type>
// Type& S21Queue<Type>::back() {
//     if (empty()) throw std::out_of_range("Query is empty");

//     return tail_.data;
// }

// template<typename Type>
// void S21Queue<Type>::swap(S21Queue& other) {
//     S21Queue temp(*this);
    
//     this->head_ = other.head_;
//     this->size_ = other.size_;
//     this->tail_ = other.tail_;

//     other.head_ = temp.head_;
//     other.size_ = temp.size_;
//     other.tail_ = temp.tail_;
// }