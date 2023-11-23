#pragma once
// @author Kondakov N

#include <iostream>
#include "Iterator.h"

using namespace std;


// ����� ���� ������

template<class T>
class Node {
public:
    T data;// ���� ������ ����
    Node<T>* next;// ��������� �� ��������� ����
    Node<T>* prev;// ��������� �� ���������� ����

    // ����������� ������ � ����������
    Node(const T& data) {
        // ���������� ���������� ������ ���� ������ ����
        this->data = data;
        // ������������� ��������� �� ��������� ���� ��������� nullptr
        next = nullptr;
        // ������������� ��������� �� ���������� ���� ��������� nullptr
        prev = nullptr;
    }
};


// ����� ����������� ������
template<class T>
class LinkedList{
private:
    Node<T>* head; // ��������� �� ������ ������
    Node<T>* tail; // ��������  �� ����� ������

public:
    // ����������� �� ���������
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // ����������
    // ��������� ��� ���� � ������
    ~LinkedList() {
        // ���� ������ �� ��������
        while (head != nullptr) {
            // ���������� ������� ����
            Node<T>* temp = head;
            // ���������� ������ �� ��������� ����
            head = head->next;
            // ������� ���������� ����
            delete temp;
        }
    }


    // ������� � ������ ������
    void AddInHead(const T& data);                         
    // ������� � ����� ������
    void AddInTail(const T& data);                       
    // ������ ������
    void PrintList();                                        
    // ����� ���� �� ��������
    int SearchNode(int data);                                  
    // �������� ���� �� ��������
    void RemoveNode(int data);
    // �������� ������
    void ClearList(); 


    // ����� ��������� ����������� ������
    template<class T>
    class LinkedListIterator : public Iterator <T> {
    private:
        Node<T>* current;  // ��������� �� ������� ����
    public:

        // ����������� � ����������
        LinkedListIterator(Node<T>* x) {
            current = x;
        }

        // �������� ������� � ������
        T& operator*() const override {
            //���������� ������ �������� ����
            return current->data;
        }

        // �������� ��� �������� �� ��������� ���� (���������)
        LinkedListIterator& operator++() override {
            //���� ������� �� ����� nullptr
            if (current != nullptr) {
                //��������� � ���������� ����
                current = current->next;
            }
            //���������� ������ �� ������� ������
            return *this;
        }

        // �������� ���������
        bool operator==(const Iterator<T>& other) const override {
            // ����������� ��������� �� other � ���� LinkedListIterator
            const LinkedListIterator* otherIterator = dynamic_cast<const LinkedListIterator*>(&other);
            // ���������� true, ���� �������������� ������� � ������� ���� ����� ���� otherIterator
            return otherIterator && current == otherIterator->current;
        }

        // �������� �����������
        bool operator!=(const Iterator<T>& other) const override {
            // ���������� ��������� ��������� ��������� ���������
            return !(*this == other);
        }
    };

    // �������� ������ ������
    LinkedListIterator<T> begin() const {
        // ��������,������� ��������� �� �������� ���� ������
        return LinkedListIterator<T>(head);
    }
    // �������� ����� ������
    LinkedListIterator<T> end() const {
        // ��������,������� ��������� �� ������� ���������� ���� ������
        return LinkedListIterator<T>(tail);
    }
};

// ������� � ������ ������
template<class T>
void LinkedList<T>::AddInHead(const T& data) {
    // �������� ������ ����
    Node<T>* newNode = new Node<T>(data);
    // ���� ������ ������,����� ���� ���������� �������� � ���������
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // ����������� ����� ���� � ������� ������
        newNode->next = head;
        // ������������� ������ �� ���������� ���� ��� ������� ������
        head->prev = newNode;
        // ����� ���� ���������� ��������
        head = newNode;
    }

}

// ������� � ����� ������
template<class T>
void LinkedList<T>::AddInTail(const T& data) {
    // �������� ������ ����
    Node<T>* newNode = new Node<T>(data);
    // ���� ������ ������,����� ���� ���������� �������� � ���������
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        // ����������� ����� ���� � �������� ������
        tail->next = newNode;
        // ������������� ������ �� ���������� ����
        newNode->prev = tail;
        // ����� ���� ���������� ���������
        tail = newNode;
    }
}

// ������ ������
template<class T>
void LinkedList<T>::PrintList() {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    while (current != nullptr) {
        // ������� ������ �������� ����
        cout << current->data << " ";
        // ��������� �� ��������� ����
        current = current->next;
    }
    cout << endl;
}

// ����� ���� �� �������� (-1 ���� �� �����)
template<class T>
int LinkedList<T>::SearchNode(int data) {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    // ���� ������� �� ����� nullptr
    while (current != nullptr) {
        // ���� ����� � ������� ���� ����� ���������
        if (current->data == data) {
            // ���������� ������� ����,���� ������� ������
            return current->data;
        }
        // ��� ��������� � ���������� ����
        current = current->next;
    }
    // ���� �� ������ ���������� -1
    return -1;
}


// �������� ���� �� ��������
template<class T>
void LinkedList<T>::RemoveNode(int data) {
    // ��������� �������� ���� �� ������ ������
    Node<T>* current = head;
    // ���� ������� �� ����� nullptr
    while (current != nullptr) {
        // ���� ����� � ������� ���� ����� ���������
        if (current->data == data) {
            // ���� ������� ���� ��������
            if (current == head) {
                // ��������� ������ ������,���� ��������� ������� - �������� 
                head = current->next;
            }
            // ���� ������� ���� �����
            if (current == tail) {
                // ��������� ����� ������, ���� ��������� ������� - ��������� 
                tail = current->prev;
            }
            // ���� � �������� ���������� �� ����� nullptr
            if (current->prev != nullptr) {
                // ��������� ������ �� ��������� ���� ��� ����������� ����
                current->prev->next = current->next;
            }
            // ���� � �������� ��������� ����� nullptr
            if (current->next != nullptr) {
                // ��������� ������ �� ���������� ���� ��� ���������� ����
                current->next->prev = current->prev;
            }
            // ������� ������� ����
            delete current;
            return;
        }
        // ��������� � ���������� ����
        current = current->next;
    }
}

// �������� ����� ������
template<class T>
void LinkedList<T>::ClearList() {
    // ���� ������ �� ��������
    while (head != nullptr) {
        // ��������� �������� ���� �� ������ ������
        Node<T>* current = head;
        // ���������� ������ �� ��������� ����
        head = head->next;
        // ������� ���������� ����
        delete current;
    }
    // ����� ������ ������� ������������� ��������� �� ����� ������ � ������� ���������
    tail = nullptr;
}
