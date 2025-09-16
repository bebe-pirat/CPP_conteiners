#include <exception>
#include <stdexcept>

template<typename Type> 
class S21Set {
    private: 
        Type* array_;
        uint32_t capacity_ = 100;
        uint32_t size_ = 100;

        // Метод для бинарного поиска, если элемент найден, то возвращает true и индекс элемента, в противном случае false и индекс, куда надо вставить элемент 
        std::pair<bool, int> binary_search_position(const Type& value);
        void resize();
    public: 
    S21Set();
    S21Set(const S21Set& other); // Конструктор копирования
    S21Set(S21Set&& other); // Конструктор перемещения

    ~S21Set();

    void insert(const Type& value);
    void erase(const Type& value);
    bool contains(const Type& value);
};

template<typename Type> 
S21Set<Type>::S21Set() {
    array_  = new Type[capacity_];
}

template<typename Type>
S21Set<Type>::S21Set(const S21Set& other): array_(other.array_), capacity_(other.capacity_), size_(other.size_) { }

template<typename Type>
S21Set<Type>::S21Set(S21Set&& other): array_(other.array_), capacity_(other.capacity_), size_(other.size_) {
    other.array_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
};

template<typename Type> 
S21Set<Type>::~S21Set() 
{ 
    delete[] array_;
}

template<typename Type> 
std::pair<bool, int> S21Set<Type>::binary_search_position(const Type& value) {
    if (size_ == 0) {
        return {false, 0};
    }
    
    int left = 0;
    int right = size_ - 1;
    int position = 0;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (array_[middle] == value) {
            return {true, middle}; 
        } else if (array_[middle] < value) {
            left = middle + 1;
            position = left;
        } else {
            right = middle - 1;
            position = middle;
        }
    }

    return {false, position};
}

template<typename Type> 
void S21Set<Type>::resize() {
    capacity_ *= 2;
    Type* new_array = new Type[capacity_];

    for (size_t i = 0; i < size_; i++) {
        new_array[i] = array_[i];
    }

    delete[] array_;
    array_ = new_array;
}

template<typename Type> 
void S21Set<Type>::insert(const Type& value) {
    auto is_exist = binary_search_position(value);

    if (!is_exist.first) {
        if (size_ >= capacity_) resize();

        for (size_t i{size_}; i > is_exist.second; i--) {
            array_[i] = array_[i - 1];
        }

        array_[is_exist.second] = value;
        size_++;
    }
}

template<typename Type> 
void S21Set<Type>::erase(const Type& value) {
    auto is_exist = binary_search_position(value);

    if (!is_exist.first) {
        for (size_t i{is_exist.second}; i < size_; i++) {
            array_[i] = array_[i + 1];
        }
        
        size_--;
    }
}