#pragma once
// @author Kondakov N

#include <iostream>
#include "Iterator.h"

using namespace std;


// класс узла списка

template<class T>
class Node {
public:
    T data;// поле данных узла
    Node<T>* next;// указатель на следующий узел
    Node<T>* prev;// указатель на предыдущий узел

    // конструктор класса с параметром
    Node(const T& data) {
        // присвоение переданных данных полю данных узла
        this->data = data;
        // инициализация указателя на следующий узел значением nullptr
        next = nullptr;
        // инициализация указателя на предыдущий узел значением nullptr
        prev = nullptr;
    }
};


// класс двусвязного списка
template<class T>
class LinkedList{
private:
    Node<T>* head; // указатель на голову списка
    Node<T>* tail; // указател  на хвост списка

public:
    // конструктор по умолчанию
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // деструктор
    // удаляются все узлы в списке
    ~LinkedList() {
        // пока список не опустеет
        while (head != nullptr) {
            // запоминаем текущий узел
            Node<T>* temp = head;
            // перемещаем голову на следующий узел
            head = head->next;
            // удаляем предыдущий узел
            delete temp;
        }
    }


    // вставка в голову списка
    void AddInHead(const T& data);                         
    // вставка в хвост списка
    void AddInTail(const T& data);                       
    // печать списка
    void PrintList();                                        
    // поиск узла по значению
    int SearchNode(int data);                                  
    // удаление узла по значению
    void RemoveNode(int data);
    // удаление списка
    void ClearList(); 


    // класс итератора двусвязного списка
    template<class T>
    class LinkedListIterator : public Iterator <T> {
    private:
        Node<T>* current;  // указатель на текущий узел
    public:

        // конструктор с параметром
        LinkedListIterator(Node<T>* x) {
            current = x;
        }

        // оператор доступа к данным
        T& operator*() const override {
            //возвращает данные текущего узла
            return current->data;
        }

        // оператор для перехода на следующий узел (инкремент)
        LinkedListIterator& operator++() override {
            //если текущий не равен nullptr
            if (current != nullptr) {
                //переходим к следующему узлу
                current = current->next;
            }
            //возвращаем ссылку на текущий объект
            return *this;
        }

        // оператор равенства
        bool operator==(const Iterator<T>& other) const override {
            // преобразуем указатель на other к типу LinkedListIterator
            const LinkedListIterator* otherIterator = dynamic_cast<const LinkedListIterator*>(&other);
            // возвращаем true, если преобразование успешно и текущий узел равен узлу otherIterator
            return otherIterator && current == otherIterator->current;
        }

        // оператор неравенства
        bool operator!=(const Iterator<T>& other) const override {
            // возвращаем результат отрицания оператора равенства
            return !(*this == other);
        }
    };

    // итератор начала списка
    LinkedListIterator<T> begin() const {
        // итератор,который указывает на головной узел списка
        return LinkedListIterator<T>(head);
    }
    // итератор конца списка
    LinkedListIterator<T> end() const {
        // итератор,который указывает на позицию последнего узла списка
        return LinkedListIterator<T>(tail);
    }
};

// вставка в начало списка
template<class T>
void LinkedList<T>::AddInHead(const T& data) {
    // создание нового узла
    Node<T>* newNode = new Node<T>(data);
    // если список пустой,новый узел становится головным и хвостовым
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // привязываем новый узел к текущей голове
        newNode->next = head;
        // устанавливаем ссылку на предыдущий узел для текущей головы
        head->prev = newNode;
        // новый узел становится головным
        head = newNode;
    }

}

// вставка в конец списка
template<class T>
void LinkedList<T>::AddInTail(const T& data) {
    // создание нового узла
    Node<T>* newNode = new Node<T>(data);
    // если список пустой,новый узел становится головным и хвостовым
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // привязываем новый узел к текущему хвосту
        tail->next = newNode;
        // устанавливаем ссылку на предыдущий узел
        newNode->prev = tail;
        // новый узел становится хвостовым
        tail = newNode;
    }
}

// печать списка
template<class T>
void LinkedList<T>::PrintList() {
    // установка текущего узла на голову списка
    Node<T>* current = head;
    while (current != nullptr) {
        // выводим данные текущего узла
        cout << current->data << " ";
        // переходим на следующий узел
        current = current->next;
    }
    cout << endl;
}

// поиск узла по значению (-1 если не нашли)
template<class T>
int LinkedList<T>::SearchNode(int data) {
    // установка текущего узла на голову списка
    Node<T>* current = head;
    // пока текущий не равен nullptr
    while (current != nullptr) {
        // если число в текущем узле равны заданному
        if (current->data == data) {
            // возвращаем текущий узел,если элемент найден
            return current->data;
        }
        // или переходим к следующему узлу
        current = current->next;
    }
    // если не найден возвращаем -1
    return -1;
}


// удаление узла по значению
template<class T>
void LinkedList<T>::RemoveNode(int data) {
    // установка текущего узла на голову списка
    Node<T>* current = head;
    // пока текущий не равен nullptr
    while (current != nullptr) {
        // если число в текущем узле равны заданному
        if (current->data == data) {
            // если текущий узел головной
            if (current == head) {
                // обновляем голову списка,если удаляемый элемент - головной 
                head = current->next;
            }
            // если текущии узел хвост
            if (current == tail) {
                // обновляем хвост списка, если удаляемый элемент - хвостовой 
                tail = current->prev;
            }
            // если у текущего предыдущий не равен nullptr
            if (current->prev != nullptr) {
                // обновляем ссылку на следующий узел для предыдущего узла
                current->prev->next = current->next;
            }
            // если у текущего следующий равен nullptr
            if (current->next != nullptr) {
                // обновляем ссылку на предыдущий узел для следующего узла
                current->next->prev = current->prev;
            }
            // удаляем текущий узел
            delete current;
            return;
        }
        // Переходим к следующему узлу
        current = current->next;
    }
}

// удаление всего списка
template<class T>
void LinkedList<T>::ClearList() {
    // пока список не опустеет
    while (head != nullptr) {
        // установка текущего узла на голову списка
        Node<T>* current = head;
        // перемещаем голову на следующий узел
        head = head->next;
        // удаляем предыдущий узел
        delete current;
    }
    // когда список опустел устанавливаем указатель на конец списка в нулевой указатель
    tail = nullptr;
}
