#include <exception>
#include <stdexcept>

template<typename Type>

class S21Queue {
    private: 
        int capacity_;
        int lenght_;
        Type& front_;
        Type& back_;
    public: 
        // функция проверяющая пустая очередь или нет
        bool empty();
        // функция возвращающая размер очереди
        int size();
        // добавление элемента в конец
        void push();
        // удаление элемента сначала
        void pop();
        // получение первого элемента
        Type front();
        // получение последнего элемента
        Type back();
};