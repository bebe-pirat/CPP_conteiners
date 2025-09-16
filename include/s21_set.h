#include <exception>
#include <stdexcept>

template<typename Type> 
class S21Set {
    private: 
        Type* array_;
        uint32_t capacity_ = 100;
        uint32_t size_ = 100;
    public: 
    S21Set();
    S21Set(const S21Set& other); // Конструктор копирования
    S21Set(S21Set&& other); // Конструктор перемещения

    ~S21Set();

    void insert(const Type& value);
    void erase(const Type& value);
    bool contains(const Type& value);
    binary_search();
};

template<typename Type> 
S21Set<Type>::S21Set() {
    array_  = new Type[capacity_];
}

template<typename Type>
S21Set<Type>::S21Set(const S21Set& other): array_(other.array_), capacity_(other.capacity_), size_(other.size_);

template<typename Type>
S21Set<Type>::S21Set(const S21Set& other): array_(other.array_), capacity_(other.capacity_), size_(other.size_) {
    other.array_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
};

template<typename Type> 
S21Set<Type>::~S21Set() 
{ 
    delete[] array_;
}