//
// Created by Gabriel on 5/18/2023.
//

#ifndef LAB2SD_NODE_H
#define LAB2SD_NODE_H

template <class T>
class Node {
public:
    Node() {next = nullptr, previous = nullptr, info = 0;}
    Node(T info, Node<T>* previous, Node<T>* next) : info(info), next(next), previous(previous){}
    explicit Node(T info) : info(info){ next = nullptr, previous = nullptr;}
    T get_info(){return info;}
    //friend class List<T>;
    Node<T>* next;
    Node<T>* previous;
    T info;
};


#endif //LAB2SD_NODE_H
