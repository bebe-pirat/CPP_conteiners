#include <exception>
#include <stdexcept>

template<typename Type>

class S21Queue {
    private: 
        int capacity_;
        int lenght_;
        Type* front_;
        Type* back_;
    public: 
        // функция проверяющая пустая очередь или нет
        bool empty();
        // функция возвращающая размер очереди
        bool size();
        // добавление элемента в конец
        bool push();
        // удаление элемента сначала
        bool pop();
        // получение первого элемента
        bool front();
        // получение последнего элемента
        bool back();
};