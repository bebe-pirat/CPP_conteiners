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
    S21Set(const S21Queue& other); // Конструктор копирования
    S21Set(S21Queue&& other); // Конструктор перемещения

    ~S21Set();

    void insert(const Type& value);
    void erase(const Type& value);
    bool contains(const Type& value);
    binary_search();
};