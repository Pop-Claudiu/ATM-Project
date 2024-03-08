

#ifndef LAB2SD_LIST_H
#define LAB2SD_LIST_H

using namespace std;

#include "Node.h"
#include <iostream>
#include "Colectie.h"

template <class T>
class List {
private:
    Node<T>* first;
    Node<T>* tail;
    Node<T>* getNode(int position) const;
public:
    List () {
        this->first=nullptr;
        this->tail = nullptr;
    }
    int size() const;
    bool is_empty() const;
    void push_back(T e);
    void push_top(T e);
    T get_at(int i) const;
    T update(int i, T e);
    void set_at(int i, T e);
    T delete_at(int i);
    int search(T e) const;
    friend class TestList;
    ~List();
    friend class Colectie;
};

template<class T>
Node<T> *List<T>::getNode(int position) const {
    if(position < 0 or position >= size())
        throw invalid_argument("Pozitie invalida");
    Node<T>* crt = first;
    int noE = 0;
    while(noE < position){
        crt = crt->next;
        noE++;
    }
    return crt;
}

template<class T>
List<T>::~List() {
    if(first != nullptr){
        Node<T>* last=first;
        while (last->next != nullptr){
            last = last->next;
            //delete last->previous;
        }
    }
}

template<class T>
int List<T>::search(T e) const {
    int c = 0;
    Node<T>* it = first;
    if(it->info == e) return 0;
    while(it->next != nullptr){
        it = it->next;
        c++;
        if(it->info == e) return c;
    }
    return -1;
}

template<class T>
T List<T>::delete_at(int i) {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    if(i == 0){
        if(size() == 1) {
            T info = first->info;
            delete first; first = nullptr;
            tail = nullptr;
            return info;
        }
        Node<T>* aux = first;
        T info = aux->info;
        first = first->next;
        delete aux; aux = nullptr;
        return info;
    }
    else if(i == size() - 1){
        Node<T>* aux = tail;
        T info = aux->info;
        tail = tail->previous;
        tail->next = nullptr;
        delete aux; aux = nullptr;
        return info;
    }
    else{
        Node<T>* crt = getNode(i);
        Node<T>* auxFirst = crt->previous;
        Node<T>* auxSecond = crt->next;
        auxFirst->next = auxSecond;
        auxSecond->previous = auxFirst;
        T info = crt->info;
        delete crt; crt = nullptr;
        return info;
    }
}

template<class T>
void List<T>::set_at(int i, T e) {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    if(i == 0) push_top(e);
    else if(i == size() - 1){
        auto* newNode = new Node<T>(e, tail->previous, tail);
        Node<T>* aux;
        aux = tail->previous;
        tail->previous = newNode;
        aux->next = newNode;
    }
    else{
        Node<T>* crt = getNode(i);
        auto* newNode = new Node<T>(e, crt->previous, crt);
        Node<T>* aux;
        aux = crt->previous;
        crt->previous = newNode;
        aux->next = newNode;
    }
}

template<class T>
void List<T>::push_top(T e) {
    Node<T>* newNode = new Node<T>(e, nullptr, first);
    first = newNode;
}

template<class T>
T List<T>::update(int i, T e) {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = getNode(i);
    T old_value = crt->info;
    crt->info = e;
    return old_value;
}

template<class T>
T List<T>::get_at(int i) const {
    if(i < 0 || i >= size())
        throw invalid_argument("pozitia nu e valida");
    Node<T>* crt = getNode(i);
    return crt->info;
}

template<class T>
void List<T>::push_back(T e) {
    Node<T>* newNode = new Node<T>(e, tail, nullptr);
    if(first == nullptr){
        first = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

template<class T>
bool List<T>::is_empty() const {
    return first == nullptr;
}

template<class T>
int List<T>::size() const {
    int contor = 0;
    Node<T>* last = first;
    while(last != nullptr)
    {
        contor++;
        last = last->next;
    }
    return contor;
}


#endif //LAB2SD_LIST_H
