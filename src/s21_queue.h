#include <exception>
#include <stdexcept>

template<typename Type>
class S21Queue {
private: 
    struct Node {
        Type data;
        Node* next;
        Node(const Type& value) : data(value), next(nullptr) {}
    };
    
    Node* head_;
    Node* tail_;
    size_t size_;
    
public: 
    // Конструкторы
    S21Queue();
    S21Queue(const S21Queue& other); // Конструктор копирования
    S21Queue(S21Queue&& other); // Конструктор перемещения
    
    // Деструктор
    ~S21Queue();
    
    // Операторы
    S21Queue& operator=(const S21Queue& other); // Копирующее присваивание
    
    // Функция проверяющая пустая очередь или нет
    bool empty() const;
    
    // Функция возвращающая размер очереди
    size_t size() const;
    
    // Добавление элемента в конец
    void push(const Type& value);
    
    // Удаление элемента сначала
    void pop();
    
    // Получение первого элемента
    Type& front();
    const Type& front() const;
    
    // Получение последнего элемента
    Type& back();
    const Type& back() const;
    
    // Обмен содержимым
    void swap(S21Queue& other) noexcept;
};